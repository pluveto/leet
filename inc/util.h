#include <vector>
#include <iostream>
#include <stdio.h>

using std::vector;

template <class T>
void printVec(vector<T> v)
{
    int size = v.size();
    std::cout << "[";
    for (int i = 0; i < size; i++)
    {
        std::cout << v[i] << (size == i + 1 ? "]\n" : ", ");
    }
}
