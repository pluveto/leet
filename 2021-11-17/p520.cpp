#include <debug.h>

class Solution {
public:
  bool detectCapitalUse(string word) {
    int n = word.size();
    if (n <= 1)
      return true;

    bool prevUpper = 'A' <= word[0] && word[0] <= 'Z';
    bool allUpper = false; //是否是全大写模式
    for (int i = 1; i < n; i++) {
      bool isUpper = 'A' <= word[i] && word[i] <= 'Z';
      if (isUpper)
        if (prevUpper)
          allUpper = true;
        else
          return false;
      else if (allUpper) //如果全大写模式出现了小写字母，则返回
        return false;
      prevUpper = isUpper;
    }
    return true;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  cout << s.detectCapitalUse("USA") << endl;      // 1
  cout << s.detectCapitalUse("leetcode") << endl; // 1
  cout << s.detectCapitalUse("Google") << endl;   // 1
  cout << s.detectCapitalUse("FlaG") << endl;     // 0
  cout << s.detectCapitalUse("AAa") << endl;      // 0
  return 0;
}