// 树、递归


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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)//遍历主树pRoot1（前序遍历递归法）
    {
        bool result = false;
        if(pRoot2 != NULL && pRoot1 != NULL) {
            if(pRoot1->val == pRoot2->val) {
                result = isSubtree(pRoot1, pRoot2);
            }
            if(!result) {
                result = HasSubtree(pRoot1->left, pRoot2);
            }
            if(!result) {
                result = HasSubtree(pRoot1->right, pRoot2);
            }
        }
        return result;
    }
    
    bool isSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if(pRoot2 == NULL) return true;
        if(pRoot1 == NULL) return false;
        if(pRoot1->val != pRoot2->val) return false;
        return isSubtree(pRoot1->left, pRoot2->left) && isSubtree(pRoot1->right, pRoot2->right);
    }
};

