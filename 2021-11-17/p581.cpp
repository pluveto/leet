#include <debug.h>

class Solution {
public:
  //寻找小区间，使得中间的数字都在两端的值之内，两端的数字都升序排列

  int findUnsortedSubarray(vector<int> &nums) {
    int n = nums.size();
    std::vector<int> sorted(nums);
    sort(sorted.begin(), sorted.end());
    int l = 0, r = n - 1;
    while (l <= r && sorted[l] == nums[l]) {
      l++;
    }
    while (l <= r && sorted[r] == nums[r]) {
      r--;
    }
    printf("l = %d\n", l);
    printf("r = %d\n", r);
    return r - l + 1;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  //   vector<int> v = {2, 6, 4, 8, 10, 9, 15};
  vector<int> v = {1, 2, 3, 4}; // 0
  // [2,(6,4,8,10,9),15] // 5
  // [1,2,(5,2,3,5,4)] // 5
  // [1,(85,16,186,1,5)] // 5
  // [1,(2,5,8,74,32,1,8)] // 7
  // [1,2,3,4,5,6,4,3,4,7,8,9] //
  auto r = s.findUnsortedSubarray(v);
  printf("r = %d\n", r);
  return 0;
}