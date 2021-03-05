

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
        int size = a.size();
        int max = 0;
        for (int i = 0, j = size - 1; i < j;)
        {
            int n = (j - i) * std::min(a[i], a[j]);
            if (n > max)
            {
                max = n;
            }
            if (a[i] < a[j])
            {
                i++;
                while (a[i] < a[i-1])
                {
                    i++;
                }
            }
            else
            {
                j--;
                while (a[j] < a[j+1])
                {
                    j--;
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
