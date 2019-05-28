class Solution {
public:
    int Sum_Solution(int n) {
        int ans = n;
        ans && (ans += Sum_Solution(n - 1));//使用&&逻辑与的短路特性，前面为假，后面的不计算
        return ans;
    }
};


