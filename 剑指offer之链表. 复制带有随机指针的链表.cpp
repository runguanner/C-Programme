// 链表、哈希表


/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/

// 难点在于：把原链表中random指针的逻辑关系在新链表中表示出来（即如何处理随机指针的问题）
// 考虑用Hashmap来建立原链表结点与新链表结点的映射关系，第一遍遍历生成所有新节点时同时建立一个原节点和新节点的哈希表，第二遍给随机指针赋值。
// 即第一遍建立新链表中next指针的关系，第二遍建立新链表中random指针的关系。

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(!pHead) return NULL;
        RandomListNode *res = new RandomListNode(pHead->label);
        RandomListNode *node = res;
        RandomListNode *cur = pHead->next;
        map<RandomListNode *, RandomListNode *> m;  //结点的对应关系既包括next指针的关系，也包括random指针的关系
        m[pHead] = res;
        while(cur) {  //（1）拷贝next指针关系，并建立random指针关系
            RandomListNode *tmp = new RandomListNode(cur->label);
            node->next = tmp;
            m[cur] = tmp;  //建立关系
            cur = cur->next;
            node = node->next;
        }
        node = res;  //分别回到原、新链表表头
        cur = pHead;
        while(node) {  //（2）拷贝random指针关系
            node->random = m[cur->random];  //运用关系
            node = node->next;
            cur = cur->next;
        }
        return res;
    }
};


// 方法（2）：在原链表内部复制链表结点，由内部关系，复制随机指针连接关系，再进行拆分
class Solution
{
public:
    RandomListNode *copyRandomList(RandomListNode *head)
    {
        //第一步：复制结点与next指针
        RandomListNode* cur = head;
        while(cur != nullptr)
        {
            RandomListNode* node = new RandomListNode(cur->label); //构造函数会将next和random指针赋值为null
            node->next = cur->next;//新结点与旧结点连接 
           
            cur->next = node; //旧结点与新结点连接
            cur = node->next; //下个旧结点
        }
       
        //第二步：复制random指针
        cur = head;
        while(cur != nullptr)
        {
            if(cur->random != nullptr) cur->next->random = cur->random->next; //复制random指针 (cur->next为新结点)
            cur = cur->next->next; //下个旧结点
        }
       
        //第三步：拆分链表
        cur = head;
        RandomListNode prehead(0); //创建整个链表的空头结点,方便处理
        prehead.next = head;
        RandomListNode* newcur = &prehead;
        while(cur != nullptr)
        {
            newcur->next = newcur->next->next;//先连接前面的指针，类似题目 328. Odd Even Linked List

            cur->next = cur->next->next;

            
            newcur = newcur->next; //更新指针
            cur = cur->next; //cur走在newcur前面，方便判断  
        }
        return prehead.next;
    }
};


