#include <debug.h>

class Solution {
public:
  int rob(vector<int> &v) {
    if (v.size() == 1) {
      return v[0];
    }
    int d = 2;
    std::vector<int> dp(d);
    dp[0] = v[0];
    dp[1] = v[1];
    int dp_max = 0; // 从 0 到 i-2 的最大值
    for (size_t i = 2; i < v.size(); i++) {
      dp_max = max(dp_max, dp[(i - 2) % d]);
      dp[i % d] = dp_max + v[i];
    }
    return max(dp[(v.size() - 1) % d], dp[(v.size() - 2) % d]);
  }
};
int main(int argc, char const *argv[]) {
  Solution s;
  std::vector<int> v;
  v = {2, 7, 9, 3, 1};
  printf("s.rob(v) = %d\n", s.rob(v));
  v = {1, 2, 3, 1};
  printf("s.rob(v) = %d\n", s.rob(v));
  v = {4, 1, 2, 7, 5, 3, 1};
  printf("s.rob(v) = %d\n", s.rob(v));
  return 0;
}