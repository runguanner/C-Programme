// 字符串、回溯算法


// 两个经验:一是只要遇到字符串的子序列或配准问题首先考虑动态规划DP，二是只要遇到需要求出所有可能情况首先考虑用递归。

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        restore(s, 4, "", res);
        return res;
    }
    void restore(string s, int k, string out, vector<string> &res) {  //用k来表示当前还需要分的段数
        if (k == 0) {  ////如果k = 0，则表示三个点已经加入完成，四段已经形成，若这时字符串刚好为空，则将当前分好的结果保存
            if (s.empty()) res.push_back(out);
        }
        else {  //若k != 0, 则对于每一段，我们分别用一位，两位，三位来尝试，分别判断其合不合法，如果合法，则调用递归继续分剩下的字符串，最终和求出所有合法组合
            for (int i = 1; i <= 3; ++i) {
                if (s.size() >= i && isValid(s.substr(0, i))) {
                    if (k == 1) restore(s.substr(i), k - 1, out + s.substr(0, i), res);
                    else restore(s.substr(i), k - 1, out + s.substr(0, i) + ".", res);
                }
            }
        }
    }
    bool isValid(string s) {
        if (s.empty() || s.size() > 3 || (s.size() > 1 && s[0] == '0')) return false;
        int res = atoi(s.c_str());
        return res <= 255 && res >= 0;
    }
};


// 可以省掉isValid函数，直接在调用递归之前用if语句来滤掉不符合题意的情况.
// 这里面用了k != std::to_string(val).size()，比如当k=3时，说明应该是个三位数，但如果字符是"010"，那么转为整型val=10，再转回字符串就是"10"，此时的长度和k值不同了，这样就可以找出不合要求的情况了

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        helper(s, 0, "", res);
        return res;
    }
    void helper(string s, int n, string out, vector<string>& res) {
        if(n == 4) {
            if(s.empty()) res.push_back(out);
        }
        else {
            for(int k = 1; k < 4; ++k) {
                if(s.size() < k) break;
                int val = atoi(s.substr(0, k).c_str());
                if(val > 255 || k != std::to_string(val).size()) continue;
                helper(s.substr(k), n + 1, out + s.substr(0, k) + (n == 3 ? "" : "."), res);
            }
        }
    }
};


// 由于每段数字最多只能有三位，而且只能分为四段，所以情况并不是很多.
// 可以使用暴力搜索的方法，每一段都循环1到3，然后当4段位数之和等于原字符串长度时，我们进一步判断每段数字是否不大于255，然后滤去不合要求的数字，加入结果中即可.

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        for (int a = 1; a < 4; ++a) 
        for (int b = 1; b < 4; ++b) 
        for (int c = 1; c < 4; ++c) 
        for (int d = 1; d < 4; ++d) 
            if (a + b + c + d == s.size()) {
                int A = stoi(s.substr(0, a));
                int B = stoi(s.substr(a, b));
                int C = stoi(s.substr(a + b, c));
                int D = stoi(s.substr(a + b + c, d));
                if (A <= 255 && B <= 255 && C <= 255 && D <= 255) {
                    string t = to_string(A) + "." + to_string(B) + "." + to_string(C) + "." + to_string(D);
                    if (t.size() == s.size() + 3) res.push_back(t);
                }
            }
        return res;
    }
};
