class Solution
{
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV)
    {
        if(pushV.empty() || popV.empty()) return false;
        stack<int> s;
       
        //用于标识弹出序列的位置
        int popIndex = 0;
        for(int i = 0; i<pushV.size(); i++) //扫描入栈序列
        {
            s.push(pushV[i]); //push元素直到栈顶元素为pop序列中的元素
            while(!s.empty() && s.top() == popV[popIndex]) //相等时，辅助栈出栈，弹出序列索引加一
            {
                s.pop();
                popIndex++;
            }
        }
       
        return s.empty(); //如果为空，则说明入栈序列和出栈序列相匹配，为true,否则为false
    }
};



