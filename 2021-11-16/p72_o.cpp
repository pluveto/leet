#include <debug.h>

inline int min3(int a, int b, int c) {
  return a < b ? (c < a ? c : a) : (b > c ? c : b);
}

class Solution {
public:
  int minDistance(string w1, string w2) {
    int n = w1.size();
    int m = w2.size();
    if (n == 0)
      return m;
    if (m == 0)
      return n;
    std::vector<int> dp(m + 1);
    for (int c = 0; c < m + 1; c++) {
      dp[c] = 1;
    }
    for (int r = 1; r < n + 1; r++) {
      int pre = r;
      for (int c = 1; c < m + 1; c++) {
        int cur = min(dp[c], pre) + 1;
        if (w1[r - 1] == w2[c - 1]) {
          cur = min(cur, dp[c - 1]);
        } else {
          cur = min(cur, dp[c - 1] + 1);
        }
        dp[c - 1] = pre;
        pre = cur;
        if (c == m)
          dp[c] = cur;
      }
    }
    return dp[m];
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  //   string word1 = "horse", word2 = "ros";
  string word1 = "intention";
  string word2 = "execution";
  // string word1 = "abbf", word2 = "abc";
  cout << s.minDistance(word1, word2) << endl;
  return 0;
}