#include <debug.h>

class MyStack {
private:
  queue<int> _q;
  queue<int> _qtmp;
  int _size = 0;

public:
  MyStack() {}

  void push(int x) {
    while (!_q.empty()) {
      auto front = _q.front();
      _q.pop();
      printf("tmp push %d\n", front);
      _qtmp.push(front);
    }
    _q.push(x);
    _size++;
    while (!_qtmp.empty()) {
      auto front = _qtmp.front();
      _qtmp.pop();
      printf("recover %d\n", front);
      _q.push(front);
    }
  }

  int pop() {
    if (_size == 0) {
      return -1;
    }
    auto front = _q.front();
    _q.pop();
    _size--;
    return front;
  }

  int top() {
    if (_size == 0) {
      return -1;
    }
    auto front = _q.front();
    return front;
  }

  bool empty() { return _size == 0; }
};
/*
top rear         top tmp rear
1
insert 2
                 1
2                1
2 1
pop 2
2                1
                 1
1
*/

int main(int argc, char const *argv[]) {
  MyStack s;
  s.push(1);
  s.push(2);
  while (!s.empty()) {
    auto p = s.pop();
    cout << p << endl;
  }
  return 0;
}