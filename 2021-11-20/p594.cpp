#include <debug.h>

class Solution {
public:
  int findLHS(vector<int> &v) {
    int n = v.size();
    bool ok = true;
    int maxlen = 0, l = 0, r = 0;
    int i_min = 0, i_max = 0;
    while (l <= r && r < n) {
      ok = v[i_max] - v[i_min] <= 1;
      if (ok) {
        maxlen = max(maxlen, r - l + 1);
        printf("l = %d\n", l);
        printf("r = %d\n", r);
        print_vec_part(v, l, r + 1);
        r++;
        if (r < n) {
          i_min = v[r] < v[i_min] ? r : i_min;
          i_max = v[r] > v[i_max] ? r : i_max;
        }
      } else {
        l = r;
        i_min = l;
        i_max = l;
      }
    }
    return maxlen;
  }
};
int main(int argc, char const *argv[]) {
  Solution s;
  std::vector<int> v = {3,4,9,1,2,1,2,1,2,9,5,3};
  cout << s.findLHS(v) << endl;
  return 0;
}