#include <debug.h>
#include <cmath>

class Solution
{
public:
    int order(std::vector<int> &vec)
    {
        int ret = 0;
        int n = vec.size();
        for (unsigned i = 0; i < vec.size(); ++i)
        {
            ret += vec[i] * (int)tgamma(i + 1);
            printf("i = %d\n", i);
            printf("vec[i] = %d\n", vec[i]);
            printf("tgamma(i) = %d\n", (int)tgamma(i + 1));
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::vector<int> v = {3, 5, 7, 4, 1, 2, 9, 6, 8};
    auto x = s.order(v);
    printf("x = %d\n", x);
    return 0;
}