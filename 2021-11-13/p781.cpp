#include <debug.h>

class Solution {
public:
  int findLength(std::vector<int> &a, std::vector<int> &b) {
    auto n = a.size(), m = b.size();
    auto d = a.size() - 1;
    int maxval = 0;
    vector<vector<int>> dp(d,
                           vector<int>(m + 1, 0)); // 注意 dp 数组的大小不是 nxm
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (a[i - 1] == b[j - 1]) { // 注意下标
          dp[i % d][j] = dp[(i - 1) % d][j - 1] + 1;
        } else {
          dp[i % d][j] = 0;
        }
        maxval = max(maxval, dp[i % d][j]);
        print_vec_2d(dp);
      }
    }
    return maxval;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  std::vector<int> a, b;
  //   a = {1, 2, 3, 2, 1};
  //   b = {3, 2, 1, 4, 7};
  a = {0, 1, 1, 1, 1};
  b = {1, 0, 1, 0, 1};
  cout << s.findLength(a, b) << endl;
  return 0;
}