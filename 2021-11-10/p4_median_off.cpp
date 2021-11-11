#include <debug.h>
#include <climits>
class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        if (a.size() > b.size()) {
            return findMedianSortedArrays(b, a);
        }
        
        int size_a = a.size();
        int size_b = b.size();
        int left = 0, right = size_a;
        // amax：前一部分的最大值
        // bmin：后一部分的最小值
        int amax = 0, bmin = 0;

        while (left <= right) {
            // 前一部分包含 nums1[0 .. i-1] 和 nums2[0 .. j-1]
            // 后一部分包含 nums1[i .. m-1] 和 nums2[j .. n-1]
            int amid = (left + right) / 2;
            int bmid = (size_a + size_b + 1) / 2 - amid;

            // nums_im1, nums_i, nums_jm1, nums_j 
            // 分别表示 nums1[i-1], nums1[i], nums2[j-1], nums2[j]
            int nums_im1 = (amid == 0 ? INT_MIN : a[amid - 1]);
            int nums_i = (amid == size_a ? INT_MAX : a[amid]);
            int nums_jm1 = (bmid == 0 ? INT_MIN : b[bmid - 1]);
            int nums_j = (bmid == size_b ? INT_MAX : b[bmid]);

            if (nums_im1 <= nums_j) {
                amax = max(nums_im1, nums_jm1);
                bmin = min(nums_i, nums_j);
                left = amid + 1;
            } else {
                right = amid - 1;
            }
        }

        return (size_a + size_b) % 2 == 0 ? (amax + bmin) / 2.0 : amax;
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