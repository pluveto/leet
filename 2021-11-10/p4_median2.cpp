#include <debug.h>

class Solution {
public:
  void test_slice_mid() {
    // printf("(slice_mid({1},0,0)) = %.2f\n", (slice_mid({1}, 0, 0)));
    // printf("(slice_mid({1,2},0,1)) = %.2f\n", (slice_mid({1, 2}, 0, 1)));
  }
  double slice_mid(vector<int> v, int from, int to) {
    // 偶数个元素
    auto size = (from - to + 1);
    auto mid = from + (to - from) / 2; // 靠下的中点
    // printf("mid = %d\n", mid);
    if (size % 2 == 0) {
      return (double(v[mid]) + double(v[mid + 1])) / 2.0;
    } else {
      return v[mid];
    }
  }
  double findMedianSortedArrays(vector<int> &a, vector<int> &b) {
    if (a.size() > b.size()) {
      return findMedianSortedArrays(b, a);
    }

    int al = 0, ar = a.size() - 1;
    int bl = 0, br = b.size() - 1;

    while (true) {

      printf("a = ");
      print_vec_part(a, al, ar + 1);
      printf("b = ");
      print_vec_part(b, bl, br + 1);
      auto size_a = ar + 1 - al;
      auto size_b = br + 1 - bl;
      // 删除的数量
      // 比如 {1,2,3,4}，则删除 数量是 2，即 size/2
      // 如果是 {1,2,3}，则删除数量是 1，即 size/2
      // 如果是 {1},则删除数量是 1，即 1
      // 如果是 {1,2}，则删除数量是 1, 即 size/2
      auto delNum = (min(size_a, size_b)) / 2;
      if (delNum == 0) {
        printf("delNum++\n");
        delNum++;
      }
      // 如果两个都只剩一个，则返回平均值
      if (size_a == 1 && size_b == 1) {
        return (double(a[ar]) + double(b[br])) / 2;
      }
      // if (size_a == 2 && size_b == 2) {
      //   continue;
      // }
      // 如果某个数组空，则返回另一个的中位数
      if (size_a == 0) {
        return slice_mid(b, bl, br);
      }
      if (size_b == 0) {
        return slice_mid(a, al, ar);
      }
      // 其中一个的中位数，必须要大于另一个的最小值
      if (size_a <= 5 || size_b <= 5) {
        delNum = 1;
      }
      printf("delNum = %d\n", delNum);
      // 从小端删除左边
      if (a[al] <= b[bl]) {
        al += delNum;
      } else {
        bl += delNum;
      }
      // 从大端删除右边
      if (a[ar] > b[br]) {
        ar -= delNum;
      } else {
        br -= delNum;
      }
      // 从小端删除左边
      // if (a[al] <= b[bl]) {
      //   al += delNum;
      //   br -= delNum;
      // } else {
      //   bl += delNum;
      //   ar -= delNum;
      // }
    }
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  s.test_slice_mid();
  auto expect = 0.0;
  auto ret = 0.0;

  vector<int> b = {8,  17, 25, 29, 36, 43, 46, 51, 59,
                   62, 65, 67, 71, 73, 76, 84, 90, 97};
  vector<int> a = {2,  4,  11, 15, 25, 31, 41, 46,
                   55, 57, 65, 74, 76, 79, 80, 89};
  ret = s.findMedianSortedArrays(a, b);
  expect = 56;
  printf("expect = %.2f, got %.2f\n\n", expect, ret);

  b = {0, 0, 0, 0, 0};
  a = {-1, 0, 0, 0, 0, 0, 1};
  ret = s.findMedianSortedArrays(a, b);
  expect = 0;
  printf("expect = %.2f, got %.2f\n\n", expect, ret);

  b = {1, 3};
  a = {2};
  ret = s.findMedianSortedArrays(a, b);
  expect = 2;
  printf("expect = %.2f, got %.2f\n\n", expect, ret);

  b = {1, 2, 3};
  a = {1, 2, 2};
  ret = s.findMedianSortedArrays(a, b);
  expect = 2;
  printf("expect = %.2f, got %.2f\n\n", expect, ret);

  b = {1, 2, 3, 8};
  a = {4, 5, 6, 7};
  ret = s.findMedianSortedArrays(a, b);
  expect = 4.5;
  printf("expect = %.2f, got %.2f\n\n", expect, ret);

  b = {1, 2, 4, 8};
  a = {3, 5, 6, 7};
  ret = s.findMedianSortedArrays(a, b);
  expect = 4.5;
  printf("expect = %.2f, got %.2f\n\n", expect, ret);

  b = {1, 2, 5, 8};
  a = {3, 4, 6, 7};
  ret = s.findMedianSortedArrays(a, b);
  expect = 4.5;
  printf("expect = %.2f, got %.2f\n\n", expect, ret);

  b = {1, 2, 3, 4, 10};
  a = {5, 6, 7, 8, 9};
  ret = s.findMedianSortedArrays(a, b);
  expect = 5.5;
  printf("expect = %.2f, got %.2f\n\n", expect, ret);

  b = {1,1,1,1,1,1,1,1,1,1,4,4};
  a = {1,3,4,4,4,4,4,4,4,4,4};
  ret = s.findMedianSortedArrays(a, b);
  expect = 3.0;
  printf("expect = %.2f, got %.2f\n\n", expect, ret);
  return 0;
}