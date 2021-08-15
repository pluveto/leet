#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n <= 1)
        {
            return;
        }
        for (size_t j = 0; j < k; j++)
        {
            int tmp = nums[0];
            for (int i = 0; i <= n - 1; i++)
            {
                nums[(n - i) % n] = nums[(n - i - 1) % n];
            }
            nums[1] = tmp;
        }
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
    vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    for (size_t i = 0; i < v.size(); i++)
    {
        _print_vec(v);
        s.rotate(v, 2);
    }

    return 0;
}