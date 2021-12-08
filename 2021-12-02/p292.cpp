#include <debug.h>

class Solution {
public:
  bool canWinNim(int n) {
    if (n <= 3) {
      return true;
    }
    vector<int> dp(n + 1);
    for (int i = 1; i <= 3; i++)
    {
        printf("i = %d\n", i);
        printf("n = %d\n", n);
        dp[i] = 1;
    }
    
    for (int i = 4; i <= n; i++) {
      dp[i] = !dp[i - 1] || !dp[i - 2] || !dp[i - 3];      
      printf("dp[%d] = %d\n", i, dp[i]);
    }
    return dp[n];
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  cout << s.canWinNim(100) << endl;
  return 0;
}