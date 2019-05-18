// 【1】Permutations 全排列（无重复元素）

// 此解法的最终生成顺序为：[[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1]]
class Solution
{
public:
    vector<vector<int>> permute(vector<int>& num) {
        vector<vector<int>> res;
        vector<int> out, visited(num.size(), 0);
        permuteDFS(num, 0, visited, out, res);
        return res;
    }

    void permuteDFS(vector<int>& num, int level, vector<int>& visited, vector<int>& out, vector<vector<int>>& res) {
        if(level == num.size()) {
            res.push_back(out);
            return;
        }
        for(int i = 0; i < num.size(); i++) {
            if(visited[i] == 1) continue;
            visited[i] = 1;
            out.push_back(num[i]);
            permuteDFS(num, level + 1, visited, out, res);
            out.pop_back();
            visited[i] = 0;
        }
    }
};
// 此解法的最终生成顺序为：[[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,2,1], [3,1,2]]
class Solution {
public:
    vector<vector<int>> permute(vector<int>& num) {
        vector<vector<int>> res;
        permuteDFS(num, 0, res);
        return res;
    }
    void permuteDFS(vector<int>& num, int start, vector<vector<int>>& res) {
        if (start >= num.size()) res.push_back(num);
        for (int i = start; i < num.size(); ++i) {
            swap(num[start], num[i]);
            permuteDFS(num, start + 1, res);
            swap(num[start], num[i]);
        }
    }
};
// 此解法运用到下面的函数，也是STL内置函数：next_permutation()并且同样的代码也适用于含有重复元素的Permutations II（相当于自动去重了）
class Solution {
public:
    vector<vector<int>> permute(vector<int>& num) {
        vector<vector<int>> res;
        sort(num.begin(), num.end());
        res.push_back(num);
        while (next_permutation(num.begin(), num.end())) {
            res.push_back(num);
        }
        return res;
    }
};






// 【2】Permutations II 全排列II（有重复元素）

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> out, visited(nums.size(), 0);
        sort(nums.begin(), nums.end());
        permuteUniqueDFS(nums, 0, visited, out, res);
        return res;
    }
    void permuteUniqueDFS(vector<int>& nums, int level, vector<int>& visited, vector<int>& out, vector<vector<int>>& res) {
        if (level >= nums.size()) {res.push_back(out); return;}
        for (int i = 0; i < nums.size(); ++i) {
            if (visited[i] == 1) continue;//由于递归的for都是从0开始，难免会重复遍历到数字，不能重复使用数字就靠visited数组来保证，这就是第一个if剪枝的意义所在
            //关键来看第二个if剪枝的意义，这里说当前数字和前一个数字相同，且前一个数字的visited值为0的时候，必须跳过。
            //前一个数visited值为0，并不代表前一个数字没有被处理过，也可能是递归结束后恢复状态时将visited值重置为0了
            if (i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == 0) continue;
            visited[i] = 1;
            out.push_back(nums[i]);
            permuteUniqueDFS(nums, level + 1, visited, out, res);
            out.pop_back();
            visited[i] = 0;
        }
    }
};

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        permute(nums, 0, res);
        return res;
    }
    void permute(vector<int> nums, int start, vector<vector<int>>& res) {
        if (start >= nums.size()) res.push_back(nums);
        for (int i = start; i < nums.size(); ++i) {
            if (i != start && nums[i] == nums[start]) continue;
            swap(nums[i], nums[start]);
            permute(nums, start + 1, res);
        }
    }
};

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> res;
        permute(nums, 0, res);
        return vector<vector<int>> (res.begin(), res.end());
    }
    void permute(vector<int>& nums, int start, set<vector<int>>& res) {
        if (start >= nums.size()) res.insert(nums);
        for (int i = start; i < nums.size(); ++i) {
            if (i != start && nums[i] == nums[start]) continue;
            swap(nums[i], nums[start]);
            permute(nums, start + 1, res);
            swap(nums[i], nums[start]);
        }
    }
};






// 【3】Next Permutation 下一个排列 

/* 
   有如下的一个数组：1 2 7 4 3 1则下一个排列为：1 3 1 2 4 7
   观察原数组可以发现，如果从末尾往前看，数字逐渐变大，到了2时才减小的，然后我们再从后往前找第一个比2大的数字，是3，那么我们交换2和3，再把此时3后面的所有数字转置一下即可，步骤如下：
   1　　2　　7　　4　　3　　1
   1　　2　　7　　4　　3　　1
   1　　3　　7　　4　　2　　1
   1　　3　　1　　2　　4　　7
*/
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int i, j, n = num.size();
        for (i = n - 2; i >= 0; --i) {
            if (num[i + 1] > num[i]) {
                for (j = n - 1; j > i; --j) {
                    if (num[j] > num[i]) break;
                }
                swap(num[i], num[j]);
                reverse(num.begin() + i + 1, num.end());
                return;
            }
        }
        reverse(num.begin(), num.end());
    }
};






// 【4】Permutation Sequence 序列排序（http://www.cnblogs.com/grandyang/p/4358678.html）
/* 规律：
   a1 = k / (n - 1)!
   k1 = k
   a2 = k1 / (n - 2)!//（1）
   k2 = k1 % (n - 2)!//（2）
   ...
   an-1 = kn-2 / 1!
   kn-1 = kn-2 % 1!
   an = kn-1 / 0!
   kn = kn-1 % 0! 
*/
class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        string num = "123456789";
        vector<int> f(n, 1);
        for (int i = 1; i < n; ++i) f[i] = f[i - 1] * i;//构造数乘
        --k;//减1
        for (int i = n; i >= 1; --i) {
            int j = k / f[i - 1];//（1）
            k %= f[i - 1];//（2）
            res.push_back(num[j]);
            num.erase(j, 1);
        }
        return res;
    }
};






// 【5】Combinations 组合项（DFS）
// 根据以往的经验，像这种要求出所有结果的集合，一般都是用DFS调用递归来解。
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> out;
        helper(n, k, 1, out, res);
        return res;
    }
    void helper(int n, int k, int level, vector<int>& out, vector<vector<int>>& res) {
        if (out.size() == k) {res.push_back(out); return;}
        for (int i = level; i <= n; ++i) {
            out.push_back(i);
            helper(n, k, i + 1, out, res);
            out.pop_back();
        }
    }
};
/*
C(4, 2) = C(3, 1) + C(3, 2)
C(3, 1) 的所有情况：[1], [2], [3]
C(3, 2) 的所有情况：[1, 2], [1, 3], [2, 3]
C(3, 1) 的每种情况后面都加上4，于是变成了[1, 4], [2, 4], [3, 4]，加上C(3, 2) 的所有情况：[1, 2], [1, 3], [2, 3]，正好就得到了 n=4, k=2 的所有情况
*/
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if (k > n || k < 0) return {};
        if (k == 0) return {{}};
        vector<vector<int>> res = combine(n - 1, k - 1);
        for (auto &a : res) a.push_back(n);
        for (auto &a : combine(n - 1, k)) res.push_back(a);
        return res;
    }
};






// 【6】Combination Sum 组合之和
// 像这种结果要求返回所有符合要求解的题十有八九都是要利用到递归
// 即都是需要另写一个递归函数，这里我们新加入三个变量，start记录当前的递归到的下标，out为一个解，res保存所有已经得到的解，每次调用新的递归函数时，此时的target要减去当前数组的的数
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> out;
        combinationSumDFS(candidates, target, 0, out, res);
        return res;
    }
    void combinationSumDFS(vector<int>& candidates, int target, int start, vector<int>& out, vector<vector<int>>& res) {
        if (target < 0) return;
        if (target == 0) {res.push_back(out); return;}
        for (int i = start; i < candidates.size(); ++i) {
            out.push_back(candidates[i]);
            combinationSumDFS(candidates, target - candidates[i], i, out, res);
            out.pop_back();
        }
    }
};



