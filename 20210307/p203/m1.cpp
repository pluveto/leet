#include <util.h>

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
    ListNode *removeElements(ListNode *head, int val)
    {
        while (head && head->val == val)
        {
            head = head->next;
        }
        auto ptr = head;
        while (ptr && ptr->next)
        {
            if (ptr->next->val == val)
                ptr->next = ptr->next->next;
            else
                ptr = ptr->next;
        }
        return head;
    }
};

int main(int argc, char const *argv[])
{
    auto s = new Solution();
    auto l1 = s->removeElements(
        util::createListNode({1, 2, 3, 4, 5, 6, 5, 4, 3, 34, 5}), 5);
    auto l2 = s->removeElements(
        util::createListNode({}), 5);
    auto l3 = s->removeElements(
        util::createListNode({5, 5}), 5);
    auto l4 = s->removeElements(
        util::createListNode({1, 2}), 1);
    util::printListNode(l1);
    util::printListNode(l2);
    util::printListNode(l3);
    util::printListNode(l4);
    return 0;
}
