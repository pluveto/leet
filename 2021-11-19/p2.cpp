#include <debug.h>
#include <util.h>
class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    int carry = 0; // 进位标识
    auto ret = l2;
    auto head = ret;
    while (l1 || l2) {
      if (l1 == nullptr) {
        l1 = new ListNode(0);
      }
      if (l2 == nullptr) {
        l2 = new ListNode(0);
      }
      ret->val = l1->val + l2->val + carry;
      carry = 0;
      if (ret->val >= 10) {
        ret->val -= 10;
        carry = 1;
      }
      l1 = l1->next;
      l2 = l2->next;
      if (l1 || l2) {
        ret->next = new ListNode();
        ret = ret->next;
      }
    }
    if(carry){
        ret->next = new ListNode(carry);
    }
    return head;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  //   auto l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
  //   auto l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
  auto l1 = util::createListNode({9,9,9,9,9,9,9});
  auto l2 = util::createListNode({9,9,9,9});
  auto ret = s.addTwoNumbers(l1, l2);
  while (ret != nullptr) {
    cout << ret->val << ",";
    ret = ret->next;
  }
  cout << endl;
  return 0;
}