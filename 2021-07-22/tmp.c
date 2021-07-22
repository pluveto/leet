#include <stdio.h>
int sum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    int a = n;
    int b = sum(n - 1);
    int c = a + b;
    return c;
}

int main()
{
    int a = sum(3);
    printf("%d\n", a);
    return 0;
}
