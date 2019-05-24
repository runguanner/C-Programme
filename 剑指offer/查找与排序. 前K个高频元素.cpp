//哈希表、堆排序、桶排序

//堆排序
/*
首先应该考虑用HashMap来做，建立数字和其出现次数的映射，然后再按照出现次数进行排序。
我们可以用堆排序来做，使用一个最大堆来按照映射次数从大到小排列，在C++中使用priority_queue来实现，默认是最大堆。
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        priority_queue<pair<int, int>> q;
        vector<int> res;
        for (auto a : nums) ++m[a];
        for (auto it : m) q.push({it.second, it.first});//按频率（it.second）排序，排入q中则为q.first
        for (int i = 0; i < k; ++i) {
            res.push_back(q.top().second); q.pop();
        }
        return res;
    }
};


//桶排序
/*
在建立好数字和其出现次数的映射后，我们按照其出现次数将数字放到对应的位置中去。
这样我们从桶的后面向前面遍历，最先得到的就是出现次数最多的数字，我们找到k个后返回即可
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        vector<vector<int>> bucket(nums.size() + 1);
        vector<int> res;
        for (auto a : nums) ++m[a];
        for (auto it : m) {
            bucket[it.second].push_back(it.first);
        }
        for (int i = nums.size(); i >= 0; --i) {
            for (int j = 0; j < bucket[i].size(); ++j) {
                res.push_back(bucket[i][j]);
                if (res.size() == k) return res;
            }
        }
        return res;
    }
};



