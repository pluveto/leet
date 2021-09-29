#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>

using namespace std;

#include <stdarg.h>
void debug(const char *fmt, ...)
{
    // return;
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
}

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

class Solution
{
public:
    void findMaxMin(vector<int> &nums, int &max, int &min)
    {
        max = INT_MIN;
        min = INT_MAX;
        int size = nums.size();
        for (int i = 0; i < size; i++)
        {
            if (nums[i] > max)
            {
                max = nums[i];
            }
            if (nums[i] < min)
            {
                min = nums[i];
            }
        }
        // debug("max = %d, min = %d \n", max, min);
    }
    int findGCD(vector<int> &nums)
    {
        int max, min;
        findMaxMin(nums, max, min);
        return gcd(max, min);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::vector<int> vec;
    vec = {2, 3, 4, 6};
    int r = s.findGCD(vec);
    printf("r = %d\n", r);
    return 0;
}