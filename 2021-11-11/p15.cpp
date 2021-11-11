#include <debug.h>

void remove_duplicated_arr(vector<int> &nums) {
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

class Solution {
public:
  bool same_list(vector<int> &v1, vector<int> &v2) {
    if (v1.size() != v2.size()) {
      return false;
    }
    for (size_t i = 0; i < v1.size(); i++) {
      if (v1[i] != v2[i]) {
        return false;
      }
    }
    return true;
  }
  vector<vector<int>> anySum(vector<int> &nums, int any, int expect) {
    if (nums.size() < any) {
      return {};
    }
    vector<vector<int>> ret;
    // 如 {0,0,1,2,3}, 1, 0
    // 则应该返回 {{0},{0}}
    if (any == 1) {
      remove_duplicated_arr(nums);
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
      if (i - 1 >= 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      vector<int> tmp = nums;
      tmp.erase(tmp.begin(), tmp.begin() + i + 1);

      // nums[0] +  anySum(nums-nums[0]) = expect
      vector<vector<int>> try_list = anySum(tmp, any - 1, expect - nums[i]);
      remove_duplicated(try_list);
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
    auto ret = anySum(nums, 3, 0);
    // remove_duplicated(ret);
    return ret;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  vector<int> v1 = {-1, 0, 1, 2, -1, -4};
  for (auto x : s.threeSum(v1)) {
    print_vec(x);
  }
  vector<int> v = {
      -13, 5,   13,  12,  -2,  -11, -1,  12, -3,  0,   -3, -7, -7,  -5, -3, -15,
      -2,  14,  14,  13,  6,   -11, -11, 5,  -15, -14, 5,  -5, -2,  0,  3,  -8,
      -10, -7,  11,  -5,  -10, -5,  -7,  -6, 2,   5,   3,  2,  7,   7,  3,  -10,
      -2,  2,   -12, -11, -1,  14,  10,  -9, -15, -8,  -7, -9, 7,   3,  -2, 5,
      11,  -13, -15, 8,   -3,  -7,  -12, 7,  5,   -2,  -6, -3, -10, 4,  2,  -5,
      14,  -3,  -1,  -10, -3,  -14, -4,  -3, -7,  -4,  3,  8,  14,  9,  -2, 10,
      11,  -10, -4,  -15, -9,  -1,  -1,  3,  4,   1,   8,  1};
  for (auto x : s.threeSum(v)) {
    print_vec(x);
  }
  return 0;
}