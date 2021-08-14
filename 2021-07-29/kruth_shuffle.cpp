#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

class Solution
{
public:
    template <class T>
    void shuffle(vector<T> &a)
    {
        for (int i = 0; i < a.size(); i++)
        {
            std::swap<T>(a[i], a[rand() % (i + 1)]);
        } 
    }
};
        
void _print_vec(std::vector<int> &vec)
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

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    Solution s;
    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int counter = 0;
    for (size_t i = 0; i < 10000; i++)
    {
        a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        s.shuffle(a);
        _print_vec(a);
        if (a[0] == 1)
        {
            counter++;
        }
    }
    printf("%d", counter);

    return 0;
}