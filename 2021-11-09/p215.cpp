#include <debug.h>
#include <queue>
class Solution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    priority_queue<int, vector<int>, greater<int>> q;
    for (auto num : nums) {
      // 随便送入 k 个数字到 q
      if (q.size() != k) {
        q.push(num);
      }
      // 然后把最小的换走，剩下 k 个最大的
      else {
        auto min_of_q = q.top();
        if (num > min_of_q) {
          // 置换
          q.pop();
          q.push(num);
        }
      }
    }
    return q.top();
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  vector<int> v = {3, 2, 3, 1, 2, 4, 5, 5, 6};
  cout << s.findKthLargest(v, 4) << endl;
  return 0;
}