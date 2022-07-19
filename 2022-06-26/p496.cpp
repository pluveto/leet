#include "../inc/debug.h"


class Solution {
 public:
  vector<int> nextGreaterElement(vector<int>& query, vector<int>& nums) {
    map<int, int> num2idx;
    for (size_t i = 0; i < nums.size(); i++) {
      num2idx[nums[i]] = i;
    }
    print_map(num2idx);
    //--BEGIN--
    stack<int> incr_stk;
    vector<int> ngn(nums.size());
    for (int i = nums.size() - 1; i >= 0; i--) {
      // 过滤
      while (!incr_stk.empty() && incr_stk.top() <= nums[i]) {
        incr_stk.pop();
      }
      // 求解
      ngn[i] = incr_stk.empty() ? -1 : incr_stk.top();

      incr_stk.push(nums[i]);
    }
    //--END--
    vector<int> ret(query.size());
    for (int i = 0; i < query.size(); i++) {
      ret[i] = ngn[num2idx[query[i]]];
    }
    print_vec(ngn);
    return ret;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> in1 = {4, 1, 2};
  vector<int> in2 = {1, 3, 4, 2};
  vector<int> out = s.nextGreaterElement(in1, in2);
  print_vec(out);
  return 0;
}