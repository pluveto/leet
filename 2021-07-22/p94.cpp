#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// Solution
class Solution
{
private:
    void _process(TreeNode *root, vector<int> &ret, stack<TreeNode *> &callstack)
    {
        while (!(root == nullptr && callstack.empty()))
        {
            if (root != nullptr)
            {
                callstack.push(root);
                root = root->left;
            }
            else if (!callstack.empty())
            {
                root = callstack.top();
                callstack.pop();
                ret.push_back(root->val);
                root = root->right;
            }
        }
    }

public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ret;
        stack<TreeNode *> stack;
        while (!(root == nullptr && stack.empty()))
        {
            if (root != nullptr)
            {
                stack.push(root);
                root = root->left;
            }
            else if (!stack.empty())
            {
                root = stack.top();
                stack.pop();
                ret.push_back(root->val);
                root = root->right;
            }
        }
        return ret;
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ret;
        std::stack<TreeNode *> stack;
        if (nullptr != root)
            stack.push(root);
        while (stack.size())
        {
            auto out = stack.top();
            ret.push_back(out->val);
            stack.pop();
            if (nullptr != out->right)
                stack.push(out->right);
            if (nullptr != out->left)
                stack.push(out->left);
        }

        return ret;
    }
};

void _print_vec(std::vector<int> &vec)
{
    if (vec.size() == 0)
    {
        printf("{}\n");
        return;
    }
    printf("{");
    for (size_t i = 0; i < vec.size() - 1; i++)
    {
        printf("%d, ", vec[i]);
    }
    printf("%d", vec[vec.size() - 1]);
    printf("}\n");
}

int main(int argc, char const *argv[])
{
    /**    1
     *    / \
     *   2   3
     *  /\    \
     * 4  5    6
     */
    TreeNode *t = new TreeNode(
        1,
        new TreeNode( // Left
            2,
            new TreeNode(4),
            new TreeNode(5) //
            ),              //
        new TreeNode(       // Right
            3,
            nullptr,
            new TreeNode(6) //
            )               //
    );

    Solution s;
    auto r = s.inorderTraversal(t);
    _print_vec(r);
    return 0;
}