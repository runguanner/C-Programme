// 数组、动态规划


// 动态规划Dynamic Programming（定义两个变量：局部最优变量local和全局最优变量global）
// 定义l[i][j]为在到达第i天时最多可进行j次交易并且最后一次交易在最后一天卖出的最大利润，此为局部最优。
// 定义g[i][j]为在到达第i天时最多可进行j次交易的最大利润，此为全局最优。

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) return 0;
        int n = prices.size(), g[n][3] = {0}, l[n][3] = {0};
        for (int i = 1; i < prices.size(); ++i) {
            int diff = prices[i] - prices[i - 1];
            for (int j = 1; j <= 2; ++j) {
                l[i][j] = max(g[i - 1][j - 1] + max(diff, 0), l[i - 1][j] + diff);  //局部最优值是比较前一天并少交易一次的全局最优加上大于0的差值，和前一天的局部最优加上差值中取较大值
                g[i][j] = max(l[i][j], g[i - 1][j]);  //全局最优值是比较局部最优和前一天的全局最优
            }
        }
        return g[n - 1][2];
    }
};

// 如何理解local[i][j]并且对其简化：上面定义的local[i][j]为在到达第i天时最多可进行j次交易并且最后一次交易在最后一天卖出的最大利润。
// 以下解释第i天卖第j支股票的情况：
// 1.今天刚买的：那么Local(i, j) = Global(i-1, j-1)，相当于啥都没干。
// 2.昨天买的：那么Local(i, j) = Global(i-1, j-1) + diff，等于Global(i-1, j-1)中的交易，加上今天干的那一票。
// 3.更早之前买的：那么Local(i, j) = Local(i-1, j) + diff，昨天别卖了，留到今天卖。
// 但其实第一种情况是不需要考虑的，因为当天买当天卖不会增加利润，完全是重复操作，这种情况可以归纳在global[i-1][j-1]中，所以我们就不需要max(0, diff)了，那么由于两项都加上了diff，所以我们可以把diff抽到max的外面，所以更新后的递推公式为：
// local[i][j] = max(global[i - 1][j - 1], local[i - 1][j]) + diff
// global[i][j] = max(local[i][j], global[i - 1][j])
