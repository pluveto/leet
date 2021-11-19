#include <debug.h>

int step = 0;

class Solution {
public:
  // 返回值：当前状态的 ring 转到 ring[rpos] == key[kpos] 所需的步数。
  // > 0 表示指针正向移动
  // dir: -1 | 1
  int calcStep(string ring, string key, int rpos = 0, int kpos = 0,
               int dir = -1) {
    int nr = ring.size();
    int nk = key.size();
    int step = 0;
    while (ring[rpos] != key[kpos]) {
      step++;
      if (dir > 0) {
        rpos = (rpos + 1) % nr;
      } else {
        rpos = (nr + rpos - 1) % nr;
      }
    }
    return step * dir;
  }
  int findRotateSteps(string ring, string key, int rpos = 0, int kpos = 0) {
    int nr = ring.size();
    int nk = key.size();
    // rpos 圆环的状态
    // key[kpos:nk] 为剩余的 key
    // 对于递归的每一步，只需要负责从对应状态转换到能消除 key[kpos] 的状态
    while (kpos != nk) {
      lstep = calcStep(ring, key, rpos, kpos, 1);
      rstep = calcStep(ring, key, rpos, kpos, -1);
      findRotateSteps(ring, key, rpos, kpos);
      kpos++;
    }
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  string r = "godding";
  string k = "gd";
  s.findRotateSteps(r, k);
  return 0;
}