// 数组、矩阵、二分查找



// O(r)或O(c)

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if(array.empty() || array[0].empty()) return false;
        int row = array.size(), col = array[0].size();
        int i = row - 1, j = 0;
        while(i >= 0 && j <= col - 1) {
            if(array[i][j] > target) i--;
            else if(array[i][j] < target) j++;
            else return true;
        }
        return false;
    }
};


// 方法二：扫描行，每行进行二分查找：O(r*logc)

class Solution
{
public:
    bool searchMatrix(vector<vector<int>>& a, int target) {
        if(a.empty() || a[0].empty()) return false;
        int row = a.size(), col = a[0].size();
        for(int i = 0; i < row; i++) {
            if(a[i][0] <= target && a[i][col - 1] >= target) {
                if(a[i][0] == target || a[i][col - 1] == target) return true;
                int left = 0, right = col - 1;
                while(left <= right) {
                    int mid = (left + right) / 2;
                    if(a[i][mid] > target) right = mid - 1;
                    else if(a[i][mid] < target) left = mid + 1;
                    else return true;
                }
            }
        }
        return false;
    }
};
