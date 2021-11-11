#include <debug.h>

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {

    int x = 0, y = 0;
    while (true) {
      if (x == matrix[0].size() || y == matrix.size()) {
        break;
      }
      auto cur = matrix[x][y];
      if (cur == target) {
        return true;
      }
      auto right = matrix[x + 1][y];
      auto down = matrix[x][y + 1];
      // 如果右边在当前值和目标值之间，则走过去
      if (cur <= right && right <= target) {
        x++;
      }
      right = matrix[x + 1][y];
      down = matrix[x][y + 1];
      if (cur <= down && down <= target) {
        y++;
      }
      // 如果右边大于目标，下边也大于目标，则无解
      if (right > target && down > target) {
        break;
      }
    }
    return false;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  vector<vector<int>> m = {
      {1, 4, 7, 11, 15},    {2, 5, 8, 12, 19},    {3, 6, 9, 16, 22},
      {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30},
  };
  cout << s.searchMatrix(m, 5) << endl;
  m = {
      {1, 4, 7, 11, 15},    {2, 5, 8, 12, 19},    {3, 6, 9, 16, 22},
      {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30},
  };
  cout << s.searchMatrix(m, 5) << endl;

  return 0;
}