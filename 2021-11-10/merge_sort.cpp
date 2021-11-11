#include <debug.h>

class Solution {
  // 临时存放排序后的升序元素
  vector<int> tmp;

public:
  void merge_vec(vector<int> &v, int iv1from, int iv1to, int iv2from,
                 int iv2to) {
    // printf("part1 = ");
    // print_vec_part(v, iv1from, iv1to);
    // printf("part2 = ");
    // print_vec_part(v, iv2from, iv2to);

    int l = iv1from, r = iv2from, ins = 0; // ins 表示插入位置
    while (l < iv1to && r < iv2to) {
      // 将较小的复制到 tmp 的开头
      if (v[l] < v[r]) {
        tmp[ins] = v[l];
        l++;
        ins++;
      } else {
        tmp[ins] = v[r];
        r++;
        ins++;
      }
    }
    // 最后有剩余
    while (l < iv1to) {
      tmp[ins] = v[l];
      l++;
      ins++;
    }
    while (r < iv2to) {
      tmp[ins] = v[r];
      r++;
      ins++;
    }
    // 将临时元素覆盖 iv1from, iv2to 的 v 的空间
    for (int i = iv1from; i < iv2to; i++) {
      v[i] = tmp[i - iv1from];
    }
    // printf("merged [%d,%d] = ", iv1from, iv2to - 1);
    // print_vec_part(v, iv1from, iv2to);
  }
  // 左闭右开
  void merge_sort(vector<int> &v, int from, int to) {
    if (to - from <= 1) {
      return;
    }
    auto mid = from + (to - from) / 2;
    // printf("from = %d\n", from);
    // printf("to = %d\n", to);
    // printf("mid = %d\n", mid);
    merge_sort(v, from, mid);
    merge_sort(v, mid, to);
    merge_vec(v, from, mid, mid, to);
  }
  vector<int> sortArray(vector<int> &v) {
    tmp = vector<int>(v.size());
    merge_sort(v, 0, v.size());
    return v;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  vector<int> v = {9, 5, 4, 6, 8, 1, 2, 3, 7};
  auto ret = s.sortArray(v);
  print_vec(ret);
  return 0;
}