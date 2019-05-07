// 链表、栈


/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/

//方法：利用"栈"的后进先出特性
//如果可以改变链表结构，则可以先反转链表指针，在遍历输出即可，可以不用辅助空间 （这个地方要学会“反转链表”）

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        stack<ListNode*> nodes;
        ListNode *p = head;
        while(p != nullptr) {
            nodes.push(p);
            p = p->next;
        }
        vector<int> result;
        while(!nodes.empty()) {
            p = nodes.top();
            result.push_back(p->val);
            nodes.pop();
        }
        return result;
    }
};
