#include <debug.h>

class Solution {
public:
  void merge(map<int, int> &idxOf, vector<int> &counter, vector<int> &nums,
             int fromIdx, int midIdx, int toIdx) {
    // 逆向双指针法合并两个有序数组
    int l1 = fromIdx;
    int l2 = midIdx + 1;
    int ins = 
    int n1, n2;
    while(l1 <= midIdx && l2 <= toIdx) {
        n1 = nums[fromIdx];
        n2 = nums[midIdx];
        // 将较小的先放入
        // 1 2 3 2 5 6
        // 2 5 6
        // 1 2
        /* code */
    }
    // 处理剩余的
    while(l1 <= midIdx){

    }
    while(l2 <= toIdx){

    }
    return
        
  }
  void impl(map<int, int> &idxOf, vector<int> &counter, vector<int> &nums,
            int fromIdx, int toIdx) {
    auto n = toIdx - fromIdx + 1;
    // 若只有一个元素，则无需处理
    if (n <= 1) {
      return;
    }

    // - 分割点
    int midIdx = n / 2; // 若 n 为奇数，如 n = 3，
                        // 则 n / 2 = 1，则左侧包含 2 个元素
    // 分治
    impl(idxOf, counter, nums, fromIdx, midIdx); // 两侧 闭区间
    impl(idxOf, counter, nums, midIdx + 1, toIdx);
    // 合并
    merge(idxOf, counter, nums, fromIdx, midIdx, toIdx);
  }
  vector<int> countSmaller(vector<int> &nums) {
    auto n = nums.size();
    map<int, int> idxOf;
    for (int i = 0; i < n; i++) {
      idxOf[nums[i]] = i;
    }
    vector<int> counter(n);
    impl(idxOf, counter, nums, 0, n);
    return counter;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;

  return 0;
}