//位运算、数组、回溯算法


// Non-recursion
// 当前层的集合 = 上一层的集合 + 上一层的集合加入当前层处理的元素得到的所有集合（其中树根是空集），因此可以从第二层开始（第一层是空集合）迭代地求最后一层的所有集合（即叶子节点）

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> >res(1);  //开始加入一个空集[]
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            int resSize = res.size();
            for(int j = 0; j < resSize(); j++) {
                res.push_back(res[j]);  //(1)
                res.back().push_back(nums[i]);  //(2)这两句是点睛之笔
            }
        }
        return res;
    }
};


// Recursion

class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int> > res;
        vector<int> out;
        sort(nums.begin(), nums.end());
        getSubsets(nums, 0, out, res);
        return res;
    }
    void getSubsets(vector<int> &nums, int pos, vector<int> &out, vector<vector<int> > &res) {
        res.push_back(out);
        for (int i = pos; i < nums.size(); ++i) {
            out.push_back(nums[i]);
            getSubsets(nums, i + 1, out, res);
            out.pop_back();
        }
    }
};


// 位运算

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > res;
        sort(S.begin(), S.end());
        int max = 1 << S.size();  //把1左移S.size()位，如i << 3 = 8
        for (int k = 0; k < max; ++k) {
            vector<int> out = convertIntToSet(S, k);
            res.push_back(out);
        }
        return res;
    }
    vector<int> convertIntToSet(vector<int> &S, int k) {
        vector<int> sub;
        int idx = 0;
        for (int i = k; i > 0; i >>= 1) {
            if ((i & 1) == 1) {
                sub.push_back(S[idx]);
            }
            ++idx;
        }
        return sub;
    }
};
