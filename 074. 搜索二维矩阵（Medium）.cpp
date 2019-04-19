// 数组、二分查找


// Two binary search：第一次先用二分查找法找到目标值所在的行的位置，第二次在该行上再用一次二分查找法来找是否存在目标值。

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        if(target < matrix[0][0] || target > matrix.back().back()) return false;
        int left = 0, right = matrix.size() - 1;
        while(left <= right) {
            int mid = (left + right) / 2;
            if(matrix[mid][0] == target) return true;
            else if(matrix[mid][0] < target) left = mid + 1;
            else right = mid - 1;
        }
        int tmp = right;
        left = 0;
        right = matrix[tmp].size() - 1;
        while(left <= right) {
            int mid = (left + right) / 2;
            if(matrix[tmp][mid] == target) return true;
            else if(matrix[tmp][mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
};


// one binary search：可以使用一次二分查找法，如果按S型遍历该二维数组，可以得到一个有序的一维数组，那么我们只需要用一次二分查找法。
// 关键就在于坐标的转换，如何把二维坐标和一维坐标转换是关键点，把一个长度为n的一维数组转化为m*n的二维数组(m*n = n)后，那么原一维数组中下标为i的元素将出现在二维数组中的[i/n][i%n]的位置。

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        if(target < matrix[0][0] || target > matrix.back().back()) return false;
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m * n - 1;
        while(left <= right) {
            int mid = (left + right) / 2;
            if(matrix[mid / n][mid % n] == target) return true;
            else if(matrix[mid / n][mid % n] < target) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
};
