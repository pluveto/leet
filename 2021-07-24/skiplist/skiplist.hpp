#include <iostream>
#include <cstdio>
#include <vector>

template <class T>
class skiplist
{
public:
    skiplist();

    T *search(int key);

    void insert(int key);

    bool remove(int key);
};