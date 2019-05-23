class Solution
{
public:
    void push(int node) {
        while(!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
        stack1.push(node);
        while(!stack2.empty()) {
            stack1.push(stack2.top());
            stack2.pop();
        }
    }

    int pop() {
        int top_element = stack1.top();
        stack1.pop();
        return top_element;
    }

private:
    stack<int> stack1;//主栈（我们做的实现操作都在这个栈的函数上实现）
    stack<int> stack2;//辅助栈
};


