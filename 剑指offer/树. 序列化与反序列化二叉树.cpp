struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
利用“前序遍历方式”序列化与反序列化
由于有表示空结点的符号存在，故可以唯一确定二叉树，而不需要与中序遍历序列相结合
*/

#include <string>
#include <sstream>

class Codec {
public:
    string serialize(TreeNode *root) {
        ostringstream out;//构造字符串流
        seri(root, out);
        return out.str();//out变为字符串返回
    }
    
    TreeNode* deserialize(string data) {
        istringstream in(data);//构造字符串流
        return deseri(in);
    }
    
private:
    //序列化，树 -> 序列
    void seri(TreeNode* root, ostringstream& out) {
        if(root) {
            out << root->val << ' ';
            seri(root->left, out);
            seri(root->right, out);
        }
        else {//空结点时，置为'# '（注意#号后有空格）
            out << "# ";
        }
    }
    
    //反序列化，序列 -> 树
    TreeNode* deseri(istringstream& in) {
        string val;//有可能数字为多位数，故不能设定为char
        in >> val;//反序列化，将序列中的值读出，联系cin,将输入值传给变量(分隔符为空格，可以直接用,若用其他分隔，可用getline函数)
        
        if(val == "#") return nullptr;
        else {
            TreeNode *root = new TreeNode(stoi(val));//处理根节点
            root->left = deseri(in);
            root->right = deseri(in);
            return root;
        }
    }
};



/*
层序遍历的非递归解法，利用queue来做本质上是BFS
*/

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        queue<TreeNode*> q;
        if (root) q.push(root);
        while (!q.empty()) {
            TreeNode *t = q.front(); q.pop();
            if (t) {
                out << t->val << ' ';
                q.push(t->left);
                q.push(t->right);
            } else {
                out << "# ";
            }
        }
        return out.str();
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        istringstream in(data);
        queue<TreeNode*> q;
        string val;
        in >> val;
        TreeNode *res = new TreeNode(stoi(val)), *cur = res;
        q.push(cur);
        while (!q.empty()) {
            TreeNode *t = q.front(); q.pop();
            if (!(in >> val)) break;
            if (val != "#") {
                cur = new TreeNode(stoi(val));
                q.push(cur);
                t->left = cur;
            }
            if (!(in >> val)) break;
            if (val != "#") {
                cur = new TreeNode(stoi(val));
                q.push(cur);
                t->right = cur;
            }
        }
        return res;
    }
};
