#include "../inc/util.h"

class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    ListNode *prev = nullptr, *cur = head, *next = head->next;
    while (cur) {
      // 用临时变量保存 cur->next
      next = cur->next;
      // 核心步骤：反转箭头
      cur->next = prev;

      // 迭代步骤
      prev = cur;
      cur = next;
    }
    return prev;
  }
};

int main() {
  Solution s;
  ListNode* l =
      new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
  util::printListNode(l);
  auto r = s.reverseList(l);
  util::printListNode(r);
  return 0;
}
