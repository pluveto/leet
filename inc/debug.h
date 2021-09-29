#include <stdio.h>
#include <stdarg.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>
#include <iterator>

using namespace std;

void debug(const char *fmt, ...)
{
    // return;
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
}

void _swap(std::vector<int> &vec, size_t from_i, size_t to_i)
{
    int tmp = vec[from_i];
    vec[from_i] = vec[to_i];
    vec[to_i] = tmp;
}

void print_vec(std::vector<int> &vec)
{
    if (vec.size() == 0)
    {
        printf("{}\n");
        return;
    }
    printf("{");
    for (size_t i = 0; i < vec.size() - 1; i++)
    {
        printf("%d, ", vec[i]);
    }
    printf("%d", vec[vec.size() - 1]);
    printf("}\n");
}