// Path Sum 1


// DFS
// 递归法
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        if (!root->left && !root->right && root->val == sum ) return true;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};

// 迭代法
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        stack<TreeNode*> st{{root}};
        while (!st.empty()) {
            TreeNode *t = st.top(); st.pop();
            if (!t->left && !t->right) {
                if (t->val == sum) return true;
            }
            if (t->right) {
                t->right->val += t->val;
                st.push(t->right);
            }
            if (t->left) {
                t->left->val += t->val;
                st.push(t->left);
            }
        }
        return false;
    }
};




// Path Sum 2

// 需要用到二维的vector，而且每当DFS搜索到新节点时，都要保存该节点。
// 每当找出一条路径之后，都将这个保存为一维vector的路径保存到最终结果二位vector中。
// 每当DFS搜索到子节点，发现不是路径和时，返回上一个结点时，需要把该节点从一维vector中移除。

// 递归法
class Solution
{
public:
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        vector<vector<int>> res;
        vector<int> out;
        helper(root, sum, out, res);
        return res;
    }
    
    void helper(TreeNode* node, int sum, vector<int>& out, vector<vector<int>>& res) {
        if(!node) return;
        out.push_back(node->val);
        if(sum == node->val && !node->left && !node->right) {
            res.push_back(out);
        }
        helper(node->left, sum - node->val, out, res);
        helper(node->right, sum - node->val, out, res);
        out.pop_back();//需要把该节点从一维vector中移除,压入新的节点
    }
};


// 迭代法：中序遍历
class Solution
{
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<TreeNode*> s;//由于要取出路径上的节点值，所以我们用一个vector来代替stack
        TreeNode *cur = root, *pre = NULL;
        int val = 0;
        while(cur || !s.empty()) {
            while(cur) {
                s.push_back(cur);
                val += cur->val;//首先利用while循环找到最左子节点，在找的过程中，把路径中的节点值都加起来
                cur = cur->left;
            }
            cur = s.back();
            if(!cur->left && !cur->right && val == sum) {//取出vector中的尾元素，如果其左右子节点都不存在且当前累加值正好等于sum了，我们将这条路径取出来存入结果res中
                vector<int> v;
                for(auto it : s) {
                    v.push_back(it->val);
                }
                res.push_back(v);
            }
            //下面的部分是和一般的迭代中序写法有所不同的地方：在于最左节点是不是叶子节点
            if(cur->right && cur->right != pre) cur = cur->right;
            else {//如果当前最左节点已经是个叶节点了，我们要转移到其他的节点上时需要把当前的节点值减去
                pre = cur;
                val -= cur->val;
                s.pop_back();
                cur = NULL;
            }
        }
        return res;
    }
};








