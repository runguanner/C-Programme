/*
1、该树为二叉搜索树
二叉搜索树是排序树，位于左子树点的结点都比父结点小，而位于右子树的结点都比父结点大，只需要从树的根结点开始和两个输入的结点进行比较。
如果当前结点的值比两个结点的值都大，那么最低的公共父结点一定在左子树，下一步就是遍历左子树；
如果当前结点的值比两个结点的值都小，那么最低的公共父结点一定在右子树；下一步就是遍历右子树；
如果当前结点的值介于两个结点的值之间，那么它就是两个结点的公共父结点，第一个找到的就是最低的公共父结点。
2、该树为二叉树，结点中有指向父结点的指针
有了父结点，就可以找到任意结点到根结点的路径；因此：
分别找到从两个结点开始到根结点的路径，即两个链表；
然后找到两个链表的第一个公共结点，就是最低的公共父结点；
3、该树为普通的树
从根结点开始，dfs，分别找到到达两个结点的路径；
然后找到两条路径的最后一个公共结点，就是最低的公共父结点；
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//235. Lowest Common Ancestor of a Binary Search Tree（二叉搜索树）
class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if(!root) return nullptr;
        if(root->val > max(p->val, q->val)) 
            return lowestCommonAncestor(root->left, p, q);
        else if(root->val < min(p->val, q->val))
            return lowestCommonAncestor(root->right, p, q);
        else 
            return root;
    }
};


//Lowest Common Ancestor of a Binary Tree（普通二叉树）
class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if(root == nullptr || p == root || q == root) return root;
        
        TreeNode *left = lowestCommonAncestor(root->left, p, q);//找左子树中是否存在p或q,存在时返回p或q或者p,q的祖先结点，不存在时返回nullptr
        TreeNode *right = lowestCommonAncestor(root->right, p, q);//找右子树中是否存在p或q
        
        if(left && right)//left和right均不为NULL，这表示左右两边可以分别找到p,q则返回root
            return root;
        else 
            return left ? left : right;//left同时有p,q,则left为公共祖先，（若left为空，则right为公共祖先）
    }
};


/*
改进：在找完左子树的共同父节点时如果结果存在，且不是p或q，
那么不用再找右子树了，直接返回这个结果即可，同理，对找完右子树的结果做同样处理，参见代码如下：
*/
class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if(root == nullptr || p == root || q == root) return root;
        
        TreeNode *left = lowestCommonAncestor(root->left, p, q);//找左子树中是否存在p或q,存在时返回p或q或者p,q的祖先结点，不存在时返回nullptr
        if(left && left != p && left != q) return left;
        
        TreeNode *right = lowestCommonAncestor(root->right, p, q);//找右子树中是否存在p或q
        if (right && right != p && right != q) return right;
        
        if(left && right)
            return root;
        else 
            return left ? left : right;
    }
};

