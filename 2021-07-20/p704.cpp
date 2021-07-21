#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int lo = 0;
        int hi = nums.size() - 1;
        int mid;
        while (lo != hi + 1)
        {
            mid = (lo + hi) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        return - 1;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    std::vector<int> vec = {-1, 0, 3, 5, 9, 12};
    printf("%d", s.search(vec, 9));
    return 0;
}