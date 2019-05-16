// 动态规划



//因为递归计算了很多分支，效率很低，这里需要用动态规划 (Dynamic Programming) 来提高效率
class Solution {
public:
    int jumpFloor(int number) {
        if(number <= 1) return 1;
        vector<int> dp(number);
        dp[0] = 1, dp[1] = 2;//dp[0]表示一层台阶，dp[1]表示两层台阶
        for(int i = 2; i < number; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp.back();
    }
};


// 递归的写法会超时，但是只要加上记忆数组，那就不一样了，因为记忆数组可以保存计算过的结果，这样就不会存在重复计算了，大大的提高了运行效率
// 其实递归加记忆数组跟迭代的 DP 形式基本是大同小异的

class Solution
{
public:
    int climbStairs(int n) {
        vector<int> memo(n + 1);
        return helper(n, memo);
    }
    
    int helper(int n, vector<int>& memo) {
        if(n <= 1) return 1;
        if(memo[n] > 0) return memo[n];
        return memo[n] = helper(n - 1, memo) + helper(n - 2, memo);
    }
};
