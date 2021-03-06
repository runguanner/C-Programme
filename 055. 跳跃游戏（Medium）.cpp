// 贪心算法、动态规划、数组


// 动态规划
// 维护一个一位数组dp，其中dp[i]表示达到i位置时剩余的步数，难点在于推导状态转移方程：dp[i]=max(dp[i-1],nums[i-1])-1。

class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1], nums[i - 1]) - 1;  //下一个位置的剩余步数（dp[i]值）等于当前位置的剩余步数（dp[i-1]值）和当前位置的跳力（跳力就是原数组中每个位置的数字）中的最大值，即最远距离减去1
            if(dp[i] < 0) return false;  //如果当某一个时刻dp数组的值为负了，说明无法抵达当前位置
        }
        return true;
    }
};


// 贪婪算法Greedy Algorithm（更优）

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), reach = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(i > reach || reach >= n - 1) break;  //i>reach条件是处于位置i时，遍历其能到达的reach这个范围内的所有位置，
            reach = max(reach, i + nums[i]);  //并且计算遍历到的每一个位置的i+nums[i]，判断得到max是否大于n-1（终点位置最远的距离）
        }
        return reach >= n - 1;
    }
};
