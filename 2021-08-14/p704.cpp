#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int hi = nums.size() - 1;
        int lo = 0;
        while (lo - 1 != hi)
        {
            int mid = (lo + hi) / 2;
            if (nums[mid] < target)
            {
                lo = mid + 1;
            }
            else if (nums[mid] > target)
            {
                hi = mid - 1;
            }
            else{
                return mid;
            }
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums = {-1,0,3,5,9,12};
    int r =s.search(nums, 2);
    printf("%d", r);
    return 0;
}