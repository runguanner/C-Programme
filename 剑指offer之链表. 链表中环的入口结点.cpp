// 链表


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
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(pHead == nullptr || pHead->next == nullptr) return nullptr;
        ListNode *slow, *fast, *entry;
        slow = fast = entry = pHead;
        while(fast && fast->next) {  ////如果有环，fast不可能为nullptr，无环时，fast会运行到末尾null,退出循环
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {  //如果有环，找环入口
                while(slow != entry) {
                    slow = slow->next;
                    entry = entry->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};
