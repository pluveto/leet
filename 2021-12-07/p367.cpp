#include <debug.h>

class Solution {
public:
  bool isPerfectSquare(int num) {
    if (num < 0) {
      return false;
    }
    if (num <= 1) {
      return true;
    }
    // 思路：猜数字
    int low = 1, high = 1, mid = 0;
    // let high reach
    while (high * high < num) {
      low = high;
      high *= 2;
      if (high * high == num) {
        return true;
      }
    }
    printf("low = %d\n", low);
    printf("high = %d\n", high);
    printf("mid = %d\n", mid);
    while (low + 1 < high) {
      mid = low + (high - low) / 2;
      printf("mid = %d\n", mid);
      if (mid * mid == num) {
        return true;
      }
      if (mid * mid < num) {
        low = mid;
      } else {
        high = mid;
      }
    }

    return mid * mid == num;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  int num = 389;
  printf("num = %d\n", num);
  //   cin >> num;
  cout << s.isPerfectSquare(num) << endl;
  return 0;
}