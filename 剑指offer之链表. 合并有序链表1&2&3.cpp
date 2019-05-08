//链表



/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/


// 合并两个有序链表

class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode *dummy = new ListNode(-1), *cur = dummy;
        while(pHead1 && pHead2) {
            if(pHead1->val < pHead2->val) {
                cur->next = pHead1;
                pHead1 = pHead1->next;
            } else {
                cur->next = pHead2;
                pHead2 = pHead2->next;
            }
            cur = cur->next;
        }
        cur->next = pHead1 ? pHead1 : pHead2;
        return dummy->next;
    }
};



// 合并K个有序链表

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {  
        if (lists.empty()) return NULL;
        int n = lists.size();
        while (n > 1) {
            int k = (n + 1) / 2;
            for (int i = 0; i < n / 2; ++i) {
                lists[i] = mergeTwoLists(lists[i], lists[i + k]);
            }
            n = k;
        }
        return lists[0];
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1), *cur = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (l1) cur->next = l1;
        if (l2) cur->next = l2;
        return dummy->next;
    }
};




Example 1:
Input: 4->2->1->3
Output: 1->2->3->4
Example 2:
Input: -1->5->3->4->0
Output: -1->0->3->4->5

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
问题：对链表排序
方法：归并排序
先用快慢指针法找到链表中部位置，对左右子链表递归处理，进行分割和归并
O(nlogn) O(1)
*/
class Solution
{
public:
    ListNode* sortList(ListNode* head)
    {
        if (!head || !head->next) return head;
       
        ListNode *slow = head, *fast = head, *pre = head;
        while (fast && fast->next)
        {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }//退出循环时，fast或fast->next = nullptr,slow指向中部位置
        pre->next = NULL; //将左右子链表断开处理
       
        return merge(sortList(head), sortList(slow)); //归并左右子链表     
    }
   
    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
      
        ListNode prehead(0); //头结点前面附加一结点（当原链表头结点可能会变化时都可以考虑使用prehead）
        ListNode* p = &prehead; //新链表结点指针
        for(; l1!=nullptr && l2!=nullptr; p = p->next) //比较l1和l2各结点大小，归并
        {
            if(l1->val < l2->val)
            {
                p->next = l1; //下一个结点指向l1结点
                l1 = l1->next;
            }
            else
            {
                p->next = l2;
                l2 = l2->next;
            }
        }
      
        if(l1!=nullptr) p->next = l1; //处理剩余结点
        if(l2!=nullptr) p->next = l2;
        return prehead.next; //返回头结点指针
    }
};
