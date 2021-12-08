#include <debug.h>

class Solution {
public:
  vector<string> findRelativeRanks(vector<int> &score) {
    int n = score.size();
    vector<string> ret(n);
    vector<int> original = score;
    // 映射 分数->原数组下标
    map<int, int> indices;
    for (int i = 0; i < n; i++) {
      indices[score[i]] = i;
    }
    // score 降序排序
    sort(score.begin(), score.end(), std::greater<int>());
    for (int i = 0; i < n; i++) {
      int idx = indices[score[i]];
      if (i > 2) {
        ret[idx] = std::to_string(i + 1);
      } else if (i == 0) {
        ret[idx] = "Gold Medal";
      } else if (i == 1) {
        ret[idx] = "Silver Medal";
      } else if (i == 2) {
        ret[idx] = "Bronze Medal";
      }
    }
    return ret;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;

  return 0;
}