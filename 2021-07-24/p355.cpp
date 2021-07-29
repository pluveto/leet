#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class Solution
{
private:
    template<class T>
     void _swap(std::vector<T> &vec, size_t from_i, size_t to_i)
    {
        T tmp = vec[from_i];
        vec[from_i] = vec[to_i];
        vec[to_i] = tmp;
    }

public:
    void reverseString(vector<char> &s)
    {
        for (size_t i = 0; i < s.size() / 2; i++)
        {
            _swap(s, i, s.size() - i - 1);
        }
    }
};

void _print_vec(std::vector<char> &vec)
{
    if (vec.size() == 0)
    {
        printf("{}\n");
        return;
    }
    printf("{");
    for (size_t i = 0; i < vec.size() - 1; i++)
    {
        printf("%c, ", vec[i]);
    }
    printf("%c", vec[vec.size() - 1]);
    printf("}\n");
}

int main(int argc, char const *argv[])
{
    Solution s;
    vector<char> str = {'h', 'e', 'l', 'l', 'o'};
    s.reverseString(str);
    _print_vec(str);
    return 0;
}