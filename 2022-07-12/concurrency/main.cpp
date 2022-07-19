#include <boost/thread/locks.hpp>
#include <boost/thread/shared_mutex.hpp>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

namespace lb {
class rw_lock {
 public:
  rw_lock();
  ~rw_lock();
  void r_lock();
  void r_unlock();
  void w_lock();
  void w_unlock();
};

class std_rw_lock : rw_lock {
 public:
  std_rw_lock() {}
  ~std_rw_lock() {}
  void r_lock() {
    std::unique_lock<std::mutex> lk(m_);
    cv_.wait(lk, [this] { return !w_locked_; });
    r_locked_ = true;
  }
  void r_unlock();
  void w_lock();
  void w_unlock();

 private:
  mutable boost::shared_lock<boost::shared_mutex> inner_lock_;
};

}  // namespace lb

lb::rw_lock::rw_lock() {
  std::cout << "rw_lock()" << std::endl;
}

lb::rw_lock::~rw_lock() {
  std::cout << "~rw_lock()" << std::endl;
}

void lb::rw_lock::r_lock() {}

void lb::rw_lock::r_unlock() {}

void lb::rw_lock::w_lock() {}

void lb::rw_lock::w_unlock() {}

int rand_num(int min, int max) {
  return min + rand() % (max - min + 1);
}

int main(int argc, char const* argv[]) {
  std::vector<std::thread> ts;
  lb::rw_lock rw_lock;
  std::vector<int> v;

  constexpr int NUM_THREADS = 1000;
  constexpr int NUM_WRITER = 200;
  for (int tid = 0; tid < NUM_THREADS; ++tid) {
    const bool is_reader = tid % NUM_THREADS / NUM_WRITER != 0;

    if (is_reader) {
      ts.emplace_back(
          [&](int _tid) {
            auto randms = rand_num(0, 100);
            std::this_thread::sleep_for(std::chrono::milliseconds(randms));
            rw_lock.r_lock();
            std::cout << "reader " << _tid << " lock" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(randms));
            rw_lock.r_unlock();
            std::cout << "reader " << _tid << " unlock" << std::endl;
          },
          tid);
    } else {
      ts.emplace_back(
          [&](int _tid) {
            auto randms = rand_num(0, 100);
            std::this_thread::sleep_for(std::chrono::milliseconds(randms));
            rw_lock.w_lock();
            std::cout << "writer " << _tid << " lock" << std::endl;
            v.emplace_back(_tid);
            rw_lock.w_unlock();
            std::cout << "writer " << _tid << " unlock" << std::endl;
          },
          tid);
    }
  }
  for (auto& t : ts) {
    t.join();
  }
  // print the vector
  for (auto& i : v) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  if (v.size() != NUM_WRITER) {
    std::cout << "error: v.size() is " << v.size() << " but NUM_WRITER is "
              << NUM_WRITER << std::endl;
  }
  return 0;
}
