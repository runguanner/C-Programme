// 链表



/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/

// 双指针法：先指针cur走k步，若此时cur指向空，说明k为链表的长度，则返回首元素。
// 如果cur存在，我们再继续往下走，此时pre指针也跟着走，直到cur为最后一个元素时停止，此时pre指向要输出元素的前一个元素。
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead == nullptr || k <= 0) return nullptr;
        ListNode *pre = pListHead, *cur = pListHead;
        for(int i = 1; i < k; i++) cur = cur->next;
        if(cur == nullptr) return nullptr;
        while(cur->next) {
            cur = cur->next;
            pre = pre->next;
        }
        return pre;
    }
};
