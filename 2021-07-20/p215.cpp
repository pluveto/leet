#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class Solution
{

    void _swap(std::vector<int> &vec, size_t from_i, size_t to_i)
    {
        int tmp = vec[from_i];
        vec[from_i] = vec[to_i];
        vec[to_i] = tmp;
    }

public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int size = nums.size();
        int unsort = size;
        while (unsort != size - k)
        {
            for (size_t i = 0; i < unsort - 1; i++)
            {
                if (nums[i] > nums[i + 1])
                {
                    _swap(nums, i, i + 1);
                }
            }
            // 第1次，找出来最大的，unsort = size - 1，此元素位于 nums[unsort]
            // 第2次，找出来第二大的，unsort = size - 2
            unsort--;
            // 第k次，找出来第k大的，unsort = size - k
        }
        return nums[unsort];
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
    vector<int> v = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int r = s.findKthLargest(v, 4);
    _print_vec(v);
    printf("%d", r);
    return 0;
}