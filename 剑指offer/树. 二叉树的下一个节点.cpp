//分清楚三种情况就OK了。
//【1】、有右子树时，下个结点就是它右子树的最左子结点
//【2】、没有右子树时，下个结点就是父结点（当前结点为左孩子时）或者 【3】向上遍历，以遍历到的结点为左孩子的父结点




/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode == nullptr) return nullptr;
        if(pNode->right) {//有右子树时，下个结点就是它右子树的最左子结点【1】
            pNode = pNode->right;
            while(pNode->left != nullptr) pNode = pNode->left;
            return pNode;
        }
        else {//没有右子树时，下个结点就是父结点（当前结点为左孩子时）或者向上遍历，以遍历到的结点为左孩子的父结点
            while(pNode->next) {
                if(pNode->next->left == pNode) return pNode->next;//若当前节点为父结点的左结点，则父结点就是下一个结点【2】
                else pNode = pNode->next;//往上查找，直到当前结点为父结点的左结点【3】
            }
            return nullptr;
        }
    }
};
