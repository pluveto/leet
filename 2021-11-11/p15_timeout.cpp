#include <debug.h>

class Solution {
public:
  vector<vector<int>> anySum(vector<int> &nums, int any, int expect) {
    if (nums.size() < any) {
      return {};
    }
    vector<vector<int>> ret;
    // 如 {0,0,1,2,3}, 1, 0
    // 则应该返回 {{0},{0}}
    if (any == 1) {
      for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == expect) {
          vector<int> ni;
          ni.push_back(nums[i]);
          ret.push_back(ni);
        }
      }
    }
    // 将 nums[i] 与剩下的右边的组合
    for (int i = 0; i < nums.size(); i++) {

      vector<int> tmp = nums;
      tmp.erase(tmp.begin(), tmp.begin() + i + 1);

      // nums[0] +  anySum(nums-nums[0]) = expect
      vector<vector<int>> try_list = anySum(tmp, any - 1, expect - nums[i]);
      for (int j = 0; j < try_list.size(); j++) {
        try_list[j].push_back(nums[i]);
        ret.push_back(try_list[j]);
      }
    }
    sort(ret.begin(), ret.end());
    return ret;
  }
  //   void remove_duplicated(vector<int> &nums) {
  //     auto current = nums.begin();
  //     auto end = nums.end();
  //     while (current != end) {
  //       auto next = current + 1;
  //       if (next != end) {
  //         if (*current == *next) {
  //           nums.erase(current);
  //           end = nums.end();
  //           continue;
  //         }
  //       }
  //       current++;
  //     }
  //   }
  void remove_duplicated(vector<vector<int>> &nums) {
    auto current = nums.begin();
    auto end = nums.end();
    while (current != end) {
      auto next = current + 1;
      if (next != end) {
        if (*current == *next) {
          nums.erase(current);
          end = nums.end();
          continue;
        }
      }
      current++;
    }
  }
  vector<vector<int>> threeSum(vector<int> &nums) {
    // 排序去重
    sort(nums.begin(), nums.end());
    print_vec(nums);
    auto ret = anySum(nums, 3, 0);
    remove_duplicated(ret);
    return ret;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  // vector<int> v = {-1, 0, 1, 2, -1, -4};
  vector<int> v = {-4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6};
  for (auto x : s.threeSum(v)) {
    print_vec(x);
  }
  return 0;
}