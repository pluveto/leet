#include <util.h>
#include <stdlib.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        auto tmp = node->next;
        node->val = tmp->val;
        node->next = tmp->next;
        //free(tmp);
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
