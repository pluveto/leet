#include <iostream>

namespace lb_ds {

// header
template <typename T>
struct optional {
  bool has_value;
  union {
    T value;
    nullptr_t null;
  };

  optional() : has_value(false) {}
  optional(const T& value) : has_value(true), value(value) {}
  optional(T&& value) : has_value(true), value(std::move(value)) {}

  T operator*() const {
    if (!has_value) {
      throw std::runtime_error("optional has no value");
    }
    return value;
  }

  T get() const {
    if (!has_value) {
      throw std::runtime_error("optional has no value");
    }
    return value;
  }
};

template <typename K, typename V>
class cache_map {
 public:
  virtual bool set(K key, V value) = 0;
  virtual optional<V> get(K key) const = 0;
};

template <typename K, typename V>
class lru_cache : public cache_map<K, V> {
 private:
  int capicity_;
  int len_;

 public:
  lru_cache(int capicity) ;
  const int& capicity()   { return capicity_;}
  bool set(K key, V value) override;
  optional<V> get(K key) const override;
};

// source

using namespace std;

template <typename K, typename V>
lru_cache<K, V>::lru_cache(int capicity): capicity_(capicity) {
  cout << "lru_cache::lru_cache" << endl;
}

template <typename K, typename V>
bool lru_cache<K, V>::set(K key, V value) {
  cout << "lru_cache::set"
       << " key: " << key
       << " value: " << value
       << endl;
  return false;
}

template <typename K, typename V>
optional<V> lru_cache<K, V>::get(K key) const {  
  cout << "lru_cache::get" << " key: " << key << endl;
  return optional<V>();
}


}  // namespace lb_ds

int main() {
  using namespace std;

  lb_ds::lru_cache<int, int> cache(4);

  cache.set(1, 1);
  cache.set(2, 2);
  cache.set(3, 3);
  cache.set(4, 4);
  cache.set(5, 5);
  cache.set(1, 1);
  cache.set(1, 1);
  cache.set(2, 2);

  for (int i = 1; i <= 5; ++i) {
    auto ret = cache.get(i);
    cout << "get " << i << ": ";
    if (ret.has_value) {
      cout << ret.value << endl;
    } else {
      cout << "not found" << endl;
    }
  }

  return 0;
}