#include <debug.h>
#include <map>
class Solution {
public:
  void shortest_path(map<pair<int, int>, int> dis, int start, int end) {}
};

int main(int argc, char const *argv[]) {
  Solution s;
  map<pair<int, int>, int> dis = {
      {{0, 1}, 4}, {{1, 2}, 8}, {{2, 3}, 7}, {{3, 4}, 9},  {{4, 5}, 10},
      {{5, 6}, 2}, {{6, 7}, 1}, {{0, 7}, 8}, {{1, 7}, 11}, {{7, 8}, 7},
      {{6, 8}, 6}, {{2, 8}, 2}, {{2, 5}, 4}, {{3, 5}, 14}};
  int start = 0;
  int end = 8;
  s.shortest_path(dis, start, end);
  return 0;
}