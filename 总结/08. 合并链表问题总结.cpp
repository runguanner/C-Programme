//21. Merge Two Sorted Lists 合并两个链表
class Solution {
public:
    ListNode *mergeTwoList(ListNode *l1, ListNode *l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;

        ListNode prehead(0);
        ListNode *p = &prehead;
        for( ; l1 != nullptr && l2 != nullptr; p = p->next) {
            if(l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
        }

        if(l1 != nullptr) p->next = l1;
        if(l2 != nullptr) p->next = l2;
        return prehead.next;
    }
};


//23. Merge k Sorted Lists （hard） 合并多个链表（运用到合并两个）
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        while(lists.size() > 1) {
            int len = lists.size();
            for(int i = 0; i < len / 2; i++) {//改进为不断二分归并，归并次数可以减少为n/2 + n/4 + ... +1
                lists[i] = mergeTwoLists(lists[i], lists[len - i - 1]);
            }
            lists.resize((len + 1) / 2);
        }
        return lists[0];
    }

private:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;

        ListNode preHead(0);
        ListNode *p = &preHead;
        for( ; l1 != nullptr && l2 != nullptr; p = p->next) {
            if(l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
        }
        if(l1 != nullptr) p->next = l1;
        if(l2 != nullptr) p->next = l2;
        return preHead.next;
    }
};


//Sort List（对链表排序的方法：归并排序：先用快慢指针法找到链表中部位置，对左右子链表递归处理，进行分割和归并）（运用到合并两个链表）
//归并排序：O(nlogn) O(1)
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if(!head || !head->next) return head;
        ListNode *slow = head, *fast = head, *pre = head;
        while(fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }//退出循环时，fast或fast->next = nullptr,slow指向中部位置
        pre->next = NULL;//将左右子链表断开处理
        return merge(sortList(head), sortList(slow));//归并左右子链表
    }

    ListNode *merge(ListNode *l1, ListNode *l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;

        ListNode preHead(0);
        ListNode *p = &preHead;

        for( ; l1 != nullptr && l2 != nullptr; p = p->next) {
            if(l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
        }
        if(l1 != nullptr) p->next = l1;
        if(l2 != nullptr) p->next = l2;
        return preHead.next;
    }
};



