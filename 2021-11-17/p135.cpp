#include <debug.h>
size_t sum_vec(vector<int> &v) {
  size_t sum = 0;
  auto n = v.size();
  for (int i = 0; i < n; i++) {
    sum += v[i];
  }
  return sum;
}
class Solution {
public:
  int candy(vector<int> &r) {
    auto n = r.size();
    std::vector<int> c(n, 1);
    if (n >= 2) { // 针对初始化优化
      for (int i = n - 2; i >= 0; i--) {
        if (r[i] > r[i + 1]) {
          c[i] = c[i + 1] + 1;
        }
      }
    }
    int cc = 1; // 一轮循环中的变化次数
    while (cc != 0) {
      cc = 0;
      for (int i = 0; i < n; i++) {
        if (i - 1 >= 0 && r[i] > r[i - 1] && c[i] <= c[i - 1]) {
          c[i] = c[i - 1] + 1;
          cc++;
        }
        if (i + 1 < n && r[i] > r[i + 1] && c[i] <= c[i + 1]) {
          c[i] = c[i + 1] + 1;
          cc++;
        }
      }
    }
    return sum_vec(c);
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  std::vector<int> v;
  size_t c;

  v = {1, 0, 2};
  c = s.candy(v);
  printf("c = %d\n", c);

  v = {1, 8, 7, 1, 1, 9, 9};
  c = s.candy(v);
  printf("c = %d\n", c);

  v = {1, 9, 8, 7, 1, 9, 9, 9, 8, 7};
  c = s.candy(v);
  printf("c = %d\n", c); // 20

  v = {1, 9, 2, 1};
  c = s.candy(v);
  printf("c = %d\n", c);

  v = {10, 9, 8, 7, 6, 10, 9, 8, 7, 6};
  c = s.candy(v);
  printf("c = %d\n", c); // 20
  return 0;
}