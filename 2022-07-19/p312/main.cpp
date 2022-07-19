#include "../../inc/util.h"
class Solution {
  using cache_t = std::vector<vector<int>>;

 public:
  void range_best(cache_t& cache, const std::vector<int>& nums, int i, int j) {
    int max = 0;
    for (int k = i + 1; k < j; ++k) {
      auto left = cache[i][k];
      auto right = cache[k][j];

      auto a = left + nums[i] * nums[k] * nums[j] + right;
      if (a > max) {
        max = a;
      }
      cache[i][j] = max;
    }
  }
  int maxCoins(vector<int>& nums) {
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    int size = static_cast<int>(nums.size());
    cache_t cache(size, std::vector<int>(size, 0));

    for (int len = 2; len < size; ++len) {
      for (int start = 0; start < size - len; ++start) {
        range_best(cache, nums, start, start + len);
      }
    }
    return cache[0][size - 1];
  }
};
int main() {
  Solution s;
  vector<int> nums = {3, 1, 5, 8};
  cout << s.maxCoins(nums) << endl;
  return 0;
}
