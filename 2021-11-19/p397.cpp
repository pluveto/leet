#include <cmath>
#include <debug.h>

class Solution {
public:
  int integerReplacement(int n) {
    int cnt = 0;
    while (n != 1) {
      cnt++;
      if (n % 2) {
        if (n - 1 % 2 == 0) {
          n--;
        } else {
          if (n == 3) {
            cnt += 1;
            return cnt;
          }
          n++;
        }
        cout << n << endl;
        continue;
      }
      n /= 2;
      cout << n << endl;
    }
    return cnt;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  cout << s.integerReplacement(94) << endl; // 8
  return 0;
}
