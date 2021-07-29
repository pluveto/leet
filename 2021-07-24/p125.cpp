#include <iostream>
#include <cstdio>
#include <math.h>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int n = s.size();
        string s2;
        // filter
        for (int i = 0; i < n; i++)
        {
            // not letter
            if (!(
                    ('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z') || ('0' <= s[i] && s[i] <= '9')))
            {
                continue;
            }
            if (s[i] < 'a')
                s2.push_back(s[i] + 32);
            else
                s2.push_back(s[i]);
        }
        //printf("after: %s(%d)\n", s2.c_str(), s2.size());
        int n2 = s2.size();
        for (int i = 0; i < n2 / 2; i++)
        {
            if (s2[i] != s2[n2 - i - 1])
            {
                //printf("%c<->%c", s2[i], s2[n - 1 - i]);
                return false;
            }
        }

        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
     printf("%d\n", s.isPalindrome("ababa"));
     printf("%d\n", s.isPalindrome("abab"));
     printf("%d\n", s.isPalindrome("0p"));
    printf("%d\n", s.isPalindrome("A man, a plan, a canal: Panama"));
    return 0;
}