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


// 延申出一个小知识点：判断链表有环

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr) return false;
        ListNode* fast,*slow;
        slow = fast = head;
       
        while(fast && fast->next) //如果有环，fast不可能为nullptr，无环时，fast会运行到末尾null,退出循环
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) 
                return true;          
        }
        return false;     
    }
};
    

