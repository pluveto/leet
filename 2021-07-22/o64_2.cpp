#include <cstdio>
#include <stack>

using namespace std;

int indent = 0;

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

stack<int> stk;
int eax, rip, edi, edx;
int sum(int n)
{
func:
    push(stk, n, "n");
    if (n == 0)
    {
        eax = 0;
        goto fin;
    }
    // int a = n;
    eax = pop(stk, "n");
    push(stk, eax, "eax/n");    
    // == callq ==
    /* 
    push   ret_addr
    jmp <func> */
    /* b = sum(n - 1);  */
    eax = pop(stk, "eax/n");
    eax = eax - 1;
    n = eax;
    /* callq  1125 <sum> */
    push(stk, 0x1f, "ret_addr_0x1f");
    auto_indent(indent);printf("call func\n");
    goto func;
ret_addr_0x1f:
    push(stk, eax, "eax");
    auto_indent(indent);printf("return %d\n", eax);    
    /* c = a + b; */
    eax = pop(stk,"eax");
    
    if (stk.empty())
    {
        edx = 1;
    }else{
        
    edx = pop(stk,"n");    
    }
    eax = eax + edx;
    push(stk, eax, "c");
    /* return c; */
    eax = pop(stk, "c");
fin:
    // == leaveq ==
    /* 
    mov   %ebp, %esp
    pop   %ebp */
    if (stk.empty())
    {
        return eax;
    }
    // == retq ==
    /* 
    pop   %rip */
    rip = pop(stk, "rip");
    if (rip == 0x1f)
    {
        goto ret_addr_0x1f;
    }
}

int main()
{
    int a = sum(2);
    printf("%d\n", a);
    return 0;
}
