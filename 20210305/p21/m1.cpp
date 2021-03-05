
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
        if (l1 == nullptr && l2 == nullptr)
        {
            return nullptr;
        }
        if (l1 != nullptr && l2 == nullptr)
        {
            return l1;
        }
        if (l1 == nullptr && l2 != nullptr)
        {
            return l2;
        }
        // select smaller to be the head
        ListNode *head;        
        if (l1->val < l2->val)
        {
            head = l1;
            l1 = l1->next;
        }
        else
        {
            head = l2;
            l2 = l2->next;
        }

        auto ptr = head;
        while (ptr)
        {
            if(l1 == nullptr && l2 == nullptr){
                return head;
            }
            if (l1 == nullptr && l2 != nullptr)
            {
                ptr->next = l2;
                return head;
            }
            if (l2 == nullptr && l1 != nullptr)
            {
                ptr->next = l1;
                return head;
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

        return head;
    }
};

int main(int argc, char const *argv[])
{
    auto s = new Solution();
    util::printListNode(
        s->mergeTwoLists(
            util::createListNode({1,2,4}),
            util::createListNode({1,3,4})));
    return 0;
}
