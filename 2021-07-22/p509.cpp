#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    void _proc(int n, stack<int> &s, int &eax)
    {
        int  a= 0, b = 0;
proc:        
        if (n == 2 || n == 1)
        {
            eax = 1;
            int ripType = s.top(); s.pop(); 
            if(ripType == 0) goto rip0;
            if(ripType == 1) goto rip1;                        
        }
        if (n <= 0)
        {
            eax = 0;
            int ripType = s.top(); s.pop(); 
            if(ripType == 0) goto rip0;
            if(ripType == 1) goto rip1;        
        }
        // 保存上下文        
        s.push(n);  // 保存 n
        s.push(eax);// 保存 eax
        n = n - 2;
        // 调用
        s.push(0); // ripType = 0
        goto proc;     
        rip0:
        // 保存返回值
        a = eax;
        // 恢复上下文
        eax = s.top(); s.pop();
        n   = s.top(); s.pop();
        // 保存上下文
        s.push(a);
        s.push(n);  // 保存 n
        s.push(eax);// 保存 eax
        n = n - 1;
        // 调用
        s.push(1); // ripType = 1
        goto proc;
        rip1:
        // 保存返回值到 b
        b = eax;
        // 恢复上下文
        eax = s.top(); s.pop();        
        n   = s.top(); s.pop();
        a   = s.top(); s.pop();
        eax = a + b;

        return;
    }
    int fib(int n)
    {
        stack<int> s;
        int r;
        _proc(n, s, r);
        return r;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    for (unsigned i = 0; i < 10; ++i)
    {
        printf("%d,", s.fib(i));
    }
    printf("\n");

    return 0;
}