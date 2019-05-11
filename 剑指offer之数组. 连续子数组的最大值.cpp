// 数组、动态规划



// 动态规划法：O(n)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN, curSum = 0;
        for (int num : nums) {
            curSum = max(curSum + num, num);
            res = max(res, curSum);
        }
        return res;
    }
};



// 递归、分治法：O(nlgn)
// 具体过程：将数组分为左子数组、右子数组、跨越中点的子数组问题


class Solution
{
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        return helper(nums, 0, (int)nums.size() - 1);
    }
    
    int helper(vector<int>& nums, int left, int right) {
        if(left >= right) return nums[left];
        int mid = left + (right - left) / 2;
        int lMax = helper(nums, left, mid - 1);
        int rMax = helper(nums, mid + 1, right);
        int mMax = nums[mid], t = mMax;
        for(int i = mid - 1; i >= left; i--) {
            t += nums[i];
            mMax = max(mMax, t);
        }
        t = mMax;
        for(int i = mid + 1; i <= right; i++) {
            t += nums[i];
            mMax = max(mMax, t);
        }
        return max(mMax, max(lMax, rMax));
    }
};


