#include "../inc/debug.h"

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int buy1 = INT_MAX, buy2 = INT_MAX;
    int sell1 = 0, sell2 = 0;
    for (auto e : prices) {
      // 第一次买的价格越低越好
      buy1 = min(buy1, e);
      // 第一次卖的利润越高越好
      sell1 = max(sell1, e - buy1);
      // 第二次买的价格越低越好。
      // 并且将第一笔交易的利润整合到第二笔买入的成本中，这样第二笔交易的利润就是总利润
      buy2 = min(buy2, e - sell1);
      // 第二次卖的利润越高越好
      sell2 = max(sell2, e - buy2);
    }
    return sell2;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> prices = {10, 9, 2, 8, 3, 7, 4, 6, 5};
  int max = s.maxProfit(prices);
  cout << "max = " << max << endl;

  return 0;
}