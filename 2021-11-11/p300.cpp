#include <debug.h>

class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    // 思路:
    // 10, 9, 2, 5, 3, 7, 101, 18
    // 对于 cur =  10，寻找 10 后面第一个大于 10 的数 101, counter ++
    // 对于 cur = 101，寻找 101 后面第一个大于 101 的数，没找到，返回
    // 0, 1, 0, 3, 0, 2, 3
    // cur = 0, next = 1, next = 3, 这不对，因为后面还有更小的
    int max_counter = 0;
    for (int i = 0; i < nums.size(); i++) {
      int cur = nums[i];
      int counter = 1;
      for (int j = i; j < nums.size(); j++) {
        if (nums[j] > cur) {
          printf("incr at j =%d, nums[j] = %d, cur = %d\n", j, nums[j], cur);
          cur = nums[j];
          counter++;
          printf("counter = %d\n", counter);
        } else {
          printf("skip nums[j] = %d, cur = %d\n", nums[j], cur);
        }
        printf("j = %d\n", j);
      }
      if (counter > max_counter) {
        max_counter = counter;
      }
    }
    return max_counter;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  std::vector<int> v;
  //   v = {10, 9, 2, 5, 3, 7, 101, 18};
  v = {0, 1, 0, 3, 2, 3};
  cout << s.lengthOfLIS(v) << endl;
  return 0;
}