#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

static int indent = 0;

void auto_indent(int count)
{
    for (size_t i = 0; i < count; i++)
    {
        printf("  ");
    }
}

void push(stack<int> &s, int v, const char *name)
{
    s.push(v);
    auto_indent(indent);
    printf("%d <- %s\n", v, name);
    indent++;
}

int pop(stack<int> &s, const char *name)
{
    int v = s.top();
    s.pop();
    auto_indent(indent - 1);
    printf("%d -> %s\n", v, name);
    indent--;
    return v;
}
class Solution
{
public:
    void proc(int n, stack<int> &s, int &eax)
    {
        int a = -1, b = -1, ript;
        eax = 0;
        push(s, eax, "eax");
        push(s, 0, "ript");
    proc:
        // 保存被调函数现场        
        if (n == 0)
        {            
            eax = 0;
            // == retq ==
            ript = pop(s, "ript");
            // retq, equiv to `popq %rip`
             // push rip
            if (ript == 0xf1)
            {
                goto rip_f1;
            }
        }
        ript = pop(s, "ript");
        eax = pop(s, "eax");
        push(s, a, "a");
        push(s, b, "b");
        push(s, n, "n");
        // 准备调用函数
        a = n;
        n = n - 1;
    func_call:
        auto_indent(indent);
        printf("\e[1;34mcall proc(n = %d)\n\e[0m", n);
        // == callq ==
        // callq, equiv to `pushq %rip; jmp <proc>`
        push(s, 0xf1, "rip_f1");
        goto proc;
    //proc(n, s, eax);
    rip_f1:
        // 调用完毕，恢复现场
        auto_indent(indent);
        printf("\e[1;34mfunction ret=%d\n\e[0m", eax);
        n = pop(s, "n");
        b = pop(s, "b");
        a = pop(s, "a");
        a = eax;
        eax = n + b;
        push(s, eax, "eax");

    ret:
        // == retq ==
        // retq, equiv to `popq %rip`
        if (s.empty())
        {
            return;
        }
        ript = pop(s, "ript"); // push rip
        if (ript == 0xf1)
        {
            goto rip_f1;
        }
    }
    int sumNums(int n)
    {
        int eax;
        stack<int> *s = new stack<int>();
        proc(n, *s, eax);
        return eax;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    printf("%d\n", s.sumNums(3));
    return 0;
}