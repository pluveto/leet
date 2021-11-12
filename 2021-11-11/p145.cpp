#include <debug.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  vector<int> postorderTraversal(TreeNode *root) {
    if (nullptr == root) {
      return {};
    }
    stack<int> sret;
    // 后序遍历: left right mid，
    // 输出顺序是 lrm，则如果用栈，入栈顺序是 mrl
    stack<TreeNode *> s;
    s.push(root);
    while (!s.empty()) {
      auto out = s.top();
      s.pop();
      sret.push(out->val);
      if (out->left)
        s.push(out->left);
      if (out->right)
        s.push(out->right);
    }
    vector<int> ret;
    while (!sret.empty()) {
      auto out = sret.top();
      sret.pop();
      ret.push_back(out);
    }
    return ret;
  }
};

int main(int argc, char const *argv[]) {
  /**    1
   *    / \
   *   2   3
   *  /\    \
   * 4  5    6
   */
  TreeNode *t = new TreeNode(1,
                             new TreeNode( // Left
                                 2, new TreeNode(4),
                                 new TreeNode(5) //
                                 ),              //
                             new TreeNode(       // Right
                                 3, nullptr,
                                 new TreeNode(6) //
                                 )               //
  );

  Solution s;
  auto r = s.postorderTraversal(t);
  print_vec(r); // assert 4 5 2 6 3 1
  return 0;
}