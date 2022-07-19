#include "../inc/debug.h"

class Solution {
 public:
  int maxSubArrayLen(vector<int>& nums, int k) {
    //值为x的前缀和最早出现的下标y
    map<int, int> hash;
    // 这个初始化很重要，为了考虑到 0~i等于k的情况
    hash[0] = -1;
    int sum = 0;
    int res = 0;
    for (int i = 0; i < nums.size(); ++i) {
      printf("\ni=%d\n", i);
      sum += nums[i];
      printf("sum: %d\n", sum);
      print_map(hash);
      // 如果 sum-k 存在，说明和为 sum-k 的
      if (hash.count(sum - k)) {
        printf("sum-k: %d\n", sum - k);
        res = max(res, i - hash[sum - k]);
        printf("res: %d\n", res);
      }
      if (!hash.count(sum))
        hash[sum] = i;  // 因为要的是第一次出现的值
    }

    return res;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> in1 = {1, 2, 4, 3, 4, 5};
  int out = s.maxSubArrayLen(in1, 9);
  return 0;
}