#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int hi = nums.size() - 1;
        int lo = 0;
        int mid;
        while (hi + 1 != lo)
        {
            mid = lo + (hi - lo) / 2;
            printf("%d\n", mid);
            if (nums[mid] == target)
            {
                printf("found\n");
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
        printf("not found %d %d\n", lo, hi);
        return lo;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> v = {1, 3, 5, 6};
    int r = s.searchInsert(v, 2);

    printf("%d", r);

    return 0;
}