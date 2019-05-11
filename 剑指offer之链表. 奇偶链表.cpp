// 链表


//方法一
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *pre = head, *cur = head->next;
        while (cur && cur->next) {  //注意这里的转换过程
            ListNode *tmp = pre->next;
            pre->next = cur->next;
            cur->next = cur->next->next;
            pre->next->next = tmp;
            cur = cur->next;
            pre = pre->next;
        }
        return head;
    }
};


//方法二：head、evenhead.两个链表，再拼在一起
class Solution
{
public:
    ListNode* oddEvenList(ListNode* head)
    {
        if(!head) return head;
        ListNode* odd = head; //奇数序列结点指针与头指针
        ListNode* evenhead = head->next,*even = evenhead; //偶数序列结点指针与头指针
       
        while(even && even->next) //偶数序列指针判断(循环时一般用后面的指针来判断是否结束循环) 对于走两步的指针p均需要判断p与p->next是否为空
        {
            odd->next = odd->next->next; //连接奇数序列结点,每次走两步 ，先连接前面的指针
            even->next = even->next->next;//连接偶数序列结点
           
            odd = odd->next; //指向下一个奇结点
            even = even->next;
        }
        odd->next = evenhead; //连接奇序列链表和偶序列链表
        return head;   
    }
};
