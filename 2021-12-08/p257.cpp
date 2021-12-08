#include <stdlib.h>

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
  vector<string> binaryTreePaths(TreeNode *root) {
    vector<string> ret;
    
    sprintf(__s, "%d", root->val);
    ret.push_back();
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
  s.binaryTreePaths(t);
  return 0;
}