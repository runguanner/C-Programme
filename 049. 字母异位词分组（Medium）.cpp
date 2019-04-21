// 哈希表、字符串


//如果把错位词的字符顺序重新排列，那么会得到相同的结果，所以重新排序是判断是否互为错位词的方法。

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;  //由于错位词重新排序后都会得到相同的字符串，我们以此作为key
        for(string str : strs) {
            string t = str;  //用t来备份
            sort(t.begin(), t.end());  //把错位词的字符顺序重新排列
            m[t].push_back(str);  //将所有错位词都保存到字符串数组中，建立key和字符串数组之间的映射。建立t（key）和str的映射关系
        }                         ////即<string, vector<string>>，string表示相同的字符串。
        for(auto a : m) {  //遍历m，将各个vector<string>（即a.second）都push_back入res。
            res.push_back(a.second);
        }
        return res;
    }
};


//没有用到排序，提高了运算效率。
//用一个大小为26的int数组来统计每个单词中字符出现的次数，然后将int数组转为一个唯一的字符串，跟字符串数组进行映射，这样我们就不用给字符串排序了。

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        for(string str : strs) {
            vector<int> cnt(26, 0);
            string t = "";
            for(char c : str) ++cnt[c - 'a'];
            for(int d : cnt) t += to_string(d) + "/";  //即创建的是t（key）就是一个26的唯一的字符串（表示次数）和每个str之间的映射关系。
            m[t] = push_back(str);  //将所有错位词都保存到字符串数组中，建立t（key）和字符串数组之间的映射。
        }
        for(auto a : m) {
            res.push_back(a.second);
        }
        return res;
    }
};
