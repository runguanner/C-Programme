// 二叉树、递归



/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/

class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if(pRoot == nullptr) return;//如果当前结点为空或者子结点均为空就返回，不进行后续操作
        if(pRoot->left == nullptr && pRoot->right == nullptr) return;
        swap(pRoot->left, pRoot->right);//如果当前结点有子结点就交换左右子结点
        if(pRoot->left) Mirror(pRoot->left);//如果左子树非空，则镜像化左子树
        if(pRoot->right) Mirror(pRoot->right);
    }
};
