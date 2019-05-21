//总结：二叉树的遍历总结（前序、中序、后序、层序、之字形、垂直遍历）

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//三种递归遍历（前序、中序、后序）
//前序遍历（根-左-右）
void preOrder(TreeNode *root, vector<int>& path) {
    if(root == nullptr) return;
    path.push_back(root->val);
    preOrder(root->left, path);
    preOrder(root->right, path);
}

//中序遍历（左-根-右）
void inOrder(TreeNode *root, vector<int>& path) {
    if(root == nullptr) return;
    inOrder(root->left, path);
    path.push_back(root->val);
    inOrder(root->right, path);
}

//后序遍历（左-右-根）
void postOrder(TreeNode *root, vector<int>& path) {
    if(root == nullptr) return;
    postOrder(root->left, path);
    postOrder(root->right, path);
    path.push_back(root->val);
}


//三种非递归遍历（前序、中序、后序）

//前序遍历（根-左-右）
//根据前序遍历访问的顺序，优先访问根结点，然后再分别访问左结点和右结点。即对于任一结点，其可看做是根结点，因此可以直接访问；
//访问完之后，若其左结点不为空，按相同规则访问它的左子树；当访问其左子树时，再访问它的右子树。
class Solution
{
public:
    vector<int> preOrder(TreeNode* root) {
        vector<int> path;
        if(root == nullptr) return path;
        
        stack<TreeNode*> s;
        TreeNode *p = root;
        while(p || !s.empty()) {//即先push_back()父节点的值，压入左节点是为了后面每个p出栈指向右节点，访问右节点
            if(p) {
                path.push_back(p->val);//访问当前父节点
                s.push(p);//入栈
                p = p->left;//指向下一个左节点
            }
            
            else {//当左节点为空之后
                p = s.top();
                s.pop();//出栈
                p = p->right;//指向右节点
            }
        }
        return path;
    }
};

//中序遍历（左-根-右）
class Solution {
public:
    vector<int> inOrder(TreeNode *root) {
        vector<int> path;
        if(root == nullptr) return path;
        
        stack<TreeNode*> s;
        TreeNode *p = root;
        while(p || !s.empty()) {
            if(p) {//当左节点不为空时
                s.push(p);//入栈
                p = p->left;//指向下一个左节点
            }
            
            else {//当左结点为空时
                p = s.top();
                path.push_back(p->val);//访问栈顶元素（父结点）
                s.pop();//出栈
                p = p->right;//指向右节点
            }
        }
        return path;
    }
};

//后序遍历（左-右-根）
class Solution {
public:
    vector<int> postOrder(TreeNode *root) {
        vector<int> path;
        if(root == nullptr) return path;
        
        stack<TreeNode*> s;
        TreeNode *p;//当前结点指针
        TreeNode *pre == nullptr;//用于记录上一次访问的结点
        s.push(root);
        while (!s.empty()) {//不为空时才会入栈，故p不可能为nullptr,无需像之前加p的判断
            p = s.top();//指向栈顶元素
            bool temp1 = p->left == nullptr && p->right == nullptr;//如果当前结点为叶子结点
            bool temp2 = pre != nullptr && (pre == p->left || pre == p->right);//或者当前结点的左结点和右结点都已被访问过了（若pre=p->left说明右结点为空，因为栈中按照根右左这样的顺序入栈，根左这种结构才能出现这种情况）
            
            if(!temp1 && !temp2) {//如果不是上面两种情况，直接入栈
                //先将右结点入栈，再将左结点入栈，这样可以保证之后访问时先访问左结点在访问右结点
                if(p->right) s.push(p->right);//右结点入栈
                if(p->left) s.push(p->left);//左结点入栈
            } else {
                path.push_back(p->val);//访问顺序：左、右、根
                s.pop();
                pre = p;//保存刚刚访问过的结点
            }
        }
        return path;
    }
};

//后序遍历的另一解法：实际时前序遍历（但先访问右节点）即变为：根-右-左，然后翻转就变为：左-右-根，即后序遍历了
vector<int> postorderTraversal(TreeNode* root) {
    list<int> temp; //开辟临时链表
    stack<TreeNode*> s; //存储各结点指针
    TreeNode* p = root;
    
    while(p || !s.empty())
    {
        while(p) //右结点不为空时
        {
            s.push(p);
            temp.push_front(p->val); //在头部插入元素，用链表比较好，和前序遍历相反
            p = p->right; //指向下一个右结点，和前序遍历相反
        }
        if(!s.empty()) //右结点为空时
        {
            p = s.top();
            s.pop(); //出栈
            p = p->left; //指向左结点，和前序遍历相反
        }
    } //根-右-左
    
    vector<int> result;
    copy(temp.begin(), temp.end(), back_inserter(result)); //将list中元素复制到vector中
    return result;
}

