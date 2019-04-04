// 贪心算法

class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0, n = nums.size(), i = 0, cur = 0;  //变量cur和pre分别来保存当前的能到达的最远位置和之前能到达的最远位置
        while(cur < n - 1) {
            ++res;
            int pre = cur;  //只要cur未达到最后一个位置则循环继续，pre先赋值为cur的值，表示上一次循环后能到达的最远位置
            for(; i <= pre; i++) {
                cur = max(cur, i + nums[i]);  //更新cur的方法是比较当前的cur和i + nums[i]之中的较大值
            }
            if(pre == cur) return -1;  //May not need this:题目中未说明是否能到达末尾，还可以判断此时pre和cur是否相等，如果相等说明cur没有更新，即无法到达末尾位置，返回-1
        }
        return res;
    }
};


class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0, n = nums.size(), last = 0, cur = 0;  //cur是当前能到达的最远位置，last是上一步能到达的最远位置
        for (int i = 0; i < n - 1; ++i) {  //遍历数组，首先用i+nums[i]更新cur
            cur = max(cur, i + nums[i]);
            if (i == last) {  //如果当前位置到达了last，即上一步能到达的最远位置，说明需要再跳一次了
                last = cur;  //将last赋值为cur进行下一次最远范围的遍历，并且步数res自增1
                ++res;
                if (cur >= n - 1) break;  //判断如果cur到达末尾了，直接break掉即可
            }
        }
        return res;
    }
};
