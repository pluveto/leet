#include <debug.h>

class Iterator {
  struct Data;
  Data *data;

public:
  Iterator(const vector<int> &nums);
  Iterator(const Iterator &iter);
  // Returns the next element in the iteration.
  int next();
  // Returns true if the iteration has more elements.
  bool hasNext() const;
};

class PeekingIterator {
private:
  int _p = 0;
  int _limit;
  const vector<int> *_nums;

public:
  PeekingIterator(const vector<int> &nums) {
    // Initialize any member here.
    // **DO NOT** save a copy of nums and manipulate it directly.
    // You should only use the Iterator interface methods.
    _nums = new vector<int>(nums);
    _limit = nums.size() - 1;
  }
  PeekingIterator(const PeekingIterator &iter) {}

  // Returns the next element in the iteration without advancing the iterator.
  int peek() {
    if (!(0 <= _p && _p <= _limit)) {
      return -1;
    }
    return (*_nums)[_p];
  }

  // hasNext() and next() should behave the same as in the Iterator interface.
  // Override them if needed.
  int next() {
    int r = peek();
    _p++;
    if (_p > _limit + 1)
      _p = _limit + 1;
    return r;
  }

  bool hasNext() const { return _p <= _limit; }
};

int main(int argc, char const *argv[]) {
  std::vector<int> vec = {1, 2, 3, 4};
  PeekingIterator *peekingIterator = new PeekingIterator(vec); // [1,2,3]
  cout << peekingIterator->hasNext() << endl;
  cout << peekingIterator->peek() << endl;
  cout << peekingIterator->peek() << endl;
  cout << peekingIterator->next() << endl;
  cout << peekingIterator->next() << endl;
  cout << peekingIterator->peek() << endl;
  cout << peekingIterator->peek() << endl;
  cout << peekingIterator->next() << endl;
  cout << peekingIterator->hasNext() << endl;
  cout << peekingIterator->peek() << endl;
  cout << peekingIterator->hasNext() << endl;
  cout << peekingIterator->next() << endl;
  cout << peekingIterator->hasNext() << endl;
  return 0;
}