// 二叉树、递归



/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/

// 递归法
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        return isMirror(pRoot, pRoot);//从根结点开始
    }
    
    bool isMirror(TreeNode* t1, TreeNode* t2) {//判断两个树是否为镜像关系
        //三个递归出口，两结点同时为空时为true,只有一个为空时为false,均为非空时，比较当前结点值以及左右子树是否为对称的
        if(t1 == nullptr && t2 == nullptr) return true;
        else if(t1 == nullptr || t2 == nullptr) return false;
        return (t1->val == t2->val) && isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
    }
};

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        return isSymmetric(root->left, root->right);
    }
    bool isSymmetric(TreeNode *left, TreeNode *right) {
        if (!left && !right) return true;
        if (left && !right || !left && right || left->val != right->val) return false;
        return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }
    
};


// 迭代法
class Solution
{
public:
    bool isSymmetrical(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*> q1, q2;
        q1.push(root->left);
        q2.push(root->right);
        while(!q1.empty() && !q2.empty()) {
            TreeNode *node1 = q1.front(); q1.pop();
            TreeNode *node2 = q2.front(); q2.pop();
            if(!node1 && !node2) return true;
            if((node1 && !node2) || (!node1 && node2)) return false;
            if(node1->val != node2->val) return false;
            q1.push(node1->left);
            q1.push(node1->right);
            q2.push(node2->right);
            q2.push(node2->left);
        }
        return ture;
    }
};



