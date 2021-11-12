#include <debug.h>

class Solution {
public:
  int calc(vector<int> &cache, vector<int> &cost, int cur = -1) {
    // 读缓存
    if (cache[cur] != 0) {
      return cache[cur];
    }
    int end = cost.size() - 1;
    int curcost = cost[cur], nextcost = 0;
    if (cur <= end - 2) {
      int next1c = calc(cache, cost, cur + 1);
      int next2c = calc(cache, cost, cur + 2);
      nextcost = min(next1c, next2c);
    }
    // 总开销 = 当前步骤开销 + 下一步开销
    auto total = curcost + nextcost;
    // 写缓存
    cache[cur] = total;
    return total;
  }
  // 规定：到达之后才计算开销
  int minCostClimbingStairs(vector<int> &cost) {
    // 缓存
    vector<int> cache(cost.size());
    int cur = -1;
    int next1c = INT_MAX, next2c = INT_MAX;
    next1c = calc(cache, cost, cur + 1);
    next2c = calc(cache, cost, cur + 2);
    return min(next1c, next2c);
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