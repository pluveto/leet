/**
 * @file m1.cpp
 * @author Pluveto (pluvet@foxmail.com)
 * @brief 暴力解法
 * @version 0.1
 * @date 2021-03-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <vector>
#include <util.h>

using std::vector;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ret;
        int size = nums.size();
        for (int i = 0; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    ret.push_back(i);
                    ret.push_back(j);
                    return ret;
                }
            }
        }
        return {};
    }
};

int main(int argc, char const *argv[])
{
    auto s = new Solution();
    vector<int> v = {2,7,11,15};
    printVec<int>(s->twoSum(v,9));
    return 0;
}
