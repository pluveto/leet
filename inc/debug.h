#include <algorithm>
#include <climits>
#include <cstdarg>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

void debug(const char* fmt, ...) {
  // return;
  va_list args;
  va_start(args, fmt);
  vprintf(fmt, args);
  va_end(args);
}

void _swap(std::vector<int>& vec, size_t from_i, size_t to_i) {
  int tmp = vec[from_i];
  vec[from_i] = vec[to_i];
  vec[to_i] = tmp;
}
template <typename T>
void print_vec(std::vector<T>& vec) {
  if (vec.size() == 0) {
    printf("{}\n");
    return;
  }
  printf("{");
  for (size_t i = 0; i < vec.size() - 1; i++) {
    cout << vec[i] << ", ";
  }
  cout << vec[vec.size() - 1];
  printf("}\n");
}

void print_indent(int count, char c = ' ') {
  for (int i = 0; i < count; i++) {
    cout << c;
  }
}

void print_vec_2d(std::vector<std::vector<int>>& vec, int indent = 0) {
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

void print_vec_part(std::vector<int>& vec, int from, int to) {
  if (vec.size() == 0 || from == to) {
    printf("{}\n");
    return;
  }
  printf("{");
  for (size_t i = from; i < to - 1; i++) {
    printf("%d, ", vec[i]);
  }
  printf("%d", vec[to - 1]);
  printf("}\n");
}

void print_stack(stack<int> s) {
  // print stack from bottom to top
  vector<int> vec;
  while (!s.empty()) {
    vec.push_back(s.top());
    s.pop();
  }
  cout << "[";
  for (size_t i = 0; i < vec.size(); i++) {
    cout << vec[vec.size() - 1 - i] << " ";
  }
  cout << endl;
}

void print_map(map<int, int> m) {
  for (auto it = m.begin(); it != m.end(); it++) {
    cout << "f"
         << "[" << it->first << "]: " << it->second << endl;
  }
}