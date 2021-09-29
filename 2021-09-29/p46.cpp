#include <debug.h>

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        if (nums.size() < 2)
        {
            return {nums};
        }
        vector<vector<int>> results;
        stack<int> stk;
        for (auto i : nums)
        {
            vector<int> rest;
            for (auto j : nums)
            {
                if (j != i)
                {
                    rest.push_back(j);
                }
            }
            auto perms = permute(rest);
            for (auto p : perms)
            {
                p.push_back(i);
                results.push_back(p);
            }
        }

        return results;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::vector<int> vec = {1, 2, 3};
    auto r = s.permute(vec);
    for (auto i : r)
    {
        reverse(i.begin(), i.end());
        print_vec(i);
    }

    return 0;
}