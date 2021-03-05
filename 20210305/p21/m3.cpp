
#include <stdio.h>
#include <util.h>
using namespace std;

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

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (!(l1 != nullptr && l2 != nullptr))
        {
            return l1 == nullptr ? l2 : l1;
        }
        // select smaller to be the head
        ListNode *head = new ListNode(0);
        auto ptr = head;
        while (ptr)
        {
            if (!(l1 != nullptr && l2 != nullptr))
            {
                ptr->next = l1 == nullptr ? l2 : l1;
                return head->next;
            }
            if (l1->val < l2->val)
            {
                ptr->next = l1;
                l1 = l1->next;
            }
            else
            {
                ptr->next = l2;
                l2 = l2->next;
            }
            ptr = ptr->next;
        }

        return head->next;
    }
};

int main(int argc, char const *argv[])
{
    auto s = new Solution();
    util::printListNode(
        s->mergeTwoLists(
            util::createListNode({1, 2, 4}),
            util::createListNode({1, 3, 4})));
            
    util::printListNode(
        s->mergeTwoLists(
            util::createListNode({}),
            util::createListNode({1, 3, 4})));

    util::printListNode(
        s->mergeTwoLists(
            util::createListNode({}),
            util::createListNode({})));
    return 0;
}
