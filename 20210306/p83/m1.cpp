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
        if(head == nullptr){
            return head;
        }
        auto ptr = head;
        while (ptr->next)
        {
            while (ptr->val == ptr->next->val)
            {
                if (ptr->next->next == nullptr)
                {
                    ptr->next = nullptr;
                    return head;
                }
                ptr->next = ptr->next->next;
            }
            ptr = ptr->next;
        }
        return head;
    }
};

int main(int argc, char const *argv[])
{
    auto s = new Solution();
    auto ll = util::createListNode({});
    auto result = s->deleteDuplicates(ll);
    util::printListNode(result);
    return 0;
}
