#include <debug.h>

class Solution {
public:
  int find_k(std::vector<int> &v, std::vector<int> &dp, int i) {
    int max_vk = -1;
    int find_k = -1;
    for (int k = 0; k < i; k++) {
      if (v[k] < v[i] && dp[k] > max_vk) {
        max_vk = dp[k];
        find_k = k;
      }
    }
    return find_k;
  }
  int lengthOfLIS(vector<int> &v) {
    auto n = v.size();
    // dp[i] 表示以 v[i] 结尾的 v[0:i] 的 LIS
    std::vector<int> dp(n);
    dp[0] = 1;
    auto llis = 1;
    for (int i = 1; i < n; i++) {
      auto k = find_k(v, dp, i);
      if (k == -1) {
        dp[i] = 1;
      } else {
        dp[i] = dp[k] + 1;
      }
      printf("dp = ");
      print_vec(dp);
      llis = max(dp[i], llis);
    }
    return llis;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  std::vector<int> v;
  //    0  1  2  3  4  5  6    7
  v = {10, 9, 2, 5, 3, 7, 101, 18}; // 4
  //   1   1  1  2  2  3  4
  cout << s.lengthOfLIS(v) << endl;

  //    1  1
  v = {0, 1, 0, 3, 2, 3}; // 4
  // v = {34, 82, 90, 69, 4,  30, 9, 69, 2, 68, 4, 36, 20,
  //  8,  4,  63, 14, 66, 6,  6, 60, 8, 91, 8, 89, 0};
  cout << s.lengthOfLIS(v) << endl;
  return 0;
}