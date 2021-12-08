#include <debug.h>

class MyQueue {
private:
  int _size = 0;
  stack<int> _s;
  stack<int> _stmp;
  /**
     s                  tmp
  bottom top        bottom top
  push 1
  1
  push 2
  1
                  1
  2               1
  2 1

   */
public:
  MyQueue() {}

  void push(int x) {
    // move s to tmp
    while (!_s.empty()) {
      auto top = _s.top();
      _s.pop();
      _stmp.push(top);
    }
    // push x to s
    _s.push(x);
    _size++;
    while (!_stmp.empty()) {
      auto top = _stmp.top();
      _stmp.pop();
      _s.push(top);
    }
  }

  int pop() {
      if(_size == 0){
          return -1;
      }
      auto top = _s.top();
      _s.pop();
      _size--;
      return top;
  }

  int peek() {
       if(_size == 0){
          return -1;
      }
      auto top = _s.top();
      return top;
  }

  bool empty() {
      return _size == 0;
  }
};

int main(int argc, char const *argv[]) {
  MyQueue q;
  q.push(1);
  q.push(2);
  while (!q.empty()) {
    cout << q.pop() << endl;
  }

  return 0;
}