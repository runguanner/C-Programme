// 树、深度优先搜索


/ 对于每个结点来说，我们要知道经过其左子结点的path之和大还是经过右子节点的path之和大。那么递归函数返回值就可以定义为以当前结点为根结点，到叶节点的最大路径之和，然后全局路径最大值放在参数中，用结果res来表示。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        helper(root, res);  //helper函数返回的是“max(left, right) + node->val”哪一半大的加上node->val的和的值
        return res;  //res返回的是以左子结点为终点的最大path之和加上以右子结点为终点的最大path之和，还要加上当前结点值，这样就组成了一个条完整的路径
    }
    int helper(TreeNode* node, int& res) {
        if(!node) return 0;
        int left = max(helper(node->left, res), 0);  //由于路径和有可能为负数，当然不希望加上负的路径和，所以我们和0相比，取较大的那个，就是要么不加，加就要加正数
        int right = max(helper(node->right, res), 0);
        res = max(res, left + right + node->val);  //更新全局最大值结果res
        return max(left, right) + node->val;
    }
};


// Follow up：求返回这个最大路径，那么就复杂很多！
// 因为我们的递归函数就不能返回路径和了，而是返回该路径上所有的结点组成的数组，递归的参数还要保留最大路径之和，同时还需要最大路径结点的数组，然后对左右子节点调用递归函数后得到的是数组，我们要统计出数组之和，并且跟0比较，如果小于0，和清零，数组清空。然后就是更新最大路径之和跟数组啦，还要拼出来返回值数组。



