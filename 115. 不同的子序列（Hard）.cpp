// 字符串、动态规划


// 看到有关字符串的子序列或者配准类的问题，首先应该考虑的就是用动态规划Dynamic Programming来求解

class Solution {
public:
    int numDistinct(string S, string T) {
        int dp[T.size() + 1][S.size() + 1];
        //二维数组dp的边缘便可以初始化
        for (int i = 0; i <= S.size(); ++i) dp[0][i] = 1;  //若原字符串和子序列都为空时，返回1，因为空串也是空串的一个子序列。若原字符串不为空，而子序列为空，也返回1，因为空串也是任意字符串的一个子序列
        for (int i = 1; i <= T.size(); ++i) dp[i][0] = 0;  //当原字符串为空，子序列不为空时，返回0，因为非空字符串不能当空字符串的子序列
        for (int i = 1; i <= T.size(); ++i) {
            for (int j = 1; j <= S.size(); ++j) {
                dp[i][j] = dp[i][j - 1] + (T[i - 1] == S[j - 1] ? dp[i - 1][j - 1] : 0);
            }  //当更新到dp[i][j]时，dp[i][j] >= dp[i][j - 1] 总是成立，再进一步观察发现，当 T[i-1]==S[j-1]时，dp[i][j] = dp[i][j-1]+dp[i-1][j-1]，若不等，dp[i][j] = dp[i][j-1]
        }
        return dp[T.size()][S.size()];
    }
};
