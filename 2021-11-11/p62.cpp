#include <debug.h>

class Solution {
public:
  int64_t combination(int64_t n, int64_t k) {
    int64_t numerator = 1;
    int64_t denominator = 1;
    for (int64_t i = 0; i < k; i++) {
      numerator *= n - i;
      denominator *= i + 1;
    }
    return numerator / denominator;
  }
  // m 行 n 列, m > n
  // 需要走 m + n - 2 次，其中纵向最多 n - 1 次
  int64_t uniquePaths(int64_t m, int64_t n) {
    if (m < n)
      return uniquePaths(n, m);
    auto path = m + n - 2;
    auto turn = n - 1;
    return combination(path, turn);
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  cout << s.uniquePaths(10, 10) << endl << endl;
  return 0;
}