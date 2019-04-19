// 哈希表、双指针、字符串、Sliding Window


class Solution {
public:
    string minWindow(string s, string t) {
        string res = "";
        unordered_map<char, int> letterCnt;  //为啥要用HashMap，而不是HashSet，是因为要统计T串中字母的个数，而不是仅仅看某个字母是否在T串中出现。
        int left = 0, cnt = 0, minLen = INT_MAX;  //minLen是维护的一个全局变量
        for(char c : t) ++letterCnt[c];  //统计子串T中字母的个数
        for(int i = 0; i < s.size(); i++) {
            if(--letterCnt[s[i]] >= 0) ++cnt;  //对于S中的每个遍历到的字母，都在HashMap中的映射值减1，如果减1后的映射值仍>=0，说明当前遍历到的字母是T串中的字母。
            while(cnt == t.size()) {  //当 cnt 和T串字母个数相等时，说明此时的窗口已经包含了T串中的所有字母，此时更新一个 minLen 和结果 res
                if(minLen > i - left + 1) {
                    minLen = i - left + 1;
                    res = s.substr(left, minLen);
                }
                if(++letterCnt[s[left]] > 0) --cnt;  //如果++letterCnt[s[left]]立马大于0，代表这个值在T中是不可或缺的  ####关键点####
                ++left;  //否则左边界右移
            }
        }
        return res;
    }
};


// 也可以不用HashMap，直接用个 int 的数组来代替，因为ASCII只有256个字符，所以用个大小为256的int数组即可代替HashMap。
// 但由于一般输入字母串的字符只有128个，所以也可以只用128，其余部分的思路完全相同。只改了一个数据结构，但是运行速度提高了一倍，说明数组还是比HashMap快啊！

class Solution {
public:
    string minWindow(string s, string t) {
        string res = "";
        vector<int> letterCnt(128, 0);
        int left = 0, cnt = 0, minLen = INT_MAX;
        for (char c : t) ++letterCnt[c];
        for (int i = 0; i < s.size(); ++i) {
            if (--letterCnt[s[i]] >= 0) ++cnt;
            while (cnt == t.size()) {
                if (minLen > i - left + 1) {
                    minLen = i - left + 1;
                    res = s.substr(left, minLen);
                }
                if (++letterCnt[s[left]] > 0) --cnt;
                ++left;
            }
        }
        return res;
    }
};
