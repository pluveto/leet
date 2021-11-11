#include <debug.h>

class Solution {
  // 临时存放排序后的升序元素
  int *tmp;

public:
  void merge_vec(vector<int> &v, int from, int mid, int to) {
    int l = from, r = mid, ins = 0;
    while (l < mid && r < to) {
      if (v[l] < v[r])
        tmp[ins++] = v[l++];
      else
        tmp[ins++] = v[r++];
    }
    while (l < mid)
      tmp[ins++] = v[l++];

    while (r < to)
      tmp[ins++] = v[r++];

    for (int i = from; i < to; i++)
      v[i] = tmp[i - from];
  }
  void merge_sort(vector<int> &v, int from, int to) {
    if (to - from <= 1)
      return;
    auto mid = from + (to - from) / 2;
    merge_sort(v, from, mid);
    merge_sort(v, mid, to);
    merge_vec(v, from, mid, to);
  }
  vector<int> sortArray(vector<int> &v) {
    tmp = (int *)malloc(v.size() * sizeof(int));
    merge_sort(v, 0, v.size());
    free(tmp);
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