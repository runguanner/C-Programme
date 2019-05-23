class Solution {
public:
    void push(int value) {
        s1.push(value);
        if(s2.empty() || value <= s2.top()) s2.push(value);//如果s2为空，或者存入数小于等于之前最小数，则传入s2
    }
    void pop() {
        if(s1.top() == s2.top()) s2.pop();//如果pop的是当前极小值，则s2也跟着pop
        s1.pop();
    }
    int top() {
        return s1.top();
    }
    int min() {
        return s2.top();
    }
    
private:
    stack<int> s1;//存数据
    stack<int> s2;//存各阶段最小数
};


