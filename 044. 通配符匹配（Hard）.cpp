//考察内容：贪心算法、字符串、动态规划、回溯算法

//注意与 010.Regular Expression Matching 正则匹配的题目区分开来

class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0, iStar = -1, jStar = -1;
        while(i < s.size()) {
            if(s[i] == p[j] || p[j] == '?') {  //情况(1)
                ++i;
                ++j;
            }
            else if(p[j] == '*') {  //情况(2)
                iStar = i;
                jStar = j++;  //jStar赋为j，此时j再自增1
            }
            else if(iStar >= 0) {  //注意这一种情况（若在接下来一次的比较中位置i与位置j的字符不同则j继续回到jStar+1的位置“重头再来”）
                i = ++iStar;
                j = jStar + 1;
            }
            else return false;
        }
        while(j < p.size() && p[j] == '*') ++j;  //匹配完了s中的所有字符，但是之后我们还要检查p串，此时没匹配完的p串里只能剩星号，不能有其他的字符
        return j == p.size();  //将连续的星号过滤掉，如果j不等于p的长度，则返回false
    }
};


//动态规划Dynamic Programming
//分四种情况：两种特殊的情况（初始）和两种一般的情况（动态规划）
//(1)若s和p都为空的话返回true，故初始化dp[0][0]为true
//(2)当s为空，p为连续的星号时的情况。由于星号是可以代表空串的，所以只要s为空，那么连续的星号的位置都应该为true，所以我们现将连续星号的位置都赋为true
//(3)若p中第j个字符是星号，由于星号可以匹配空串，所以如果p中的前j-1个字符跟s中前i个字符匹配成功了（dp[i][j-1] 为true）的话，那么 dp[i][j] 也能为true。或者若 p中的前j个字符跟s中的前i-1个字符匹配成功了（dp[i-1][j] 为true）的话，那么 dp[i][j] 也能为true（因为星号可以匹配任意字符串，再多加一个任意字符也没问题）。
//若p中的第j个字符不是星号，对于一般情况，我们假设已经知道了s中前i-1个字符和p中前j-1个字符的匹配情况（即 dp[i-1][j-1] ），那么现在只需要匹配s中的第i个字符跟p中的第j个字符，若二者相等（s[i-1] == p[j-1]），或者p中的第j个字符是问号（p[j-1] == '?'），再与上 dp[i-1][j-1] 的值，就可以更新 dp[i][j] 了

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));  //使用一个二维dp数组，其中dp[i][j]表示s中前i个字符组成的子串和p中前j个字符组成的子串是否能匹配。
        dp[0][0] = true;  //情况(1)
        for(int j = 1; j <= n; j++) {  //情况(2)
            if(p[j - 1] == '*') dp[0][j] = dp[0][j - 1];
        }
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(p[j - 1] == '*') {  //情况(3)
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];    
                }
                else {  //情况(4)
                    dp[i][j] = (s[i - 1] == p[j - 1] || p[j - 1] == '?') && dp[i - 1][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};


//递归：有三种不同的状态（至于为何失败的情况要分类，就是为了进行剪枝）
//返回0：若s串匹配完成了，但p串但当前字符不是星号，即p后面还有不为星号的字符；
//返回1：表示未匹配到s串的末尾就失败了，即s串未匹配完，p串匹配完了；
//返回2：表示成功匹配。那么只有返回值大于1，才表示成功匹配。

class Solution {
public:
    bool isMatch(string s, string p) {
        return helper(s, p, 0, 0) > 1;
    }
    
    int helper(string& s, string& p, int i, int j) {
        if(i == s.size() && j == p.size()) return 2;
        if(i == s.size() && p[j] != '*') return 0;
        if(j == p.size()) return 1;
        if(s[i] == p[j] || p[j] == '?') {
            return helper(s, p, i + 1, j + 1);
        }
        if(p[j] == '*') {
            if(j + 1 < p.size() && p[j + 1] == '*') {  //连续的星号情况：让星号匹配空串，一个字符，两个字符...直到匹配完整个s串，对每种情况分别调用递归函数
                return helper(s, p, i, j + 1);
            }
            for(int k = 0; k <= (int)s.size() - i; ++k) {
                int res = helper(s, p, i + k, j + 1);
                if(res == 0 || res == 2) return res;
            }
        }
        return 1;
    }
};
