#include <debug.h>

class Solution {
public:
  bool canWinNim(int n) { return n % 4 != 0; }
};

int main(int argc, char const *argv[]) {
  Solution s;
  cout << s.canWinNim(100) << endl;
  return 0;
}