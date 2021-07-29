#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        short map[26] = {0};
        for (char c : s)
        {
            map[c - 'a']++;
        }
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if(map[s[i] - 'a'] == 1){
                return i;
            }
        }
        return -1;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    printf("%d", s.firstUniqChar("ffuckyou"));
    return 0;
}