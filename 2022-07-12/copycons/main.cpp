#include <chrono>
#include <iostream>

template <int N>
void show() {
  for (int i = 0; i < N; i++) {
    std::cout << i << " ";
  }
}

int main() {  
  show<1>();
  std::cout << std::endl;
  return 0;
}
