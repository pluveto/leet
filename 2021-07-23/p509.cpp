#include <cstdio>
#include <stack>

using namespace std;

stack<int> s;

void push(stack<int> &s, int v)
{
    //printf("push %d\n", v);
    s.push(v);
}

int pop(stack<int> &s)
{
    int v = s.top();
    //printf("pop %d\n", v);
    s.pop();
    return v;
}
int fib0(int n)
{
    if (n == 2 || n == 1)
        return 1;
    if (n <= 0)
        return 0;
    return fib0(n - 2) + fib0(n - 1);
}

int fib(int n)
{
    int eax = 0, o;
    push(s, n);
    while (!s.empty())
    {
        o = pop(s);
        if (o == 2 || o == 1)
        {
            eax += 1;
        }
        else if (o <= 0)
        {
            eax += 0;
        }
        else
        {
            push(s, o - 1);
            push(s, o - 2);
        }
    }
    return eax;
}

int main()
{
    int n = 30;
    int a = fib0(n);
    int b = fib0(n);
    printf("%d, expect %d\n", a, b);
    return 0;
}
