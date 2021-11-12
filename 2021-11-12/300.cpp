#include <debug.h>

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

    }
};

int main(int argc, char const *argv[]) {
  Solution s;
  std::vector<int> v;
  //   v = {10, 9, 2, 5, 3, 7, 101, 18};
  v = {34, 82, 90, 69, 4,  30, 9, 69, 2, 68, 4, 36, 20,
       8,  4,  63, 14, 66, 6,  6, 60, 8, 91, 8, 89, 0};
  cout << s.lengthOfLIS(v) << endl;
  return 0;
}