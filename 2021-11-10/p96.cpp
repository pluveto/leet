#include <debug.h>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

void print_indent(int n) {
  for (int i = 0; i < n; i++) {
    printf(" ");
  }
}

void print_tree(TreeNode *t, int ind = 0) {
  print_indent(ind);
  if (t == nullptr) {
    printf("NULL\n");
    return;
  }
  printf("%d\n", t->val);
  print_tree(t->left, ind + 2);
  print_tree(t->right, ind + 2);
}

class Solution {
  // from, to 左闭右开，即不含 to
  TreeNode *slice_to_bst(vector<int> &v, int from, int to) {
    if (from == to) {
      return nullptr;
    }
    auto mid = from + (to - from) / 2;
    auto left = slice_to_bst(v, from, mid);
    auto right = slice_to_bst(v, mid + 1, to);
    return new TreeNode(v[mid], left, right);
  }

public:
  TreeNode *sortedArrayToBST(vector<int> &v) {
    return slice_to_bst(v, 0, v.size());
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  vector<int> v = {-10, -3, 0, 5, 9};
  auto t = s.sortedArrayToBST(v);
  print_tree(t);
  return 0;
}