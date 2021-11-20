#include <binary_tree.h>
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
class Solution {
private:
  int sliceIndexOf(vector<int> &haystack, int ifrom, int ito, int needle) {
    for (int i = ifrom; i <= ito; i++) {
      if (haystack[i] == needle) {
        return i;
      }
    }
    return -1;
  }
  TreeNode *buildTreeFromSlice(vector<int> &inorder, int ifrom, int ito,
                               vector<int> &postorder, int pfrom, int pto) {
    print_vec_part(inorder, ifrom, ito + 1);
    print_vec_part(postorder, pfrom, pto + 1);
    if (ifrom > ito || pfrom > pto) {
      return nullptr;
    }
    if (ifrom == ito) {
      return new TreeNode(inorder[ifrom]);
    }
    if (pfrom == pto) {
      return new TreeNode(postorder[pfrom]);
    }
    TreeNode *root = new TreeNode(postorder[pto]);
    printf("root = %d\n", postorder[pto]);
    int idiv = sliceIndexOf(inorder, ifrom, ito, postorder[pto]); // 分界线
    if (idiv == -1) {
      printf("error idiv not found\n");
      return nullptr; // error
    }
    int len = idiv - ifrom + 1;
    printf("build left \n");
    root->left = buildTreeFromSlice(inorder, ifrom, idiv - 1, postorder, pfrom,
                                    pfrom + len - 2);
    printf("build right \n");
    root->right = buildTreeFromSlice(inorder, idiv + 1, ito, postorder,
                                     pfrom + len - 1, pto - 1);
    return root;
  }

public:
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    int ifrom = 0, ito = inorder.size() - 1, pfrom = 0,
        pto = postorder.size() - 1;
    return buildTreeFromSlice(inorder, ifrom, ito, postorder, pfrom, pto);
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  //   std::vector<int> v1 = {1, 9, 2, 3, 15, 20, 7};
  //   std::vector<int> v2 = {1, 2, 9, 15, 7, 20, 3};
  //   std::vector<int> v1 = {1, 2};
  //   std::vector<int> v2 = {2, 1};
  //   std::vector<int> v1 = {1, 2, 3, 4};
  //   std::vector<int> v2 = {4, 3, 2, 1};
  std::vector<int> v1 = {1, 2, 3, 4};
  std::vector<int> v2 = {3, 2, 4, 1};
  auto ret = s.buildTree(v1, v2);
  print_tree(ret);
  return 0;
}