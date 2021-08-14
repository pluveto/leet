#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(long long int version);

class Solution
{
private:
    bool isBadVersion(long long int i)
    {
        return i >= 1;
    }

public:
    int firstBadVersion(long long int n)
    {
        // 如果 v 是错误的，则 v...n 都是错误的
        /**
         * 搜索过程 
         * v = very large
         * v = 1000
         * v = 10
         * v = 5
         * v = 2 <- false
         * v = (2+5)/2 = 3 false
         * v = (3+5) / 2 = 4 = false
         * v = (4+5)/2 = 4 =false
         * v = (5+5)/2 = 5 true
         * 
         * 第一阶段：快速下降到首次出现 false
         * 第二阶段：让 v = 
         */
        long long int hi = n;
        long long int lo = 1;
        long long int v = hi;
        while (true)
        {
            v = (lo + hi) / 2;
            if (isBadVersion(v) && !isBadVersion(v - 1))
            {
                break;
            }
            if (isBadVersion(v))
            {
                hi = v - 1;
            }
            else
            {
                lo = v + 1;
            }
        }
        return v;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.firstBadVersion(100);
    return 0;
}