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
    deque<TreeNode *> pathp;
    deque<TreeNode *> pathq;
    bool foundp = false;
    bool foundq = false;

    deque<TreeNode *> tmpStack;
    // find path of p
    tmpStack.push_back(root);    
    // find paht of q
    while (!tmpStack.empty()) {
      auto top = tmpStack.back();
      // pathp.push_back(top);
      print_deque(tmpStack);
      tmpStack.pop_back();
      if (top == p) {
        break;
      }
      if (top->right) {
        tmpStack.push_back(top->right);
      }
      if (top->left) {
        tmpStack.push_back(top->left);
      }
    }
    print_deque(pathp);
    cout << endl;
    print_deque(pathq);
    TreeNode *outp;
    TreeNode *outq;
    while (!pathp.empty() && !pathq.empty()) {
      if (pathp.front() != pathq.front()) {
        return outq;
      }
      outp = pathp.front();
      outq = pathq.front();
      pathp.pop_front();
      pathq.pop_front();
    }
    return nullptr;
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
  s.lowestCommonAncestor(t, p4, p5);
  return 0;
}