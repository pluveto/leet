#include <iostream>
class my_class {
 public:
  int member_a;
  int member_b[512];
};

my_class create_obj() {
  my_class obj;
  obj.member_a = 1;
  obj.member_b[0] = 2;
  obj.member_b[sizeof(obj.member_b) /( sizeof(decltype(obj.member_b))) - 1] = 2;
  return obj;
}

int main() {
  my_class obj = create_obj();
  std::cout << "obj" << std::endl;
  std::cout << "-----------------" << std::endl;
  std::cout << "obj.member_a: " << obj.member_a << std::endl;
  auto length = sizeof(obj.member_b) /( sizeof(decltype(obj.member_b[0])));
  std::cout << "obj.member_b(length=" << length << "): " << std::endl;
  for (size_t i = 0; i < length; i++) {
    std::cout << "idx   val = " << i << "\t" << obj.member_b[i] << std::endl;
  }
  return 0;
}
