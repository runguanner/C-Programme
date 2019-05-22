/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
/*
对于每一个节点，我们通过checkDepth方法递归获得左右子树的深度，
如果子树是平衡的，则返回真实的深度，若不平衡，直接返回-1，
此方法时间复杂度O(N)，空间复杂度O(H)

 
对于用递归求解的题，可以画递归树来分析
*/
class Solution
{
public:   
    bool isBalanced(TreeNode *root)
    {
        if (checkDepth(root) == -1) return false;
        else return true;
    }
   
    //类似问题：104. Maximum Depth of Binary Tree：即求树的深度
    int checkDepth(TreeNode *root)
    {
        if (!root) return 0; //为空时，返回深度0 
       
        int left = checkDepth(root->left); //返回左子树的深度，如果不平衡，返回-1
        if (left == -1) return -1; //只要哪里有-1一路返回，直到递归结束
       
        int right = checkDepth(root->right); //返回右子树的深度
        if (right == -1) return -1;
       
        int diff = abs(left - right); //计算左右子树的深度差，如果不平衡，返回-1，平衡则返回实际深度
        if (diff > 1)
            return -1;
        else
            return 1 + max(left, right);
    }
};


