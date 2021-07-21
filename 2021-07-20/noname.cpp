#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int count[3] = {0, 0, 0};
        for (int i = 0; i < nums.size(); i++)
            count[nums[i]]++;
        int c = 0;
        for (int i = 0; i < 3; i++)
            for (size_t j = 0; j < count[i]; j++)
                nums[c++] = i;
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
    std::vector<int> v = {2, 0, 2, 1, 1, 0};
    s.sortColors(v);
    _print_vec(v);
    return 0;
}