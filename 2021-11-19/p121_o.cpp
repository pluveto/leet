#include <debug.h>

class Solution {
public:
  int maxProfit(vector<int> &v) {
    int maxval = 0, n = v.size();
    if (n <= 1) {
      return 0;
    }
    int ibuy = 0, isell = 1;

    printf("ibuy = %d\n", ibuy);
    printf("isell = %d\n", isell);
    for (int i = 1; i < n; i++) {
      // 先扩张 sell 区间
      printf("v[i] = %d\n", v[i]);
      printf("v[isell] = %d\n", v[isell]);
      if (v[i] > v[isell]) {
        isell = i;
      }
      // 再扩张 buy
      if (v[i] < v[ibuy] && i <= isell) {
        ibuy = i;
      }
      printf("ibuy = %d\n", ibuy);
      printf("isell = %d\n", isell);
    }
    return max(0, v[isell] - v[ibuy]);
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  // std::vector<int> v = {7, 6, 4, 3, 1};
  // std::vector<int> v = {7, 1, 5, 3, 6, 4};
  std::vector<int> v = {2, 1, 2, 1, 0, 1, 2};
  printf("s.maxProfit(v) = %d\n", s.maxProfit(v));
  return 0;
}