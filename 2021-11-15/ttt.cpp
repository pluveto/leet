#include <iostream>
#include <iterator>
#include <queue>
#include <stdio.h>
#include <vector>

using namespace std;

void print_vec(std::vector<int> &vec) {
  if (vec.size() == 0) {
    printf("{}\n");
    return;
  }
  printf("{");
  for (size_t i = 0; i < vec.size(); i++) {
    if (vec[i] == 0)
      printf("O ");
    else if (vec[i] == 1)
      printf("X ");
    else if (vec[i] == 2)
      printf("_ ");
    else
      printf("%d ", vec[i]);
  }
  printf("}\n");
}

void print_vec_2d(std::vector<std::vector<int>> &vec, int indent = 0) {
  if (vec.size() == 0) {
    return;
  }
  for (size_t i = 0; i < vec.size(); i++) {
    printf("  ");
    print_vec(vec[i]);
  }
}
int counter = 0;
class Solution {
public:
  int win(std::vector<std::vector<int>> state) {
    if (state.size() == 0) {
      cout << "err" << endl;
      return 2;
    }
    int winlen = 3;
    // 对角
    for (int turn = 0; turn <= 1; turn++) {
      if (state[0][0] == turn && state[1][1] == turn && state[2][2] == turn) {
        return turn;
      }
    }
    // 反对角
    for (int turn = 0; turn <= 1; turn++) {
      if (state[2][0] == turn && state[1][1] == turn && state[0][2] == turn) {
        return turn;
      }
    }
    for (int y = 0, x = 0; y < state.size() && x < state[0].size();
         y++ && x++) {
      // 十字
      for (int turn = 0; turn <= 1; turn++) {
        if (state[y][x] == turn && state[(y + 1) % winlen][x] == turn &&
            state[(y + 2) % winlen][x] == turn) {
          return turn;
        }
        if (state[y][x] == turn && state[y][(x + 1) % winlen] == turn &&
            state[y][(x + 2) % winlen] == turn) {
          return turn;
        }
      }
    }
    return 2;
  }

  void output_states(deque<std::vector<std::vector<int>>> states) {
    int step = 0;
    while (!states.empty()) {
      if (step > 129) {
        cout << "Your code has bug (T⌓T)" << endl;
        exit(-1);
      }
      auto front = states.front();
      cout << "step " << step++ << endl;
      print_vec_2d(front);
      states.pop_front();
    }
    cout << "over " << endl << endl;
  }

  int rec(deque<std::vector<std::vector<int>>> &history,
          std::vector<std::vector<int>> &state, int turn = 0, int level = 0) {
    if (state.size() == 0) {
      cout << "err" << endl;
      return -1;
    }
    for (int y = 0; y < state.size(); y++) {
      for (int x = 0; x < state[0].size(); x++) {
        if (state[y][x] != 2) {
          continue;
        }
        history.push_back(state);

        auto w = win(state);
        if (w != 2) {
          printf("w = %d\n\n", w);
          output_states(history);
          history.pop_back();
          ++counter;
          return 0;
        }

        std::vector<std::vector<int>> copied(state);
        copied[y][x] = turn;
        rec(history, copied, turn == 1 ? 0 : 1, 1 + level);

        history.pop_back();
      }
    }
    return 0;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  std::vector<std::vector<int>> init = {
      {0, 1, 2},
      {2, 2, 2},
      {2, 2, 2},
  };
  auto history = new deque<std::vector<std::vector<int>>>();
  cout << "player 0 first---" << endl;
  s.rec(*history, init, 0);
  history = new deque<std::vector<std::vector<int>>>();
  cout << "player 1 first---" << endl;
  s.rec(*history, init, 1);
  printf("counter = %d\n", counter);

  return 0;
}