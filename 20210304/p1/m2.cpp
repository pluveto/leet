/**
 * @file m2.cpp
 * @author Pluveto (pluvet@foxmail.com)
 * @brief 哈希表法
 * @version 0.1
 * @date 2021-03-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <util.h>

using std::unordered_map;
using std::vector;

class Solution
{
public:
    /**
     * @brief 原理是：建哈希表，key 为 nums 中的值，value 为下标。建表之后，寻找 target - nums[i] 的差值的下标即可。
     * 
     * @param nums 
     * @param target 
     * @return vector<int> 
     */
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ret;
        unordered_map<int, int> map;
        int size = nums.size();
        for (int i = 0; i < size; i++)
        {
            auto diff = target - nums[i];
            if (map.count(diff))
            {
                return {i, map[diff]};
            }
            else
            {
                map[nums[i]] = i;
            }
        }
        return {-1, -1};
    }
};

int main(int argc, char const *argv[])
{
    auto s = new Solution();
    vector<int> v = {2, 7, 11, 15};
    printVec<int>(s->twoSum(v, 9));
    return 0;
}
