#include <util.h>
#include <unordered_map>
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
    bool isPalindrome(ListNode *head)
    {
        auto p = head;
        if (p == nullptr || p->next == nullptr)
        {
            return true;
        }
        return this->isSame(this->reverse(head), head);
    }
    ListNode *reverse(ListNode *head)
    {
        auto l1c = head;
        ListNode *prevprev = nullptr;
        while (l1c)
        {
            ListNode *prev = new ListNode(l1c->val);
            prev->next = prevprev;
            prevprev = prev;
            l1c = l1c->next;
        }
        return prevprev;
    }
    bool isSame(ListNode *l1, ListNode *l2)
    {
        auto l1c = l1;
        auto l2c = l2;
        while (l1c)
        {
            if (l1c->val != l2c->val)
            {
                return false;
            }
            l2c = l2c->next;
            l1c = l1c->next;

            if (l1c == nullptr && l2c != nullptr)
            {
                return false;
            }
            if (l1c != nullptr && l2c == nullptr)
            {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    auto s = new Solution();
    util::printBool(
        s->isSame(
            util::createListNode({1, 2, 3}),
            util::createListNode({1, 2, 3})));
    util::printBool(
        s->isSame(
            util::createListNode({1, 2, 3, 4}),
            util::createListNode({1, 2, 3})));
    util::printBool(
        s->isSame(
            util::createListNode({1}),
            util::createListNode({1})));
    util::printBool(
        s->isSame(
            util::createListNode({}),
            util::createListNode({})));
    util::printBool(
        s->isPalindrome(
            util::createListNode({})));
    util::printBool(
        s->isPalindrome(
            util::createListNode({1})));
    util::printBool(
        s->isPalindrome(
            util::createListNode({1, 2, 3})));
    util::printBool(
        s->isPalindrome(
            util::createListNode({1, 2, 1})));
    util::printBool(
        s->isPalindrome(
            util::createListNode({1, 2, 2, 1})));
    return 0;
}
