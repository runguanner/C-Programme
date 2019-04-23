// 数组、回溯算法


// 这道子集合之二是之前那道 078.Subsets 子集合 的延伸，这次输入数组允许有重复项，其他条件都不变。
// 当处理到第一个2时，此时的子集合为[], [1], [2], [1, 2]，而这时再处理第二个2时，如果在[]和[1]后直接加2会产生重复，所以只能在上一个循环生成的后两个子集合后面加2

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if(nums.empty()) return {};
        vector<vector<int>> res(1);
        sort(nums.begin(), nums.end());
        int size = 1, last = nums[0];  //用last来记录上一个处理的数字
        for(int i = 0; i < nums.size(); ++i) {  
            if(last != nums[i]) {  //判定当前的数字和上面的是否相同
                last = nums[i];
                size = res.size();
            }  //若不同，则循环还是从0到当前子集的个数，若相同，则新子集个数减去之前循环时子集的个数当做起点来循环，这样就不会产生重复了
            int newSize = res.size();
            for(int j = newSize - size; j  < newSize; ++j) {
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
            }
        }
        return res;
    }
};


// 递归
//                       []        
//                  /          \        
//                 /            \     
//                /              \
//             [1]                []
//          /       \           /    \
//         /         \         /      \        
//      [1 2]       [1]       [2]     []
//     /     \     /   \     /   \    / \
// [1 2 2] [1 2]  X   [1]  [2 2] [2] X  []     while(S[i] == S[i + 1]) ++i; 这句话的作用是跳过树中为X的叶节点，因为它们是重复的子集，应被抛弃。

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if(nums.empty()) return {};
        vector<vector<int>> res(1);
        vector<int> out;
        sort(nums.begin(), nums.end());
        getSubsets(nums, 0, out, res);
        return res;
    }
    void getSubsets(vector<int>& nums, int pos, vector<int>& out, vector<vector<int>>& res) {
        res.push_back(out);
        for(int i = pos; i < nums.size(); i++) {
            out.push_back(nums[i]);
            getSubsets(nums, i + 1, out, res);
            out.pop_back();
            while(i + 1 < nums.size() && s[i] == s[i + 1]) ++i;
        }
    }
};
