#include <cmath>
#include <debug.h>

class Solution {
public:
  int integerReplacement(size_t n, int cnt = 0) {
    if (n == 1) {
      return cnt;
    }
    cnt++;
    if (n % 2 == 0) {
      n = n / 2;
      return integerReplacement(n, cnt);
    }
    return min(integerReplacement(n + 1, cnt), integerReplacement(n - 1, cnt));
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  cout << s.integerReplacement(94) << endl; // 8
  return 0;
}
