// 二叉树、递归



//给定preorder & inorder
//给定中序遍历和前序遍历序列，且【无重复元素】，则可以从根节点（前序遍历序列的第一个元素）找起，再找左子树和右子树
//递归法

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//法1：采用下标法
class Solution
{
public:
    TreeNode* reConstructBinaryTree(vector<int>& pre, vector<int>& vin) {
        return reConstructOneLevel(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
    }
    //递归函数功能：构建树的某一层结构
    TreeNode* reConstructOneLevel(vector<int>& pre, int preBegin, int preEnd, vector<int>& vin, int vinBegin, int vinEnd) {//这里用下标法，需要6个形参，也可以用迭代器只需4个形参
        if(preBegin > preEnd || vinBegin > vinEnd) return NULL;
        //先找根节点（用前序遍历序列）
        TreeNode* root = new TreeNode(pre[preBegin]);
        //再找左子树和右子树（用中序遍历序列）
        int leftLength = 0;//左子树长度
        for(int i = vinBegin; i <= vinEnd; i++) {
            if(vin[i] == root->val) {
                leftLength = i;
                break;//先找到中序遍历序列中根节点的位置
            }
        }
        leftLength -= vinBegin;
        root->left = reConstructOneLevel(pre, preBegin + 1, preBegin + leftLength, vin, vinBegin, vinBegin + leftLength - 1);//左子树
        root->right = reConstructOneLevel(pre, preBegin + leftLength + 1, preEnd, vin, vinBegin + leftLength + 1, vinEnd);//右子树
        return root;//递归母函数的出口
    }
};


//法2：采用迭代器
class Solution
{
public:
    TreeNode* reConstructBinaryTree(vector<int>& pre, vector<int>& vin) {
        return reConstructOneLevel(pre.begin(), pre.end(), vin.begin(), vin.end());//！！注意end指向容器末尾（最后一个元素的下一个位置）
    }
    //递归函数功能：构建树的某一层结构
    //template<typename iterator> 
    //也可直接用vector<int>::iterator类型，模板可以进行类型延伸(泛型编程)，避免不同类型写多个函数（自己的思考）,但函数内部的很多变量名需用auto
    //为便于书写，也可使用类型别名 （同typedef）
    using iter = vector<int>::iterator;
    TreeNode* reConstructOneLevel(iter pre_begin, iter pre_end, iter vin_begin, iter vin_end) {//这里用迭代器需4个形参
        if(pre_begin == pre_end || vin_begin == vin_end) return nullptr;//递归出口一（除结尾外还需要一个内部return,即两个return吧）
        //先找根节点（用前序遍历序列）具体只用求左子树序列长度就可以了
        vector<int>::iterator vin_root_pos = find(vin_begin, vin_end, root->val);//由于序列中不含重复元素，故可以用此方法
        //再找左子树和右子树（用中序遍历序列）
        int leftLength = vin_root_pos - vin_begin;//左子树序列长度
        // ！！注意end指向容器末尾（最后一个元素的下一个位置）
        root->left = reConstructOneLevel(pre_begin + 1, pre_begin + leftLength + 1, vin_begin, vin_root_pos);//左子树
        root->right = reConstructOneLevel(pre_begin + leftLength + 1, vin_root_pos + 1, vin_end);//右子树
        return root;//递归出口二
    }
};





//给定postorder & inorder且无重复

class Solution
{
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        return build(postorder.begin(), postorder.end(), inorder.begin(), inorder.end());
    }
private:
    using iter = vector<int>::iterator; //类型别名
    TreeNode* build(iter post_begin, iter post_end, iter in_begin, iter in_end)
    {
        if(post_begin == post_end || in_begin == in_end) return nullptr;
       
        //先找根结点（后序遍历最一个元素）
        TreeNode* root = new TreeNode(*(post_end-1)); //注意容器的end迭代器指向最后一个元素的下一个位置，而非最后一个元素！！
       
        // cout<<root->val<<endl;
        //再找左右子树（通过中序遍历，找到左右子树的分割点，求出左子树的长度）
        vector<int>::iterator in_root_pos = find(in_begin, in_end, root->val); //同过迭代器将STL中容器与算法联系起来
        int left_length = in_root_pos - in_begin;
       
        //左子树
        root->left = build(post_begin, post_begin + left_length, in_begin, in_root_pos);
        //右子树
        root->right = build(post_begin + left_length, post_end - 1, in_root_pos + 1, in_end);       
        return root;
    }
};


