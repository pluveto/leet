#include <debug.h>

class Solution {
public:
  int numDistinct(string s, string t) {
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    bool first = true;

    for (int r = 0; r < m; r++) {
      set<char> s_wanting; // 表示 t 代表串中出现，而 s 代表串中未出现的
      set<char> s_history;
      int M = 0;
      for (int c = r; c < n; c++) {
        auto dp_lt = r > 0 ? dp[r - 1][c - 1] : 0; // 左上
        auto dp_l = c > 0 ? dp[r][c - 1] : 0;      // 左
        printf("t[r] = %c\n", t[r]);
        printf("s[c] = %c\n", s[c]);
        // 关注 t 的当前字符，如果曾经出现过
        if (s_history.end() != s_history.find(t[r])) {
          if (t[r] == s[c]) {
            dp[r][c] = dp_lt + dp_l;
          } else {
            dp[r][c] = dp_lt;
          }
          print_vec_2d(dp);
          continue;
        }
        // 如果没有出现过，并且也不是当前字符，则归零
        else {
          if (t[r] != s[c]) {
            dp[r][c] = 0;
            print_vec_2d(dp);
            continue;
          }
          // 没有出现过这个字符，但当前字符恰好就是
          if (first) {
            first = false;
            dp[r][c] = dp_lt + 1;
          } else {
            dp[r][c] =dp_lt;
          }
        }
        s_history.insert(s[c]);
        print_vec_2d(dp);
      }
    }
    return dp[m - 1][n - 1];
  }
};

int main(int argc, char const *argv[]) {
  Solution S;
  //   string s = "rabbbith", t = "rabbit"; // 3
  // string s = "babgbag", t = "bag"; // 5
  string s = "aabb", t = "ab"; // 4

  cout << S.numDistinct(s, t) << endl;
  return 0;
}