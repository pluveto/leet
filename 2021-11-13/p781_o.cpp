#include <debug.h>

class Solution {
public:
  int findLength(std::vector<int> &a, std::vector<int> &b) {
    int n = a.size(), m = b.size(), maxval = 0;
    vector<int> dp(m + 1);
    for (int i = 1; i <= n; i++) {
      for (int j = m; j > 0; j--) {
        if (a[i - 1] == b[j - 1]) { // 注意下标
          dp[j] = dp[j - 1] + 1;
        }else{
          dp[j] = 0; // 这句不可少
        }
        maxval = max(maxval, dp[j]);
        print_vec(dp);
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
  a = {1, 0, 0, 0, 1};
  b = {1, 0, 0, 1, 1};

  cout << s.findLength(a, b) << endl;
  return 0;
}