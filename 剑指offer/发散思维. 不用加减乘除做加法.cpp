// 用异或代替加运算（不考虑进位）
// 用与运算+左移运算代替进位



class Solution {
public:
    int Add(int num1, int num2)
    {
        int sum = num1;
        int carry = num2;
        while(carry != 0) {
            sum = num1 ^ num2;//用异或代替加运算（不考虑进位）
            carry = (num1 & num2) << 1;//用与运算+左移运算代替进位
            
            num1 = sum;
            num2 = carry;
        }
        return sum;
    }
};



