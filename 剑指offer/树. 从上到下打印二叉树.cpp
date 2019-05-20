/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/

//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;

class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        if(root == NULL) return res;
        q.push(root);
        while(!q.empty()) {
            res.push_back(q.front()->val);
            if(q.front()->left != NULL) q.push(q.front()->left);
            if(q.front()->right != NULL) q.push(q.front()->right);
            q.pop();
        }
        return res;
    }
};

//int main() {
//    Solution sol;
//    vector<int> res;
//    TreeNode *root = new TreeNode(1);
//    root->right = new TreeNode(2);
//    root->right->left = new TreeNode(3);
//    res = sol.PrintFromTopToBottom(root);
//    for(int i : res) cont << i;
//    return 0;
//}

