// 二分查找，分治算法


// 有两个位置的数字很有特点：左下角和右上角的数。
// 左下角的数字：往上所有的数变小，往右所有数增加，那么就可以和目标数相比较，如果目标数大，就往右搜，如果目标数小，就往上搜。这样就可以判断目标数是否存在。当然也可以把起始数放在右上角，往左和下搜，停止条件设置正确就行。

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        if (target < matrix[0][0] || target > matrix.back().back()) return false;
        int x = matrix.size() - 1, y = 0;
        while(true) {
            if(matrix[x][y] > target) --x;
            else if(matrix[x][y] < target) ++y;
            else return true;
            if(x < 0 || y >= matrix[0].size()) return false;
        }
        return false;
    }
};
