#include <debug.h>

class Solution {
public:
  // 初始条件下，v1 的长度是 m+n
  void merge(vector<int> &v1, int m, vector<int> &v2, int n) {
    int l = m - 1, r = n - 1, ins = m + n - 1; // ins: 插入位置
    while (l >= 0 && r >= 0) {
      if (v1[l] > v2[r]) {
        v1[ins] = v1[l];
        ins--;
        l--;
      } else {
        v1[ins] = v2[r];
        ins--;
        r--;
      }
    }
    while (r >= 0) {
      v1[ins] = v2[r];
      ins--;
      r--;
    }
  }
};
int main(int argc, char const *argv[]) {
  Solution s;
  std::vector<int> v1 = {3, 5, 0, 0,
                         0};       //{1, 2, 4, 7, 10, 11, 0, 0, 0, 0, 0, 0};
  std::vector<int> v2 = {1, 2, 6}; //{0, 3, 4, 5, 6, 12};
  s.merge(v1, 2, v2, 3);
  print_vec(v1);
  return 0;
}