//分治法、递归、迭代




//分治法：O(logn) 掌握
class Solution {
public:
    double Power(double base, int exponent) {
        if(exponent < 0) return 1.0 / myPower(base, exponent);
        else return myPower(base, exponent);
    }
    
private:
    double myPower(double x, int n) {
        if(n == 0) return 1;
        double res = myPower(x, n / 2);
        if(n % 2 == 0) return res * res;
        else return res * res * x;
    }
};


//迭代法
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        unsigned int p;
        if(n < 0) {
            p = -n;
            x = 1 / x;
        }
        else {
            p = n;
        }
        
        double ans = 1;
        while(p > 0) {
            if(p % 2 == 1) ans *= x;
            x *= x;
            p /= 2;
        }
        return ans;
    }
};



