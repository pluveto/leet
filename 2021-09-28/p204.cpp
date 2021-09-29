#include <debug.h>

class Solution
{
public:
    // 计数小于 n 的素数
    int countPrimes(int n)
    {
        vector<int> primes;
        bool *not_prime = new bool[n]();
        for (int i = 2; i < n; i++)
        {
            // 如果 i 是素数，则添加到素数列表。
            // 每次添加进来的一定是素数，因为经过筛选之后，非素数的已经在先前的循环标记上了
            if (!not_prime[i])
            {
                primes.push_back(i);
                // printf("i = %d\n", i);
            }
            // 依次遍历各个（可能的）素数
            for (auto p : primes)
            {
                if (p * i >= n) // 避免后面数组越界访问
                {
                    break;
                }
                // 既然 p 是素数，则 p 的 i 倍一定不是素数，所以标记 1
                not_prime[p * i] = 1;
                // i 整除 p，说明 i 不是素数，直接退出，避免重复筛它。
                // 这种方法叫做欧拉筛。
                if (i % p == 0)
                {
                    break;
                }
            }
        }
        delete[] not_prime;
        return primes.size();
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int x = s.countPrimes(2);
    printf("x = %d\n", x);
    return 0;
}