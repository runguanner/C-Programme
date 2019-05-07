// 链表


/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/

//迭代法
//O(n),O(1)

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead == nullptr) return nullptr;
        ListNode *pre = nullptr, *cur = pHead, *next;  //三个指针分别保存之前，当前，下一个结点
        while(cur) {
            next = cur->next;  //保存原链表该结点的下一个结点，以免变换指向之后无法遍历到下一个结点
            cur->next = pre;  //变换指向
            pre = cur;  //更新指针
            cur = next;  //更新指针
        }
        return pre;
    }
};


//递归法
//O(n) O(n)（来自递归栈）

class Solution
{
public:
    ListNode* reverseList(ListNode* head)
    {
        if(head == nullptr || head->next == nullptr) return head;
       
        ListNode* p = reverseList(head->next); //递归之后为从后往前开始转向
        head->next->next = head;
        head->next = nullptr;
        return p;
    }
};



//Follow Up:反转链表中的部分结点

class Solution
{
public:
    ListNode* reverseBetween(ListNode* head, int m, int n)
    {
        //异常情况处理（严格来说，还需判断m,n值是否超出链表长度,题目已经有此条件）
        if(!head || !head->next || m<0 || n<0 || m>=n) return head;
      
        //prehead的应用：头结点前的结点，方便索引，方便分析（链表用1开头+prehead分析较好，序号可以与步数对应起来）
        //且指向了链表的头结点，当m=1时，原头结点被换到后面，若返回head会出错，
        //而用prehead会指向新头结点，故返回prehead.next不会出错
        ListNode prehead(0);
        prehead.next = head;
       
        ListNode* cur = &prehead;
        for(int i = 1; i <= m-1; i++)
            cur = cur->next; //最后cur处在m-1位置
       
        ListNode* pre = cur;
        ListNode* next;
        cur = cur->next; //让cur处在m位置
        ListNode* prefirst = pre, *first = cur; //保存m-1位置和m位置处的结点
       
        for(int i = m; i<=n; i++) //翻转位置m~n处的链表
        {
            next = cur->next;
            cur->next = pre;
           
            pre = cur; //更新指针
            cur = next; //更新指针
        }//退出时，pre在n处，cur在n+1处
       
        prefirst->next = pre; //连接m-1与n位置
        first->next = cur; //连接m与n+1位置
       
        return prehead.next;
    }
};
