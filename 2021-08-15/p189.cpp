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
        k = k % n;
        if (n <= 1 || k == 0)
        {
            return;
        }
        auto tmps = new int[k];
        for (int i = 0; i < k; i++)
        {
            tmps[i] = nums[(n - i) % n];
        }
        for (int i = 0; i <= n - k; i++)
        {
            nums[(n - i) % n] = nums[(n - i - k) % n];
        }

        for (int i = 0; i < k; i++)
        {
            nums[k - i] = tmps[i];
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
    s.rotate(v, 11);
    _print_vec(v);
    vector<int> v2 = {1, 2};
    s.rotate(v2, 2);
    _print_vec(v2);
    return 0;
}