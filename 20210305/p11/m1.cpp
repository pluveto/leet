

#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <util.h>
#include <algorithm>

using std::vector;

class Solution
{
public:
    int maxArea(vector<int> &a)
    {
        // z = (i - j) * min(a[i], a[j])
        int size = a.size();
        int max = INT32_MIN;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                int x = (i - j) * std::min(a[i], a[j]);
                if (x > max)
                {
                    max = x;
                }
            }
        }
        return max;
    }
};
int main(int argc, char const *argv[])
{
    auto s = new Solution();
    vector<int> v = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    printf("%d", s->maxArea(v));
    return 0;
}
