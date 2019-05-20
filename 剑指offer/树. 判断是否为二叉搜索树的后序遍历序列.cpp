//后序遍历序列规律：最后一个元素为根结点，前面左半部分为左子树，右半部分为右子树；BST规律：对任意结点，左结点<根结点<右结点

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.empty()) return false;
        return verify(sequence, 0, sequence.size() - 1);
    }
    
private:
    bool verify(vector<int>& a, int begin, int end) {
        if(begin >= end) return true;//只有一个元素了，其没有左右子树，没有判断的必要，故返回true
        int root = a[end];//根结点的值
        int i = begin;
        for( ; i < end - 1; i++) {//注意这里最多扫描到倒数第二个元素（最后一个元素为根结点）
            if(a[i] > root) break;//一旦大于根结点就退出
        }//退出时，i即为左子树序列的长度
        for(int j = i; j < end - 1; j++) {
            if(a[j] < root) return false;
        }
        return verify(a, begin, i - 1) && verify(a, i, end - 1);
    }
};
