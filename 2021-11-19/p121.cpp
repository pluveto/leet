#include <debug.h>

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int maxDelta = 0, n = prices.size();
    for (int ibudy = 0; ibudy < n - 1; ibudy++) {
      for (int isell = ibudy + 1; isell < n; isell++) {
        auto curDelta = prices[isell] - prices[ibudy];
        if (curDelta > maxDelta) {
          maxDelta = curDelta;
        }
      }
    }
    return maxDelta;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  std::vector<int> v = {7, 1, 5, 3, 6, 4};
  printf("s.maxProfit(v) = %d\n", s.maxProfit(v));
  return 0;
}