/**
 * @file m2.cpp
 * @author Pluveto (pluvet@foxmail.com)
 * @brief 利用快慢指针寻找中间点，对后半逆序，然后比较是否相同。
 * @version 0.1
 * @date 2021-03-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */
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
        //util::printListNode(head);

        if (nullptr == head || nullptr == head->next)
        {
            return true;
        }
        ListNode *preCenter, *center;
        bool odd;
        this->findCenter(head, preCenter, center, odd);
        printf("odd=%d\n", odd);

        preCenter->next = nullptr;
        // reverse list after center
        auto subHead = odd ? center->next : center;
        ListNode *prev = nullptr, *cur = subHead, *tmp;
        while (cur)
        {
            // printf("cur: %d\n", cur->val);

            tmp = cur->next;
            cur->next = prev;

            prev = cur;
            cur = tmp;
        }
        //util::printListNode(prev);
        //util::printListNode(head);
        //util::printBool(this->isSame(prev, head));
        
        return this->isSame(head,prev);
    }
    
    bool isSame(ListNode *l1, ListNode *l2)
    {
        auto p1 = l1, p2 = l2;
        while (p1)
        {
            if (p1 == nullptr && p2 != nullptr)
            {
                return false;
            }
            if (p1 != nullptr && p2 == nullptr)
            {
                return false;
            }
            if (p1->val != p2->val)
            {
                return false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
    }
    void findCenter(ListNode *head, ListNode *&pre, ListNode *&center, bool &odd)
    {
        auto slow = head;
        auto fast = head;
        odd = false;
        while (fast)
        {
            if (fast->next == nullptr)
            {
                odd = true;
                break;
            }
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        center = slow;
    }
};

int main(int argc, char const *argv[])
{
    auto s = new Solution();

    util::printBool(
        s->isPalindrome(
            util::createListNode({})));
    util::splitLine();
    util::printBool(
        s->isPalindrome(
            util::createListNode({1})));
    util::splitLine();
    util::printBool(
        s->isPalindrome(
            util::createListNode({1, 2, 3})));
    util::splitLine();
    util::printBool(
        s->isPalindrome(
            util::createListNode({1, 2, 1})));
    util::splitLine();
    util::printBool(
        s->isPalindrome(
            util::createListNode({1, 2, 2, 1})));
    util::splitLine();
    util::printBool(
        s->isPalindrome(
            util::createListNode({1, 2, 3, 4, 3, 2, 1})));
    return 0;
}
