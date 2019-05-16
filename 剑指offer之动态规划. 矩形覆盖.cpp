// 动态规划



/*
问题：矩形覆盖
方法：动态规划
f(n)表示 2 * n 的矩形的覆盖方法
f(n)可以是 2 * (n - 1) 的矩形加一个竖着放的 2 * 1 的矩形或 2 * (n - 2) 的矩形加 2 个横着放的,
故递推公式为：f(n) = f(n - 1) + f(n - 2)
另外，f(1) = 1,f(2) = 2，为方便起见，假设f(0) = 1
*/

class Solution {
public:
    int rectCover(int number) {
        if(number <= 0) return 0;
        if(number == 1) return 1;
        vector<int> dp(number + 1);
        dp[0] = dp[1] = 1;
        for(int i = 2; i < number + 1; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp.back();
    }
};
