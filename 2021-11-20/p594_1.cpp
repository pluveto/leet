#include <debug.h>

class Solution {
public:
  int findLHS(vector<int> &v) {
    sort(v.begin(), v.end());
    print_vec(v);
    int l = 0, r = 1, maxlen = 0, n = v.size();
    while (l < r && r < n) {
      while (l < r && v[r] - v[l] > 1) {
        l++;
      }
      if (v[r] - v[l] == 1) {
        maxlen = max(maxlen, r - l + 1);
        print_vec_part(v, l, r + 1);
      }
      r++;
    }
    return maxlen;
  }
};
int main(int argc, char const *argv[]) {
  Solution s;
  // std::vector<int> v = {1, 3, 2, 2, 5, 2, 3, 7};
  std::vector<int> v = {3, 4, 9, 1, 2, 1, 2, 1, 2, 9, 5, 3};
  cout << s.findLHS(v) << endl;
  return 0;
}