// 链表


// (1)
// 1->2->2->3 变为 1->3
// 1->1->2->4->5 变为 2->4->5

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead == nullptr || pHead->next == nullptr) return pHead;
        ListNode *dummy = new ListNode(-1), *pre = dummy;
        dummy->next = pHead;  
        while(pre->next) {
            ListNode *cur = pre->next;
            while(cur->next && cur->next->val == cur->val) {
                cur = cur->next;
            }
            if(cur != pre->next) pre->next = cur->next;
            else pre = pre->next;
        }
        return dummy->next;
    }
};


// (2)
// 1->2->2->3 变为 1->2->3
// 1->1->2->4->5 变为 1->2->4->5

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *cur = head;
        while (cur && cur->next) {
            if (cur->val == cur->next->val) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
};
