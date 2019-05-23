//分治法

/*
首先计算出左子树的结点个数总和cnt，
如果k小于等于左子树结点总和cnt，说明第k小的元素在左子树中，直接对左子结点调用递归即可。
如果k大于cnt+1，说明目标值在右子树中，对右子结点调用递归函数
如果k等于cnt+1,则当前结点即为所求
*/

class Solution {
public:
    int kthSmallest(TreeNode *root, int k) {
        int cnt = count(root->left);
        if(k <= cnt) {
            return kthSmallest(root->left, k);
        } else if(k > cnt + 1) {
            return kthSmallest(root->right, k - cnt - 1);
        } else 
            return root->val;
    }

    int count(TreeNode *node) {
        if(!node) return 0;
        return 1 + count(node->left) + count(node->right);
    }
};



