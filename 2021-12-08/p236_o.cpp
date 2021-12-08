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

void print_deque(deque<TreeNode *> t) {
  auto cur = t.begin();
  while (cur != t.end()) {
    cout << (*cur)->val << ", ";
    cur++;
  }
  cout << endl;
}

class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == nullptr) {
      return nullptr;
    }
    if (root == p || root == q) {
      return root;
    }
    // case 1: one in left, another in right
    auto left = lowestCommonAncestor(root->left, p, q);
    auto right = lowestCommonAncestor(root->right, p, q);
    if (left && right) {
      return root;
    }
    // case 2: both in the same side
    auto side = left ? left : right;
    return lowestCommonAncestor(side, p, q);
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  /**    1
   *    / \
   *   2   3
   *  /\    \
   * 4  5    6
   */
  auto p4 = new TreeNode(4);
  auto p5 = new TreeNode(5);
  TreeNode *t = new TreeNode(1,
                             new TreeNode( // Left
                                 2, p4,
                                 p5        //
                                 ),        //
                             new TreeNode( // Right
                                 3, nullptr,
                                 new TreeNode(6) //
                                 )               //
  );
  auto ret = s.lowestCommonAncestor(t, p4, p5);
  cout << ret->val << endl;
  return 0;
}