// 链表



/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        int len1 = findListLength(pHead1);
        int len2 = findListLength(pHead2);
        
        ListNode *pLong = pHead1, *pShort = pHead2;
        if(len1 < len2) {
            pShort = pHead1;
            pLong = pHead2;
        }
        
        for(int i = 1; i <= abs(len1 - len2); i++) pLong = pLong->next;  //较长的链表多走几步
        while(pShort != pLong) {  //同时步进，直到遇到相同结点或者均遇到尾结点
            pLong = pLong->next;
            pShort = pShort->next;
        }
        return pLong;
    }
    
private:
    int findListLength(ListNode *p) {
        int n = 0;
        while(p != nullptr) {
            p = p->next;
            n++;
        }
        return n;
    }
};
