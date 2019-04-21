// 排序、数组


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.empty()) return {};
        sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b) {return a.start < b.start;});  //要排序的是个结构体，所以要定义自己的comparator，才能用sort来排序，我们以start的值从小到大来排序，排完序我们就可以开始合并了
        vector<Interval> res{intervals[0]};
        for(int i = 1; i < intervals.size(); i++) {
            if(res.back().end < intervals[i].start) {
                res.push_back(intervals[i]);
            }
            else {
                res.back().end = max(res.back().end, intervals[i].end);
            }
        }
        return res;
    }
};




class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        int n = intervals.size();
        vector<Interval> res;  
        vector<int> starts, ends;
        for(int i = 0; i < n; i++) {  //将起始位置和结束位置分别存到了两个不同的数组starts和ends中
            starts.push_back(intervals[i].start);
            ends.push_back(intervals[i].end);
        }
        sort(starts.begin(), starts.end());  //然后分别进行排序
        sort(ends.begin(), ends.end());
        for(int i = 0, j = 0; i < n; i++) {  //用两个指针i和j，初始化时分别指向starts和ends数组的首位置
            if(i == n - 1 || starts[i + 1] > ends[i]) {  //如果i指向starts数组中的最后一个位置，或者当starts数组上i+1位置上的数字大于ends数组的i位置上的数时，此时说明区间已经不连续了
                res.push_back(Interval(starts[j], ends[i]));
                j = i + 1;
            }
        }
        return res;
    }
};
