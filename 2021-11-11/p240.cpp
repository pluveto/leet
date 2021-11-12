#include <debug.h>

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    // 需要注意轴向
    // +--> y
    // |
    // x
    int x = 0, y = 0;
    int xMax = matrix.size() - 1;
    int yMax = matrix[0].size() - 1;
    int allowRight = 1;
    int allowDown = 1;
    while (true) {
      if (x > xMax || y > yMax) {
        break;
      }
      auto cur = matrix[x][y];
      if (cur == target) {
        return true;
      }
      // 如果右边或者下边已经是目标，则直接返回
      allowDown = (x + 1 <= xMax);
      allowRight = (y + 1 <= yMax);
      if (allowDown) {
        auto down = matrix[x + 1][y];
        if (down == target) {
          return true;
        }
      }
      if (allowRight) {
        auto right = matrix[x][y + 1];
        if (right == target) {
          return true;
        }
      }
      // 不能再往下移动，则只能往右移动

      if (allowDown) {
        auto down = matrix[x + 1][y];
        // 如果右边在当前值和目标值之间，则走过去
        if (cur <= down && down <= target) {
          x++;
        }
      }

      if (allowRight) {
        auto right = matrix[x][y + 1];
        if (cur <= right && right <= target) {
          y++;
        }
      }
      cur = matrix[x][y];
      if (cur == target) {
        return true;
      }
      // 如果右边大于目标，下边也大于目标，则无解
      // 考虑边界情况：没有下边，则只判断右边
      // 考虑边界情况：没有右边，则只判断下边
      // 考虑边界情况：没有右边和下边，则一定不对
      allowDown = (x + 1 <= xMax);
      allowRight = (y + 1 <= yMax);

      if (!allowDown && !allowRight) {
        break;
      } else if (!allowDown && allowRight) {
        auto right = matrix[x][y + 1];
        if (right > target)
          break;
      } else if (allowDown && !allowRight) {
        auto down = matrix[x + 1][y];
        if (down > target)
          break;
      } else if (allowDown && allowRight) {
        auto down = matrix[x + 1][y];
        auto right = matrix[x][y + 1];
        if (right > target && down > target)
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
  m = {{1, 4}, {2, 5}};
  //   vector<vector<int>> m = {{1, 1}};
  cout << s.searchMatrix(m, 4) << endl;
  m = {{1, 3, 5, 7, 9},
       {2, 4, 6, 8, 10},
       {11, 13, 15, 17, 19},
       {12, 14, 16, 18, 20},
       {21, 22, 23, 24, 25}};
  //   vector<vector<int>> m = {{1, 1}};
  cout << s.searchMatrix(m, 11) << endl;
  return 0;
}