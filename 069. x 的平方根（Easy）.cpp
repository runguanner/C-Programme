// 数学、二分查找

// 二分搜索法来找平方根

class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1) return x;
        int left = 0, right = x;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(x / mid >= mid) left = mid + 1;
            else right = mid;
        }
        return right - 1;
    }
};


// 牛顿迭代法：注意为了防止越界，声明为长整型

class Solution {
public:
    int mySqrt(int x) {
        long res = x;
        while(res * res > x) {
            res = (res + x / res) / 2;
        }
        return res;
    }
};
