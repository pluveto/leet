#include <debug.h>

class Solution {
public:
  string longestPalindrome(string s) {
    int n = s.size();
    if (n == 0) {
      return "";
    }
    string ret = s.substr(0, 1);
    if (n == 1) {
      return ret;
    }
    int l, m, r, maxlen = 1;
    // cbbd
    for (m = 0; m < n - 1; m++) {
      int len = 0;
      l = m - 1, r = m + 1;
      int offset = 1;
      // 保存现场
      int ml = l, mr = r;
      
      if (l + 1 == r - 1 && s[l + 1] == s[r]) {
        r++;
        len = 2;
      branch1:
        while (l >= 0 && r <= n - 1) {
          if (s[l] != s[r]) {
            break;
          }
          l--;
          r++;
          len += 2;
        }
        if (len > maxlen) {
          maxlen = len;
          ret = s.substr(l + 1, len);
          cout << ret << endl;
        }
      }
    branch2:
      // 恢复现场
      l = ml;
      r = mr;
      len = 1;
      while (l >= 0 && r <= n - 1) {
        if (s[l] != s[r]) {
          break;
        }
        l--;
        r++;
        len += 2;
      }
      if (len > maxlen) {
        maxlen = len;
        ret = s.substr(l + 1, len);
        cout << ret << endl;
      }
    }
    return ret;
  }
};
int main(int argc, char const *argv[]) {
  Solution s;
  cout << s.longestPalindrome("ccc") << endl;
  return 0;
}