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

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ret;
        queue<TreeNode *> q; // 总队列
        if (!root)
        {
            return ret;
        }
        q.push(root);
        while (!q.empty())
        {
            std::queue<TreeNode *> level_queue = q; // 此队列用于暂存当前层
            vector<int> level_values;               // 此队列用于暂存当前层的值
            // 清空 q，只放下面一层的了
            while (!q.empty())
                q.pop();
            // 把下一层的值有序送入 q
            while (!level_queue.empty())
            {
                auto front = level_queue.front();
                level_queue.pop();
                level_values.push_back(front->val);
                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
            }
            ret.push_back(level_values); // 提交当前层的值
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