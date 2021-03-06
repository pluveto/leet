/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <util.h>
using namespace std;
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        auto ptr = head;
        while (ptr && ptr->next)
        {
            if (ptr->val == ptr->next->val)
            {
                ptr->next = ptr->next->next;
            }
            else
            {
                ptr = ptr->next;
            }
        }
        return head;
    }
};

int main(int argc, char const *argv[])
{
    auto s = new Solution();
    util::printListNode(s->deleteDuplicates(
        util::createListNode({})));
    util::printListNode(s->deleteDuplicates(
        util::createListNode({1, 1})));
    util::printListNode(s->deleteDuplicates(
        util::createListNode({1, 1, 2, 3, 3, 4, 4})));
    return 0;
}
