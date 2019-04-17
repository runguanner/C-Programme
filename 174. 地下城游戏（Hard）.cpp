// 动态规划

// 参考 064. 最小路径和
// 建立一个二维数组dp，其中dp[i][j]用来表示当前位置 (i, j) 出发的起始血量，最先处理的是公主所在的房间的起始生命值，然后慢慢向第一个房间扩散，不断的得到各个位置的最优的生命值。
// 逆着往回推，骑士逆向进入房间后PK后所剩的血量就是骑士正向进入房间时pk前的起始血量。
// 状态转移方程是dp[i][j] = max(1, min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j])
// 状态方程中的 min：表示在我回退的上一步的最小的血量然后减去当前位置的血量，然后和1比较取max，因为如果比1小，则我需要保命，就得取1。

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        dp[m][n - 1] = 1, dp[m - 1][n] = 1;  //到达公主房间后，骑士血量至少为1，那么此时公主房间的右边和下边房间里的数字都设置为1
        for(int i = m - 1; i >= 0; --i) {
            for(int j = n - 1; j >= 0; --j) {
                dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);  //到达公主房间的生存血量就是1减去公主房间的数字和1相比较，取较大值
            }
        }
        return dp[0][0];
    }
};

// 由于最终目标是骑士到达公主位置，因此在右下角必须满足HP剩余1.
// 从右下角位置开始倒推，每个位置需要同时满足两个条件：（1）该位置HP为1(保证不死)，（2）该位置的HP足够到达公主(使用动态规划)
