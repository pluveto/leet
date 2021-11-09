#include <debug.h>
#include <queue>
class Solution {};

int main(int argc, char const *argv[]) {
  Solution s;
  priority_queue<int, vector<int>, greater<int>> asc_q;
  int src[] = {3, 5, 8, 1, 10, 2, 9, 15, 13, 16};
  int limit = 5;
  for (auto num : src) {
    if (asc_q.size() != 5) {
      asc_q.push(num);
      continue;
    } else {
      auto min = asc_q.top();
      if (num > min) {
        cout << "pop" << asc_q.top() << endl;
        // replace
        asc_q.pop();
        asc_q.push(num);
      }
    }
  }
  while (!asc_q.empty()) {
    cout << asc_q.top() << ", ";
    asc_q.pop();
  }
  cout << endl;
  return 0;
}