// 贪心算法、数组


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0,n = prices.size();
        for(int i = 0; i < n - 1; i++) {
            if(prices[i] < prices[i + 1]) {  //低价买入高价抛出，只需要从第二天开始，如果当前价格比之前价格高，则把差值加入利润中
                res += prices[i + 1] - prices[i];
            }
        }
        return res;
    }
};
