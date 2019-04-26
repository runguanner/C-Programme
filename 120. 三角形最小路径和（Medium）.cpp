// 数组、动态规划


// 为了保证能得到全局最小，运用动态规划Dynamic Programming。

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i = 1; i < triangle.size(); ++i) {
            for(int j = 0; j < triangle[i].size(); ++j) {
                if(j == 0) {
                    triangle[i][j] += triangle[i - 1][j];
                } else if(j == triangle[i].size() - 1) {
                    triangle[i][j] += triangle[i - 1][j - 1];
                } else {
                    triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);  //这三排中“+=”的意思是说原来位置triangle[i][j]的值加上min中的值赋给新的位置triangle[i][j]的新值（相当于覆盖）
                }
            }
        }
        return *min_element(triangle.back().begin(), triangle.back().end());
    }
};

