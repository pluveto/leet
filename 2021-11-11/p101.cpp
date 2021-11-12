#include <binary_tree.h>
#include <debug.h>
class Solution {
public:
  /*
          1
         / \
        2   2
       / \ / \
      3  4 4  3
     /         \
    5           5

  */
  bool mirrorEq(TreeNode *l, TreeNode *r) {
    if (l == nullptr && r == nullptr) {
      return true;
    }
    // 其中一个为 null，则不等
    if (l == nullptr || r == nullptr) {
      return false;
    }
    if (l->val != r->val) {
      return false;
    }
    return mirrorEq(l->left, r->right) && mirrorEq(l->right, r->left);
  }
  bool isSymmetric(TreeNode *root) { return mirrorEq(root->left, root->right); }
};

int main(int argc, char const *argv[]) {
  Solution s;
  int null = -1;
  TreeNode *t =
      // create_tree({1, 2, 2, 3, 4, 4, 3, 5, -1, -1, -1, -1, -1, -1, 5});
      create_tree({1, 2, 2, null, 3, null, 3});
  print_tree(t);
  cout << s.isSymmetric(t) << endl;
  return 0;
}