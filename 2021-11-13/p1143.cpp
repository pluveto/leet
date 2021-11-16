#include <debug.h>

class Solution {
public:
  int longestCommonSubsequence(string a, string b) {
    auto n = a.size(), m = b.size();
    auto d = 2;
    vector<vector<int>> dp(d,
                           vector<int>(m + 1, 0)); // 注意 dp 数组的大小不是 nxm
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (a[i - 1] == b[j - 1]) { // 注意下标
          dp[i % d][j] = dp[(i - 1) % d][j - 1] + 1;
        } else {
          dp[i % d][j] = max(dp[(i - 1) % d][j], dp[i % d][j - 1]);
        }
      }
    }
    return dp[n % d][m];
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  string s1, s2;
  int ret;
  s1 = "abcde";
  s2 = "ace";
  //   s1 = "bl";
  //   s2 = "yby";
  //   s1 = "abc";
  //   s2 = "def";
  ret = s.longestCommonSubsequence(s1, s2);
  cout << ret << endl;
  return 0;
}