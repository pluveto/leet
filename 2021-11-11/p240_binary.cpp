#include <debug.h>

class Solution {
public:
  // return: hasErr
  bool movedown(vector<vector<int>> &m, int &x, int &y) {
    if (x + 1 == m.size()) {
      return true;
    }
    x++;
    return false;
  }
  // return hasErr
  bool moveleft(vector<vector<int>> &m, int &x, int &y) {
    if (y == 0) {
      return true;
    }
    y--;
    return false;
  }
  bool searchMatrix(vector<vector<int>> &m, int target) {
    if(m.size() == 0){
      return false;
    }
    // 需要注意轴向
    // +--> y
    // |
    // x
    // 以右上角为起始点
    int x = 0, y = m[0].size() - 1;
    bool err = false;
    // 如果 target 大于当前，则向下移动，小于则向左移动，等于则返回
    // true，越界则返回 false
    while (true) {
      if (target > m[x][y]) {
        err = movedown(m, x, y);
      } else if (target < m[x][y]) {
        err = moveleft(m, x, y);
      } else {
        return true;
      }
      if (err) {
        return false;
      }
    }
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  vector<vector<int>> m = {
      {1, 4, 7, 11, 15},    {2, 5, 8, 12, 19},    {3, 6, 9, 16, 22},
      {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30},
  };
  cout << s.searchMatrix(m, 5) << endl;

  m = {{-5}};
  cout << s.searchMatrix(m, -2) << endl;

  m = {{1, 4}, {2, 5}};
  cout << s.searchMatrix(m, 4) << endl;

  m = {{1, 3, 5, 7, 9},
       {2, 4, 6, 8, 10},
       {11, 13, 15, 17, 19},
       {12, 14, 16, 18, 20},
       {21, 22, 23, 24, 25}};
  cout << s.searchMatrix(m, 11) << endl;
  return 0;
}