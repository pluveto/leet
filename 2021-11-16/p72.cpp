#include <debug.h>

inline int min3(int a, int b, int c) {
  return a < b ? (c < a ? c : a) : (b > c ? c : b);
}

class Solution {
public:
  int minDistance(string w1, string w2) {
    int n = w1.size();
    int m = w2.size();
    vector<int> dp(m + 1, 0);
    // -- 初始化基本情况
    // +-------> y
    // |
    // x
    //
    // 第一列的各行
    for (int i = 1; i <= (n % d); i++) {
      dp[i % d][0] = i;
    }
    // 第一行的各列
    for (int j = 1; j <= m; j++) {
      dp[0][j] = j;
    }
    // -- 开始 DP
    for (int i = 1; i <= n; i++) { // 各行
      dp[i % d][0] = i;
      for (int j = 1; j <= m; j++) {      // 各列
        auto c1 = dp[(i - 1) % d][j] + 1; // 上
        auto cc2 = w1[i - 1] == w2[j - 1] ? 0 : 1;
        auto c2 = dp[(i - 1) % 2][j - 1] + cc2; // 左上
        auto c3 = dp[i % d][j - 1] + 1;
        dp[i % d][j] = min3(c1, c2, c3);
        // print_vec_2d(dp);
      }
    }

    // print_vec_2d(dp);

    return dp[n % 2][m];
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