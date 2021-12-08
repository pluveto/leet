#include <debug.h>

class Solution {
public:
  vector<int> majorityElement(vector<int> &nums) {
    auto n = nums.size();
    vector<int> ret;
    if (n == 0) {
      return ret;
    }
    if (n == 1) {
      nums.push_back(nums[0]);
      return ret;
    }
    auto n1 = nums[0], c1 = 1;
    auto n2 = nums[1], c2 = 1;

    for (unsigned i = 2; i < n; ++i) {
      auto num = nums[i];
      if (num == n1) {
        c1++;
        continue;
      }
      if (nums == n2) {
        c2++;
        continue;
      }
      if (c1 == 0) {
        n1 = num;
        c1++;
        continue;
      }
      if (c2 == 0) {
        n2 = num;
        c2++;
        continue;
      }
      c1--;
      c2--;
    }

    // statistics
    c1 = 0;
    c2 = 0;

    // 会不会出现 n1 = n2?
    for (unsigned i = 0; i < n; ++i) {
      if (n == n1) {
        c1++;
      }
      if (n == n2) {
        c2++;
      }
    }
    if (c1 > n / 3) {
      ret.push_back(n1);
    }
    if (c2 > n / 3) {
      ret.push_back(n2);
    }
    return ret;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;

  return 0;
}