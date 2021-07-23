#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>

#include <cstring>

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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        int level = 0;
        queue<TreeNode *> q;
        if (root)
            q.push(root);
        while (!q.empty())
        {
            int level_size = q.size();
            while (level_size)
            {
                auto o = q.front();
                q.pop();
                if (o->left)
                    q.push(o->left);
                if (o->right)
                    q.push(o->right);
                level_size--;
            }
            level++;
        }
        return level;
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
    auto r = s.maxDepth(t);
    printf("%d", r);

    return 0;
}