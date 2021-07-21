// https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

// Solution
class Solution
{
public:
    vector<int> twoSum(vector<int> &v, int target)
    {
        int p = 0, q = v.size() - 1;
        while (p != q)
        {
            int sum = v[p] + v[q];
            if (sum == target)
            {
                return {p , q};
            }
            if (sum > target)
            {
                q--;
            }
            if (sum < target)
            {
                p++;
            }
        }
        return {-1, -1};
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
    Solution s;
    std::vector<int> v = {1, 2, 3, 4, 5};
    auto r = s.twoSum(v, 4);
    _print_vec(r);
    return 0;
}
/**
 
输入：
[2,7,11,15]
9
输出：
[0,1]
预期结果：
[1,2]
*/