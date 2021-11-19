#include <debug.h>
#include <math.h>
class Solution {
public:
  int bulbSwitch(int nmax) {
    return sqrt(nmax) - 1;
    std::vector<bool> bm(nmax, true);
    // print_vec(bm);
    for (int n = 2; n <= nmax; n++) {
      for (int i = 1; i < nmax; i += n) {
        bm[i] = !bm[i];
      }
      print_vec(bm);
    }
    int sum = 0;
    for (int i = 0; i < bm.size(); i++) {
      sum += bm[i] ? 1 : 0;
    }
    return sum;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  int sum;
  //   sum = s.bulbSwitch(12);
  //   printf("sum = %d\n", sum);
  for (size_t i = 1; i < 20; i++) {
    sum = s.bulbSwitch(i);
    printf("sum = %d\n", sum);
  }

  return 0;
}