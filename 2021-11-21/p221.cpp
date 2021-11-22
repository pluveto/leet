#include <debug.h>

typedef struct {
  int top1n; // 上边1个数（算上自己） cur.top1n = cur + dp[i][j-1].top1n
  int left1n; // 左边1个数（算上自己）
  int sqrn;   // 正方形最大大小
} dp_ele, *pdp_ele;

void print_dp(std::vector<std::vector<dp_ele>> &vec, int indent = 0) {
  if (vec.size() == 0) {
    print_indent(indent);
    printf("{}\n");
    return;
  }
  print_indent(indent);
  printf("{\n");
  for (size_t i = 0; i < vec.size(); i++) {
    printf("  ");
    print_indent(indent);
    print_vec(vec[i]);
  }
  print_indent(indent);

  printf("}\n");
}

class Solution {
public:
  int maximalSquare(vector<vector<char>> &mtx) {
    int n = mtx.size();
    int m = mtx[0].size();
    dp_ele default_dp_ele = {0, 0, 0};
    vector<vector<dp_ele>> dp(n, vector<dp_ele>(m, default_dp_ele));

    // 初始化第一行第一列
    dp[0][0] = {mtx[0][0] - '0', mtx[0][0] - '0', mtx[0][0] - '0'};
    for (int j = 1; j < m; j++) {
      dp[0][j] = {mtx[0][j] - '0', mtx[0][j] - '0' + mtx[0][j - 1] - '0',
                  mtx[0][j] - '0'};
    }
    for (int i = 1; i < n; i++) {
      dp[i][0] = {mtx[i - 1][0] - '0' + mtx[i][0] - '0', mtx[i][0] - '0',
                  mtx[i][0] - '0'};
    }
    print_dp(dp);
    for (int i = 1; i < n; i++) {
      for (int j = 1; j < m; j++) {
      }
    }
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  std::vector<std::vector<int>> v = {
      {"1", "0", "1", "0", "0"},
      {"1", "0", "1", "1", "1"},
      {"1", "1", "1", "1", "1"},
      {"1", "0", "0", "1", "0"},
  };
  return 0;
}