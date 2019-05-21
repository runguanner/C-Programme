//其他遍历方式：层序遍历、之字形层序遍历、垂直遍历

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};





//Binary Tree Level Order Traversal（层序遍历）

//方法一：递归法 O(n),O(1)：实际上就是用的前序遍历的思想（前序遍历对每一层而言，靠左的先访问，满足层序遍历规律），区别在于每次递归传入了level信息
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        traverse(root, 1, res);
        return res;
    }
    
    void traverse(TreeNode* root, int level, vector<vector<int>>& res) {
        if(root == NULL) return;//递归的出口（包括递归子函数的出口）
        if(level > res.size()) {
            res.push_back(vector<int>());//在下一层时，增加空容器（因为事先不知道树的层数，故要一边遍历，一边增加容器大小）
        }
        res[level - 1].push_back(root->val);//将元素值push进第level层的容器（索引从0开始）
        traverse(root->left, level + 1, res);
        traverse(root->right, level + 1, res);//最后一个语句return之后，整个递归函数才结束
    }
};

//方法二：迭代法 O(n),O(1) （要求掌握）
//层序遍历二叉树是典型的广度优先搜索BFS的应用，但是这里稍微复杂一点的是，我们要把各个层的数分开，存到一个二维向量里面（用队列实现）
//（1）首先根结点入队
//（2）访问队首元素，队首元素出队，若子结点不为空，子结点（下一层的所有结点）入队
//（3）一层一层的访问，直至队列清空
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if(root == nullptr) return res;
        
        queue<TreeNode*> q;
        q.push(root);//根节点入队
        
        while(!q.empty()) {
            vector<int> level;
            int size = q.size();
            for(int i = 0; i < size; i++) {
                TreeNode *node = q.front();
                level.push_back(node->val);
                q.pop();
                 //将当前结点的左右子结点入队
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                //下一层的结点排在上一层结点之后
            }
            res.push_back(level);
        }
        return res;
    }
};





//Binary Tree Zigzag Level Order Traversal（之字形层序遍历）

//递归法：用level-order遍历，用奇数层偶数层判断，偶数层时反向存数
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> result;
        traverse(root, 1, result);
        return result;
    }
    //递归函数的功能：按Zigzag Level Order扫描某一层（第level层）的元素，存在一个vector里
    void traverse(TreeNode *root, int level, vector<vector<int>>& result) {
        if(root == NULL) return;//递归子函数和递归母函数的出口
        if(level > result.size()) result.push_back(vector<int>());//增加子容器
        //每一个结点都可以看成本层的根节点，将当前层（第level层）的结点元素push进vector里
        if(level % 2 == 1) result[level - 1].push_back(root->val);//奇数层时，从左到右遍历
        else result[level - 1].insert(result[level - 1].begin(), root->val);//每个数据从开头插入
        //从左到右存数
        traverse(root->left, level + 1, res);
        traverse(root->right, level + 1, res);
    }
};

//迭代法：按level order遍历，偶数层时翻转一下（可以用一bool型变量，每一层反号一次）
class Solution {
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if(root == nullptr) return res;
        
        queue<TreeNode*> q;
        q.push(root);
        bool right_to_left = false;
        
        while(!q.empty()) {
            vector<int> level;
            int size = q.size();//当前层的结点数
            for(int i = 0; i < size; i++) {//遍历该层结点，并将下一层结点入队
                TreeNode *node = q.front();
                level.push_back(node->val);
                q.pop();
                //将当前结点的左右子结点入队
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                //下一层的结点排在上一层结点之后
            }
            if(right_to_left) reverse(level.begin(), level.end());//反序
            res.push_back(level);
            right_to_left = !right_to_left;
        }
        return res;
    }
};





//Binary Tree Vertical Order Traversal （二叉树的竖直遍历）（要求掌握）
/* 掌握
问题：二叉树的垂直遍历
方法：层序遍历，并给每个结点赋上列号(对于每列元素而言，层序遍历访问的先后顺序满足垂直遍历规律)
     把根节点给个序号0，然后开始层序遍历，凡是左子节点则序号减1，右子节点序号加1，这样我们可以通过序号来把相同列的节点值放到一起
*/
class Solution {
    vector<vector<int>> verticalOrder(TreeNode *root) {
        vector<vector<int>> res;
        if(!root) return res;
        
        map<int, vector<int>> m;//构建存储<序号，遍历序列>对的map
        queue<pair<int, TreeNode*>> q;//构建存储<序号，结点>对的队列
        
        q.push({0, root});//根结点入队，根结点序号设为0
        while(!q.empty()) {//层序遍历
            auto a = q.front();
            m[a.first].push_back(a.second->val);//访问当前结点，将结点值push到相同列的容器中
            q.pop();
            
            //将下一层结点入队
            if(a.second->left) q.push(a.first - 1, a.second->left);//左结点序号减一
            if(a.second->right) q.push(a.first + 1, a.second->right);//右结点序号加一
            //下一层的结点排在上一层结点之后
        }
        for(auto mi : m) {//将map中遍历序列按顺序push到结果容器中（map内部会自动排序，序号从小到大排列遍历序列）
            res.push_back(mi.second);
        }
        return res;
    }
};



