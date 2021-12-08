#include <debug.h>

void swap(vector<int> &xs, int i, int j) {
  printf("swap %d,%d\n", xs[i], xs[j]);
  int tmp = xs[i];
  xs[i] = xs[j];
  xs[j] = tmp;
}

void wmerge(vector<int> &xs, int i, int m, int j, int n, int w) {
  while (i < m && j < n) {
    if (xs[i] < xs[j]) {
      printf("%d < %d \n", xs[i], xs[j]);
    } else {
      printf("%d >= %d \n", xs[i], xs[j]);
    }
    swap(xs, w++, xs[i] < xs[j] ? i++ : j++);
    print_vec(xs);
  }
  while (i < m) {
    swap(xs, w++, i++);
    print_vec(xs);
  }
  while (j < n) {
    swap(xs, w++, j++);
    print_vec(xs);
  }
}

int main(int argc, char const *argv[]) {
  //               0  1  2  3  4  5  6
  vector<int> v = {2, 5, 1, 2, 6, 6, 9};
  //               ^i ^w ^j
  wmerge(v, 0, 1, 2, 7, 1);
  return 0;
}