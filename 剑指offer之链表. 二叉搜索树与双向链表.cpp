// 二叉树、链表



/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/

// 中序遍历递归法（左、根、右）

class Solution {
private:
    TreeNode *pre;
    
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == nullptr) return nullptr;
        pre = nullptr;//初始化成员变量,用于记录上一次访问的结点
        convertNode(pRootOfTree);
        TreeNode *head = pRootOfTree;
        while(head->left) head = head->left;
        return head;
    }
    
private:
    void convertNode(TreeNode *cur) {
        if(cur == nullptr) return;
        //转换左子树
        convertNode(cur->left);
        //转换根节点
        cur->left = pre;
        if(pre) pre->right = cur;
        pre = cur;//记录被处理过的结点
        //转换右子树
        convertNode(cur->right);
    }
};



// 中序遍历迭代法


class Solution
{
public:
    TreeNode* Convert(TreeNode* root)
    {
        if(root == nullptr) return nullptr;
        TreeNode* head = root;
        while(head->left) head = head->left; //二叉搜索树中最左子结点即为中序遍历的第一个结点
       
        stack<TreeNode*> s;
        TreeNode* p = root, *pre = nullptr;
        while(p || !s.empty())
        {
            if(p)
            {
                s.push(p);
                p = p->left;
            }
            else
            {
                p = s.top();
                p->left = pre; //连接p与pre
                if(pre) pre->right = p; //连接pre与p
                pre = p; //更新pre
                s.pop();
               
                p = p->right;
            }
        }
        return head;
    }

};
