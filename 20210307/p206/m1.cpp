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
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode *prev, *cur, *tmp;
        prev = nullptr;
        cur = head;
        while (cur)
        {
            printf("cur: %d\n", cur->val);
            tmp = cur->next;
            cur->next = prev;

            prev = cur;
            cur = tmp;
        }
        return prev;
    }
};

int main(int argc, char const *argv[])
{
    auto s = new Solution();
    auto l = s->reverseList(
        util::createListNode({}));
    util::printListNode(l);
    l = s->reverseList(
        util::createListNode({1, 2, 3}));
    util::printListNode(l);
    l = s->reverseList(
        util::createListNode({1, 2, 3, NULL}));
    util::printListNode(l);
    return 0;
}
