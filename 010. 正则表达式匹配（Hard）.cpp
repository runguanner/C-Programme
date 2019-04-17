// 递归
// '*'表示之前那个字符可以有0个，1个或是多个，就是说，字符串a*b，可以表示b或是aaab，即a的个数任意。
// '.'表示匹配任意单个字符。
class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();  //(1)若p为空，若s也为空，返回true，反之返回false。
        if(p.size() == 1) {  //(2)若p的长度为1，若s长度也为1，且相同或是p为'.'则返回true，反之返回false。
            return (s.size() == 1 && (s[0] == p[0] || p[0] == '.'));
        }
        if(p[1] != '*') {  //(3)若p的第二个字符不为*，若此时s为空返回false，否则判断首字符是否匹配，且从各自的第二个字符开始调用递归函数匹配。
            if (s.empty()) return false;
            return (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
        }
        while(!s.empty() && (s[0] == p[0] || p[0] == '.')) {  //(4)若p的第二个字符为*，进行下列循环，条件是若s不为空且首字符匹配（包括p[0]为点）。
            if (isMatch(s, p.substr(2))) return true;  //调用递归函数匹配s和去掉前两个字符的p（假设此时的星号作用是让前面字符出现0次，验证是否匹配）
            s = s.substr(1);  //(5)否则s去掉首字母（因为首字母匹配了可以去掉s的首字母，而p由于星号的作用，可以有任意个首字母，不需要去掉）继续进行循环。
        }
        return isMatch(s, p.substr(2));  //(5)比如s="", p="a*"，由于s为空，不会进入任何的if和while，只能到最后的return来比较了，返回true。
    }
};

// 法(1)中substr()函数有2种用法：
// string s = "0123456789";
// string sub1 = s.substr(5); //只有一个数字5表示从下标为5开始一直到结尾：sub1 = "56789"
// string sub2 = s.substr(5, 3); //从下标为5开始截取长度为3位：sub2 = "567"


法(1)简化：
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();  //(1)
        if (p.size() > 1 && p[1] == '*') {  //(4)(5)
            return isMatch(s, p.substr(2)) || (!s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p));
        } else {  //(3)
            return !s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
        }
    }
};

// DP动态规划
// This problem has a typical solution using Dynamic Programming. We define the state P[i][j] to be true if s[0..i) matches p[0..j) and false otherwise. Then the state equations are:

// P[i][j] = P[i - 1][j - 1], if p[j - 1] != '*' && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
// P[i][j] = P[i][j - 2], if p[j - 1] == '*' and the pattern repeats for 0 times;
// P[i][j] = P[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'), if p[j - 1] == '*' and the pattern repeats for at least 1 times.

// Putting these together, we will have the following code.

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length(); 
        vector<vector<bool> > dp(m + 1, vector<bool> (n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if (p[j - 1] == '*')
                    dp[i][j] = dp[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
                else dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
        return dp[m][n];
    }
};
