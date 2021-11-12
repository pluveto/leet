#include <debug.h>

class Solution {
public:
  int minCostClimbingStairs(vector<int> &cost) {
    int n = cost.size();
    std::vector<int> dp(n);
    int prev, pprev;
    pprev = cost[0];
    prev = cost[1];
    for (int i = 2; i < n; i++) {
      auto cur = min(prev, pprev) + cost[i];
      pprev = prev;
      prev = cur;
    }
    return min(prev, pprev);
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  std::vector<int> v;
  // 初始，形成两个分支，一个是 1，一个是 100，分别对应坐标 0,1
  // ，这两个的起始开销忽略不计 之后，每到达一点，开销要加上这一点的值

  v = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
  cout << s.minCostClimbingStairs(v) << endl;
  v = {10, 15, 20};
  cout << s.minCostClimbingStairs(v) << endl;
  return 0;
}