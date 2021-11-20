#include <iostream>
#include <string>
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

#include <cstdio>
#include <vector>
using namespace std;
TreeNode *create_tree(vector<int> v, int i = 0) {
  if (i >= v.size()) {
    return nullptr;
  }
  if (v[i] == -1) {
    return nullptr;
  }
  auto current = new TreeNode(v[i]);
  
  auto i_left = 2 * i + 1;
  auto i_right = 2 * i + 2;
  current->left = create_tree(v, i_left);
  current->right = create_tree(v, i_right);
  return current;
}


// void print_tree(TreeNode *t, int ind = 0) {
//   print_indent(ind);
//   if (t == nullptr) {
//     printf("NULL\n");
//     return;
//   }
//   printf("%d\n", t->val);
//   print_tree(t->left, ind + 2);
//   print_tree(t->right, ind + 2);
// }

void print_tree(TreeNode *node, bool isLeft = false, std::string prefix = "") {
  if (node != nullptr) {
    std::cout << prefix;
    std::cout << (isLeft ? "├──" : "└──");
    // print the value of the node
    std::cout << node->val << std::endl;
    // enter the next tree level - left and right branch
    print_tree(node->left, true, prefix + (isLeft ? "│   " : "    "));
    print_tree(node->right, false, prefix + (isLeft ? "│   " : "    "));
  }
}