#include <debug.h>

class Solution {
public:
  // 4,       {1,4,4}
  int minSubArrayLen(int target, vector<int> &v) {
    int n = v.size();
    std::vector<int> dp(n, 0);
    int minlen = 0x3f3f3f3f;
    for (int i = 0; i < n; i++) {
      dp[i] = v[i];
      if (dp[i] == target) {
        return 1;
      }
      for (int j = i + 1; j < n; j++) {
        dp[j] = dp[j - 1] + v[j];
        auto len = j - i + 1;
        if (dp[j] >= target && len < minlen) {
          minlen = len;
        }
      }
    }
    if (minlen == 0x3f3f3f3f) {
      return 0;
    }
    return minlen;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;

  return 0;
}