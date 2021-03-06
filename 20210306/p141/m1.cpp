/**
 * @file m1.cpp
 * @author Pluveto (pluvet@foxmail.com)
 * @brief 思路：（会破坏原链表）：将遍历过的都指向 marker，那么如果正在遍历的也指向 marker，说明成环
 * @version 0.1
 * @date 2021-03-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <util.h>

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == nullptr)
        {
            return false;
        }

        auto marker = (ListNode *)malloc(0);
        auto cur = head;
        ListNode * tmp;
        while (cur->next)
        {
            if (cur->next == marker)
            {
                return true;
            }
            tmp = cur->next;
            cur->next = marker;
            cur = tmp;
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    auto ly = util::createListNode({1, 2, 3, 4});
    ly->next->next->next = ly->next;
    auto ln = util::createListNode({1, 2, 3, 4});

    auto s = new Solution();
    util::printBool(s->hasCycle(ly));
    util::printBool(s->hasCycle(ln));
    util::printBool(util::createListNode({}));

    return 0;
}
