// 字符串、动态规划


// 对于字符串相关的题目且求极值的问题，很大可能运用动态规划Dynamic Programming来解。
// 维护一个二维的数组dp，其大小为 (m + 1) x (n + 1)，m和n分别为word1和word2的长度。dp[i][j] 表示从word1的前i个字符转换到word2的前j个字符所需要的步骤。

//   Ø a b c d
// Ø 0 1 2 3 4
// b 1 1 1 2 3
// b 2 2 1 2 3
// c 3 3 2 1 2

// 当word1[i] == word2[j]时，dp[i][j] = dp[i - 1][j - 1]
// 其他情况时，dp[i][j]是其左，左上，上的三个值中的最小值加1，其实这里的左，上，和左上，分别对应的增加，删除，修改操作。

//             / dp[i - 1][j - 1]                                             if (word1[i - 1] == word2[j - 1])
// dp[i][j] =    
//             \ min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1   else
 

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for(int i = 0; i <= m; ++i) dp[i][0] = i;
        for(int i = 0; i <= n; ++i) dp[0][i] = i;
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
            }
        }
        return dp[m][n];
    }
};

// （1）对于当前比较的两个字符 word1[i] 和 word2[j]，若二者相同，一切好说，直接跳到下一个位置。
// （2）若不相同，有三种处理方法，分别为（a）插入、（b）删除、（c）修改（插入是在word2[j]插入到word1[i]的位置，删除是在word1[i]删除，修改是在word2中修改）
//      （a）插入：首先是直接插入一个 word2[j]，那么 word2[j] 位置的字符就跳过了，接着比较 word1[i] 和 word2[j+1] 即可。
//      （b）删除：将 word1[i] 字符直接删掉，接着比较 word1[i+1] 和 word2[j] 即可。
//      （c）修改：将 word1[i] 修改为 word2[j]，接着比较 word1[i+1] 和 word[j+1] 即可。

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> memo(m, vector<int>(n));
        return helper(word1, 0, word2, 0, memo);
    }
    int helper(string& word1, int i, string& word2, int j, vector<vector<int>>& memo) {
        if (i == word1.size()) return (int)word2.size() - j;
        if (j == word2.size()) return (int)word1.size() - i;
        if (memo[i][j] > 0) return memo[i][j];
        int res = 0;
        if (word1[i] == word2[j]) {  
            return helper(word1, i + 1, word2, j + 1, memo);
        } else {
            int insertCnt = helper(word1, i, word2, j + 1, memo);
            int deleteCnt = helper(word1, i + 1, word2, j, memo);
            int replaceCnt = helper(word1, i + 1, word2, j + 1, memo);
            res = min(insertCnt, min(deleteCnt, replaceCnt)) + 1;
        }
        return memo[i][j] = res;
    }
};
