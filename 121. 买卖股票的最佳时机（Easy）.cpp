// 数组、动态规划


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, buy = INT_MAX;
        for (int price : prices) {  //遍历价格
            buy = min(buy, price);  //买入为最小价格
            res = max(res, price - buy);  //重点在于买入buy与res的顺序，每遍历一个price，选出遍历过的最小值buy然后选择当前price与最小buy之间的差价就为res
        }
        return res;
    }
};
