// 数组、动态规划

// 维护一个二维的dp数组，其中dp[i][j]表示当前位置的最小路径和，递推式也容易写出来 dp[i][j] = grid[i][j] + min(dp[i - 1][j]。

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dp[m][n];
        dp[0][0] = grid[0][0];
        for(int i = 1; i < m; i++) dp[i][0] = grid[i][0] + dp[i - 1][0];
        for(int j = 1; j < n; j++) dp[0][j] = grid[0][j] + dp[0][j - 1];
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m - 1][n - 1];
    }
};
