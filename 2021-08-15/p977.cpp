#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        auto out = vector<int>(nums.size());
        int lo = 0;
        int hi = nums.size() - 1;
        if (-1 == hi)
        {
            return out;
        }
        int ins = hi;
        while (lo != hi + 1)
        {
            if (abs(nums[hi]) > abs(nums[lo]))
            {        
                out[ins] = nums[hi] * nums[hi];
                hi--;
                ins--;
            }
            else
            {        
                out[ins] = nums[lo] * nums[lo];
                lo++;
                ins--;
            }
        }
        return out;
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
    std::vector<int> vec = {-5, -3, -2, -1, 2};
    _print_vec(vec);

    auto a = s.sortedSquares(vec);
    _print_vec(a);
    return 0;
}