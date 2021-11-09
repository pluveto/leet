#include <debug.h>

void adjust(vector<int> &v, int bound, int i) {
  // 子节点索引
  int i_left = 2 * i + 1;
  int i_right = i_left + 1;
  // 选出比根大的子节点
  int i_max = i;
  i_max = i_left < bound && v[i_left] > v[i_max] ? i_left : i_max;
  i_max = i_right < bound && v[i_right] > v[i_max] ? i_right : i_max;
  if (i_max != i) {
    // 让小的靠根
    swap(v[i_max], v[i]);
    // 调整变化后的子树
    adjust(v, bound, i_max);
  }
}

void heap_sort(vector<int> &v) {
  // 构建大根堆
  int n = v.size();
  for (int i = n / 2 - 1; i >= 0; i--) {
    adjust(v, n, i);
  }
  // 选择排序
  for (int i = n - 1; i != 0; i--) {
    swap(v[0], v[i]);
    adjust(v, i, 0);
  }
}

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    vector<int> ret(nums);
    heap_sort(ret);
    return ret;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  vector<int> arr = {8, 1, 14, 3, 21, 5, 7, 10};
  auto sorted = s.sortArray(arr);
  print_vec(sorted);
  return 0;
}