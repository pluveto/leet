#include <cstdio>
#include <stack>

using namespace std;

stack<int> s;

void push(stack<int> &s, int v)
{
    s.push(v);
}

int pop(stack<int> &s)
{
    int v = s.top();
    s.pop();
    return v;
}

int sum(int n)
{
    push(s, n);
    int eax, o;
    while (!s.empty())
    {
        o = pop(s);
        eax = eax + o;
        if (o == 0)
            break;
        else
            push(s, o - 1);
    }
    return eax;
}

int main()
{
    int a = sum(100);
    printf("%d\n", a);
    return 0;
}
