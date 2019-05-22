/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    int maxDepth(TreeNode* root)
    {
        if(root == NULL) return 0; //递归的出口
        int depth_left = maxDepth(root->left); //用递归的方法，左子树的深度
        int depth_right = maxDepth(root->right); //右子树的深度
       
        return 1 + max(depth_left, depth_right);
       
    }
};


