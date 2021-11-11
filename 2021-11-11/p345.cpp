#include <debug.h>

class Solution {
public:
  bool isVowel(char c) {
    const char *const v = "aeiouAEIOU";
    for (int i = 0; i < 10; i++) {
      if (v[i] == c) {
        return true;
      }
    }
    return false;
  }
  string reverseVowels(string s) {
    int l = 0, r = s.size();
    while (l < r) {
      while (l < r && !isVowel(s[l])) {
        l++;
      }
      while (l < r && !isVowel(s[r])) {
        r--;
      }
      char tmp = s[l];
      s[l] = s[r];
      s[r] = tmp;
      l++;
      r--;
    }
    return s;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  string str = "Hello";
  cout << s.reverseVowels(str) << endl;
  return 0;
}