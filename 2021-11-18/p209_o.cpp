#include <debug.h>

class Solution {
public:
  // 4,       {1,4,4}
  int minSubArrayLen(int target, vector<int> &v) {
    int n = v.size();
    if (n == 0) {
      return 0;
    }
    int l = 0, r = 0;
    int minlen = INT_MAX;
    size_t sum = v[0];
    while (l <= r && r < n) {
      if (sum >= target) {
        minlen = min(minlen, r - l + 1);
        sum -= v[l];
        l++;
      } else {
        r++;
        if (r != n)
          sum += v[r];
      }
    }
    return minlen == INT_MAX ? 0 : minlen;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  int target;
  std::vector<int> v;
  target = 7;
  v = {2, 3, 1, 2, 4, 3};
  cout << s.minSubArrayLen(target, v) << endl;
  target = 4;
  v = {1, 4, 4};
  cout << s.minSubArrayLen(target, v) << endl;
  target = 4;
  v = {4, 1, 1};
  cout << s.minSubArrayLen(target, v) << endl;
  target = 11;
  v = {1, 1, 1, 1, 1, 1, 1, 1};
  cout << s.minSubArrayLen(target, v) << endl;
  target = 8;
  v = {1, 2, 5, 2, 3, 5, 4};
  cout << s.minSubArrayLen(target, v) << endl;
  return 0;
}