#include <debug.h>

#include <cstring>
class Solution {
 private:
  // value, {[i, j],[i,j]}
  vector<int> v;
  int n;
  map<int, set<pair<int, int>>> memo;
  void initMemo() {
    int zeroCnt = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        auto twoSum = v[i] + v[j];
        if (twoSum > 0) {
          continue;
        }
        if (twoSum == 0 && v[i] == 0) {
          zeroCnt++;
        }
        if (zeroCnt > 3) {
          continue;
        }
        // create if not exists
        auto existing = memo.find(twoSum);
        if (existing == memo.end()) {
          memo[twoSum] = set<pair<int, int>>();
        }
        // add
        memo[twoSum].insert(make_pair(i, j));
        printf("%d = %d + %d\n", twoSum, v[i], v[j]);
      }
    }
  }

 public:
  Solution() {}
  vector<vector<int>> twoSum(int except_idx, int target) {
    auto existing = memo.find(target);
    auto ret = vector<vector<int>>();
    if (existing == memo.end()) {
      return ret;
    }
    typedef struct {
      int a;
      int b;
      int c;
    } n3;
    n3 prev = {-1, -1, -1};
    for (auto&& pair : memo[target]) {
      auto i = pair.first;
      auto j = pair.second;
      if (i == except_idx || j == except_idx) {
        continue;
      }
      int a = -target;
      int b = v[i];
      int c = v[j];
      if (a > b) {
        swap(a, b);
      }
      if (a > c) {
        swap(a, c);
      }
      if (b > c) {
        swap(b, c);
      }
      n3 cur = {a, b, c};
      if (memcmp(&prev, &cur, sizeof(n3)) != 0) {
        ret.push_back({cur.a, cur.b, cur.c});
        prev = cur;
      }
    }
    return ret;
  }
  void removeDup() {}
  vector<vector<int>> threeSum(vector<int>& nums) {
    v = nums;
    n = v.size();
    sort(v.begin(), v.end());
    print_vec(v);
    removeDup();
    print_vec(v);
    initMemo();

    print_vec(v);
    auto ret = set<vector<int>>();
    for (size_t i = 0; i < n; i++) {
      // skip same target
      if (i + 1 < n && v[i] == v[i + 1]) {
        continue;
      }
      auto twosum = twoSum(i, -v[i]);
      for (auto&& item : twosum) {
        ret.insert(item);
      }
    }
    return vector<vector<int>>(ret.begin(), ret.end());
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  //   std::vector<int> v = {-1, 0, 1, 2, -1, 4};
  //   std::vector<int> v = {-4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6};
  std::vector<int> v = {
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  };
  auto ret = s.threeSum(v);
  print_vec_2d(ret);
  return 0;
}