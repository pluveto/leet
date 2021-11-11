#include <debug.h>

class Solution {
public:
  int binary_search(vector<int> &v, int target) {
    auto i_hi = v.size() - 1;
    auto i_lo = 0;
    auto i_md = 0;
    while (i_lo < i_hi + 1) {
      i_md = i_lo + (i_hi - i_lo) / 2;
      if (v[i_md] == target) {
        // return i_md;
        i_lo = i_md + 1;
      }
      if (v[i_md] < target) {
        i_lo = i_md + 1;
      } else
        i_hi = i_md - 1;
    }
    return i_lo;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  vector<int> v = {1, 3, 5, 6};
  cout << s.binary_search(v, 7) << endl;
  vector<int> v2 = {1, 1, 1, 1, 1, 1, 1};
  cout << s.binary_search(v2, 0) << endl;
  vector<int> v3 = {1, 2, 3, 3, 3, 2, 1};
  cout << s.binary_search(v3, 3) << endl;
  return 0;
}