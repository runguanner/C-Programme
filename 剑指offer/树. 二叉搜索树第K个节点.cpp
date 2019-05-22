// 二叉搜索树BST、迭代、分治



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};




/*
【1】中序遍历递归法
递归太多，发生段错误，中序遍历递归法，不是最优的，因为是遍历完之后在给出的结果（可用迭代法进行改进，参考题目 Validate Binary Search Tree）
BST中序遍历之后为从小到大排列
注：可在递归中加入判断进行减枝
*/

class Solution {
public:
    int kthSmallest(TreeNode *root, int k) {
        vector<int> nodes;
        inorder(root, nodes);
        return nodes[k - 1];
    }
    
    void inorder(TreeNode *root, vector<int>& nodes) {
        if(root == nullptr) return;
        
        inorder(root->left, nodes);
        nodes.push_back(root->val);
        inorder(root->right, nodes);
    }
};


//【2】迭代法：在遍历的过程中统计数量（所以不需要全部递归遍历完，才能得出结果）
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        stack<TreeNode*> s;
        TreeNode *p = root;
        
        while(!s.empty() || p) {
            if(p) {
                s.push(p);
                p = p->left;
            } else {
                p = s.top();
                cnt++;
                if(cnt == k) return p->val;
                s.pop();
                
                p = p->right;
            }
        }
        return 0;
    }
};


//【3】分治法
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




