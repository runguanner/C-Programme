// 字符串



class Solution {
public:
    string LeftRotateString(string str, int n) {
        if(n < 1 || str.empty()) return str;
        n = n % str.size();
        reverse(str.begin(), str.end());
        reverse(str.begin(), str.end() - n);
        reverse(str.end() - n, str.end());
        return str;
    }
};
