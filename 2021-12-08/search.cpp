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

void print_stack(stack<TreeNode *> &t) {
  if (t.empty()) {
    printf("\n");
    return;
  }
  auto top = t.top();
  t.pop();
  print_stack(t);
  t.push(top);
  printf("%d, ", top->val);
}

class Solution {
public:
  void FindPathImpl(stack<TreeNode *> &history, TreeNode *root,
                    TreeNode *target, bool &over) {
    if (over) {
      return;
    }
    history.push(root);
    if (root == nullptr) {
      return;
    }
    if (root == target) {
      over = true;
      return;
    }
    FindPathImpl(history, root->left, target, over);
    if (over) {
      return;
    } else {

      history.pop();
    }
    FindPathImpl(history, root->right, target, over);
    if (over) {
      return;
    } else {

      history.pop();
    }
  }
  deque<TreeNode *> FindPath(TreeNode *root, TreeNode *target) {
    stack<TreeNode *> history;
    bool found = false;
    FindPathImpl(history, root, target, found);
    // reverse
    deque<TreeNode *> ret;
    while (!history.empty()) {
      auto top = history.top();
      history.pop();
      ret.push_back(top);
    }
    return ret;
  }
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    auto sp = this->FindPath(root, p);
    print_deque(sp);
    auto sq = this->FindPath(root, q);
    print_deque(sq);
    auto prev = sp.back();
    while (!sp.empty() && !sq.empty()) {
      if (sp.back() != sq.back()) {
        return prev;
      }
      prev = sp.back();
      sp.pop_back();
      sq.pop_back();
    }
    return prev;
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
  // auto p4 = new TreeNode(4);
  // auto p5 = new TreeNode(5);
  // TreeNode *t = new TreeNode(1,
  //                            new TreeNode( // Left
  //                                2, p4,
  //                                p5        //
  //                                ),        //
  //                            new TreeNode( // Right
  //                                3, nullptr,
  //                                new TreeNode(6) //
  //                                )               //
  // );
  // auto pathp = s.FindPath(t, p4);
  // print_stack(pathp);
  // auto pathq = s.FindPath(t, p5);
  // print_stack(pathq);
  // cout << endl;
  // cout << s.lowestCommonAncestor(t, p4, p5)->val << endl;
  auto node4 = new TreeNode(4);
  auto node5 = new TreeNode(5,
                            new TreeNode(6),              //
                            new TreeNode(2,               //
                                         new TreeNode(7), //
                                         node4            //
                                         )                //
  );
  auto t = new TreeNode(3,
                        node5,                        //
                        new TreeNode(1,               //
                                     new TreeNode(0), //
                                     new TreeNode(8)  //
                                     )                //
  );
  auto t2n4 = new TreeNode(4);
  auto t2 = new TreeNode(1,                    //
                         new TreeNode(2,       //
                                      nullptr, //
                                      t2n4     //
                                      ),       //
                         new TreeNode(3)       //
  );
  cout << s.lowestCommonAncestor(t, node5, node4)->val << endl;
  // cout << s.lowestCommonAncestor(t2, t2, t2n4)->val << endl;
  return 0;
}