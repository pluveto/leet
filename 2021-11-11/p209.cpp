#include <debug.h>

class Solution {
public:
  int minSubArrayLen(int target, vector<int> &nums) {
    int l = 0, r = 0, minLen = nums.size();
    int len = l - r + 1;
    // 暴力法
    // 第一轮
    // 2, 3, 1, 2, 4, 3
    // '
    // 2, 3, 1, 2, 4, 3
    //    '
    // 2, 3, 1, 2, 4, 3
    //       '

    // 第二轮
    // 2, 3, 1, 2, 4, 3
    // '  '
    // 2, 3, 1, 2, 4, 3
    //    '  '
    // 2, 3, 1, 2, 4, 3
    //       '  '
    
    // 滑动窗口法
    // l, r 指针。
    // 若 r 右移，sum += v[r]
    // 若 l 右移，sum -= v[r]
    // 先让 r 右移，直到满足条件
    // 然后让 l 左移，直到不满足条件
    // 返回临界值 r - l + 1 + 1 即可。

    return minLen;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  vector<int> v = {2, 3, 1, 2, 4, 3};
  cout << s.minSubArrayLen(7, v) << endl;
  ;
  return 0;
}