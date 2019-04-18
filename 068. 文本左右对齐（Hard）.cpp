// 字符串

// 待解决问题：
// 1、确定每一行能放下的单词数，就是比较n个单词的长度总和加上n-1个空格的长度跟给定的长度L来比较即可，找到了一行能放下的单词个数，然后计算出这一行存在的空格的个数，是用给定的长度L减去这一行所有单词的长度和。
// 2、空格处理：最后一行的处理方法和其他行之间略有不同。
// 3、用总的空格数除以空间个数，能除尽最好，说明能平均分配，除不尽的话就多加个空格放在左边的空间里。

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        vector<string> res;
        int i = 0;
        while (i < words.size()) {  //i, j是用来统计每一排的单词树（或者说间隔数）words.size()表示多少个单词
            int j = i, len = 0;
            while (j < words.size() && len + words[j].size() + j - i <= maxWidth) {  //j - i表示目前这一排中需要的间隔数，已有的len加上预备加入的单词长度与目前需要的间隔数的大小与maxWidth（允许一排最长的长度）比较
                len += words[j++].size();  //满足情况就把这个单词加入，并且j++表示增加一个间隔数，同时转入下一个单词
            }
            string out;
            int space = maxWidth - len;  //因为最后不满足情况，但是可能最后加入的单词后面还有空格，所有这里的space和间隔数(j-i)是不相等的，space更大，此时我们要来规划space该如何分布（情况3）
            for (int k = i; k < j; ++k) {  //遍历循环每一轮的第i个单词到第j个单词
                out += words[k];  //加入一个单词到out后，接下来要加入的是space数，这里用一个tmp来表示每个间隔之间需要加入的space。
                if (space > 0) {
                    int tmp;
                    if (j == words.size()) {  //这种情况是在考虑（情况2）最后一排
                        if (j - k == 1) tmp = space;
                        else tmp = 1;
                    } else {  //考虑前面的若干排
                        if (j - k - 1 > 0) {
                            if (space % (j - k - 1) == 0) tmp = space / (j - k - 1);  //整除情况，平均分配space数
                            else tmp = space / (j - k - 1) + 1;  //不是整除前面的多分配一个space数
                        } else tmp = space;
                    }
                    out.append(tmp, ' ');
                    space -= tmp;
                }
            }
            res.push_back(out);
            i = j;  //接下来一次得到第2、3、4...排
        }
        return res;
    }
};
