#include <debug.h>

class Solution {

public:
  // 我们要取得的是 {1, 2, 2, 2, 3} 中的第一个 2
  // 那么最后的格局是： {1}{2,2,2,3}，取 r
  // 因此 r 的扩张要更强势，即不带等号（等号相当于优先扩张 l）
  int search_first(vector<int> &v, int target) {
    int l = -1, m, r = v.size();
    while (l + 1 != r) {
      m = (r - l) / 2 + l;
      if (v[m] < target) {
        l = m;
      } else {
        r = m;
      }
    }
    return r;
  }
  // 我们要取得的是 {1, 2, 2, 2, 3} 中的最后一个 2
  // 即最后的格局是 {1,2,2,2}{3}，取 l
  // 那么 l 的扩张更强势
  int search_last(vector<int> &v, int target) {
    int l = -1, m, r = v.size();
    while (l + 1 != r) {
      m = (r - l) / 2 + l;
      // 小于目标值，说明下界给得太小，所以扩张 l
      if (v[m] <= target) {
        l = m;
      } else {
        r = m;
      }
    }
    return l;
  }

  vector<int> searchRange(vector<int> &nums, int target) {
    if (nums.empty())
      return {-1, -1};

    int l = search_first(nums, target);
    int r = search_last(nums, target);

    bool l_valid = 0 <= l && l <= nums.size() - 1;
    if (l_valid && nums[l] != target) {
      return {-1, -1};
    }

    bool r_valid = 0 <= r && r <= nums.size() - 1;
    if (r_valid && nums[r] != target) {
      return {-1, -1};
    }
    return {l, r};
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  vector<int> v = {5, 7, 7, 8, 8, 10};
  auto ret = s.searchRange(v, 6);
  print_vec(ret);

  vector<int> v2 = {1, 2, 3, 3, 3, 4, 5};
  auto ret2 = s.searchRange(v2, 3);
  print_vec(ret2);

  vector<int> v3 = {2, 2};
  auto ret3 = s.searchRange(v3, 3);
  print_vec(ret3);

  vector<int> v4 = {1};
  auto ret4 = s.searchRange(v4, 0);
  print_vec(ret4);
  return 0;
}