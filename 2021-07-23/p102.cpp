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
    void convert(vector<TreeNode *> &in, vector<int> &out)
    {
        for (auto i : in)
        {
            out.push_back(i->val);
        }
    }

public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ret;
        stack<TreeNode *> stack;
        if (root)
            stack.push(root);
        while (!stack.empty())
        {
            std::stack<TreeNode *> current_level; // 用来暂存当前层的元素
            vector<int> current_level_values; // 用来暂存当前层元素的值
            // 将栈中所有元素逆序放入当前层
            while (!stack.empty())
            {
                current_level.push(pop(stack));
            }
            // 根据每个当前层元素创建下一层的元素到总栈
            while (!current_level.empty())
            {
                auto i = current_level.top();
                current_level.pop();
                current_level_values.push_back(i->val);
                if (i->left)
                    push(stack, i->left);
                if (i->right)
                    push(stack, i->right);
            }
            // 提交当前层的数字
            ret.push_back(current_level_values);
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
     *  /    \
     * 4      5
     */
    TreeNode *t = new TreeNode(
        1,
        new TreeNode( // Left
            2,
            new TreeNode(4),
            nullptr   //
            ),        //
        new TreeNode( // Right
            3,
            nullptr,
            new TreeNode(5) //
            ));

    Solution s;
    auto r = s.levelOrder(t);
    for (size_t i = 0; i < r.size(); i++)
    {
        _print_vec(r[i]);
    }

    return 0;
}