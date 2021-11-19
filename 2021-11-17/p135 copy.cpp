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
    int cc = 1; // 一轮循环中的变化次数
    int step = 0;
    while (cc != 0) {
      cc = 0;
      for (int i = 0; i < n; i++) {
        if (i - 1 >= 0 && r[i] > r[i - 1] && c[i] <= c[i - 1]) {
          c[i] = c[i - 1] + 1;
          cc++;
          step++;
        }
        if (i + 1 < n && r[i] > r[i + 1] && c[i] <= c[i + 1]) {
          c[i] = c[i + 1] + 1;
          cc++;
          step++;
        }
      }
      print_vec(c);
      printf("cc = %d\n", cc);
      printf("step = %d\n", step);
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

  v = {1, 9, 2, 1};
  c = s.candy(v);
  printf("c = %d\n", c);

  v = {};
  for (int i = 0; i < 10000; i++) {
    v.push_back(i);
  }
  c = s.candy(v);
  printf("c = %d\n", c);

  return 0;
}