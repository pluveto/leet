#include <debug.h>

class Solution {
public:
  vector<int> countSmaller(vector<int> &nums) {
    int n = nums.size();
    std::vector<int> ret(n);
    for (int i = 0; i < n; i++) {
      int cnt = 0;
      for (int j = i + 1; j < n; j++) {
        if (nums[j] > nums[i]) {
          cnt++;
        }
      }
      ret[i] = cnt;
    }
  }
};

int main(int argc, char const *argv[]) {
  Solution s;

  return 0;
}