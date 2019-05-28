// 最大堆（默认）：heap.top()最大
// 最小堆：heap.top()最小



class Solution {
private:
    priority_queue<int> maxheap;//stl中默认为大顶堆（联系默认的二叉搜索树,根结点较左子树大，中序遍历从小到大，不同的是大顶堆根结点较左右子树都大）
    priority_queue<int, vector<int>, greater<int>> minheap;//小顶堆
public:
    void Insert(int num)
    {
        if(maxheap.empty() || num < maxheap.top()) maxheap.push(num);
        else minheap.push(num);
        
        if(maxheap.size() < minheap.size()) {
            maxheap.push(minheap.top());
            minheap.pop();
        }
        else if(maxheap.size() > minheap.size() + 1) {
            minheap.push(maxheap.top());
            maxheap.pop();
        }
    }

    double GetMedian()
    { 
        return (maxheap.size() > minheap.size()) ? maxheap.top() : (maxheap.top() + minheap.top()) * 0.5;
    }//奇数时，返回中间元素，偶数时，返回中间两个数的平均数，注意浮点数的处理
};
