#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <unordered_map>

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

void indent_print(int size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf(" ");
    }
}

//template <class T>
void push(std::stack<TreeNode *> &s, TreeNode *value)
{
    indent_print(s.size());
    printf("%d <-\n", value->val);
    s.push(value);
}

//template <class T>
TreeNode *pop(std::stack<TreeNode *> &s)
{
    TreeNode *top = s.top();
    s.pop();
    indent_print(s.size());
    printf("%d ->\n", top->val);
    return top;
}
/* 
while (curr != NULL)
            {
                push(s, curr);
                curr = curr->left;
            }
            curr = pop(s);
            ret.push_back(curr->val);
            curr = curr->right; */
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ret;
        stack<TreeNode *> s;
        TreeNode *curr = root;
        while (curr || !s.empty())
        {
            while (curr)
            {
                push(s, curr);
                curr = curr->left;
            }
            curr = pop(s);
            ret.push_back(curr->val);
            curr = curr->right;
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
     *        / \
     *       7   8
     *     /
     *    9
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
            new TreeNode(
                6,            //
                new TreeNode( //
                    7,
                    new TreeNode(9),
                    nullptr),
                new TreeNode(8) //
                )               //
            )                   //
    );

    Solution s;
    auto r = s.inorderTraversal(t);
    _print_vec(r);
    return 0;
}