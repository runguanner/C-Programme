// 利用减一再做与运算可以使最右边的1变为0，统计1的个数

class Solution {
public:
     int  NumberOf1(int n) {
         int count = 0;
         while(n) {
             count++;
             n = (n - 1) & n;
         }
         return count;
     }
};


