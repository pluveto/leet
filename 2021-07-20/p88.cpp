#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

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

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        for (size_t i = 1; i <= m; i++)
        {
            nums1[m + n - i] = nums1[m - i];
        }
        int p = 0;
        int q = 0;
        int sorted = -1;
        while (!(p == m && q == n))
        {
            if (p == m)
            {
                nums1[++sorted] = nums2[q];
                q++;
                continue;
            }

            if (q == n)
            {
                nums1[++sorted] = nums1[n + p];
                p++;
                continue;
            }

            if (nums1[n + p] <= nums2[q])
            {
                nums1[++sorted] = nums1[n + p];
                p++;
            }
            else
            {
                nums1[++sorted] = nums2[q];
                q++;
            }
        }
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    std::vector<int> v1 = {1, 2, 4, 5, 6, 0}; //{1, 2, 4, 7, 10, 11, 0, 0, 0, 0, 0, 0};
    std::vector<int> v2 = {3};             //{0, 3, 4, 5, 6, 12};
    s.merge(v1, 5, v2, 1);
    _print_vec(v1);
    return 0;
}