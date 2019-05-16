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



// Follow up：变态爬楼梯

//1层台阶， 1   1种 
//2层台阶，11，2   2种 
//3层台阶，111，12，21，3      4种 
//4层台阶，1111，112，121，13，211，22，31，4    8种 
//5层台阶，11111，1112，1121，113，1211，122，131，14，2111，212，221，23，311，32，41，5   16种 
//由数学归纳法可知：an = 2^(n - 1)


class Solution {
public:
    int jumpFloorII(int number) {
        if(number <= 1) return 1;
        return 2 * jumpFloorII(number - 1);
    }
};


