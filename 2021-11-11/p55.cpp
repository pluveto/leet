#include <debug.h>
// for (int i = 0; i < nums.size(); i++) {
//   if (nums[i] == 0) {
//      return false;
//   }
// }
class Solution {
public:
  // 如果一个位置能够到达，那么这个位置左侧所有位置都能到达
  bool canJump(vector<int> &nums) {
    // 能跳的最远距离
    auto farthest = 0;
    // 目标位置
    auto end = nums.size() - 1;
    for (int i = 0; i < farthest; i++) {
      auto cur_farthest = i + nums[i];
      farthest = max(cur_farthest, farthest);
      if (farthest >= end) {
        return true;
      }
    }
    return false;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  vector<int> v;
  //   v = {2, 3, 1, 1, 4};
  //   cout << s.canJump(v) << endl;
  //   v = {3, 2, 1, 0, 4};
  //   cout << s.canJump(v) << endl;
  //   v = {0};
  //   cout << s.canJump(v) << endl;
  //   v = {1};
  //   cout << s.canJump(v) << endl;
  //   v = {2, 5, 0, 0};
  //   cout << s.canJump(v) << endl;
  //   v = {1, 2, 0, 1};
  //   cout << s.canJump(v) << endl;
  v = {1, 1, 2, 2, 0, 1, 1};
  cout << s.canJump(v) << endl;
  return 0;
}