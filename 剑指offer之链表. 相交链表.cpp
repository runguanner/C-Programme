// 链表



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 法(1)：设置set<ListNode*> node_set，运用node_set.find()函数
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode *> node_set;  //设置查找集合node_set
        while(headA) {
            node_set.insert(headA);  //将链表A中的节点指针域插入node_set
            headA = headA->next;  //遍历链表A
        }
        while(headB) {
            if(node_set.find(headB) != node_set.end()) {
                return headB;  //当在headB中找到第一个出现在node_set中的节点时
            } 
            headB = headB->next;  //遍历链表B
        }
        return NULL;
    }
};



// 法(2)：设计get_list_length(), *forward_long_list辅助函数

int get_list_length(ListNode *head) {
    int len = 0;
    while(head) {  //遍历链表，计算链表长度
        len++;
        head = head->next;
    }
    return len;
}

ListNode *forward_long_list(int long_len, int short_len, ListNode *head) {
    int delta = long_len - short_len;
    while(head && delta) {
        head = head->next;
        delta--;
    }
    return head;
}

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int list_A_len = get_list_length(headA);
        int list_B_len = get_list_length(headB);  //求A,B两个链表的长度
        if(list_A_len > list_B_len) {
            headA = forward_long_list(list_A_len, list_B_len, headA);
        }
        else {
            headB = forward_long_list(list_B_len, list_A_len, headB);
        }
        while(headA && headB) {
            if(headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};
