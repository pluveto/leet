#include <iostream>
#include <cstdio>
#include <vector>

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
    void _process(TreeNode *root, vector<int> &ret)
    {
        if (root == nullptr)
        {
            return;
        }
        ret.push_back(root->val);
        _process(root->left, ret);
        _process(root->right, ret);
    }

public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ret;
        _process(root, ret);
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
    auto r = s.preorderTraversal(t);
    _print_vec(r);
    return 0;
}