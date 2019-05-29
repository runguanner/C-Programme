//双向队列deque、multiset、priority_queue（最大堆）



// 双向队列O(n)
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> result;
        if(size > num.size() || size < 1) return result;
        
        deque<int> index;//双端队列；队列中存的元素中，队首元素为当前窗口下的最大值，队首外的元素为最大值之后的次大值（队列中索引指向元素为从大到小，均为局部极大值点）
        for(unsigned int i = 0; i < num.size(); i++) {
            while(!index.empty() && num[i] >= num[index.back()]) 
                index.pop_back();//从队尾依次弹出队列中比当前num值小的元素，同时也能保证队列首元素为当前窗口最大值下标
            index.push_back(i);//插入当前索引值，因为可能为其他窗口下的最大值
            if(!index.empty() && i - index.front() + 1 > size)
                index.pop_front();//如果队首索引所指向的元素已经不在窗口中了就弹出
            if(i >= size - 1) 
                result.push_back(num[index.front()]);
        }
        return result;
    }
};


/*
方法一：暴力法
每个滑动窗口都计算最大值，
O(nk),O(1), k为滑动窗的长度
*/


/*
方法二：用一个双端队列来存各阶段的最大值
用O(1)时间得到滑动窗口的最大值,队列最大长度为k
O(n),O(k)
存索引，这样可以判断窗口位置，从而决定是否移除队首元素
*/
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, int k) {
        vector<int> res;
        multiset<int> st;
        for(int i = 0; i < num.size(); i++) {
            //若超过了k，则需要把左边界值删除，这里不能直接删除 nums[i-k]，因为集合中可能有重复数字，我们只想删除一个，而 erase 默认是将所有和目标值相同的元素都删掉。
            //所以我们只能提供一个 iterator，代表一个确定的删除位置，先通过 find() 函数找到左边界 nums[i-k] 在集合中的位置，再删除即可。
            if(i >= k) st.erase(st.find(num[i - k]));
            st.insert(num[i]);
            //看若 i >= k-1，说明窗口大小正好是k，就需要将最大值加入结果 res 中，而由于 multiset 是按升序排列的，最大值在最后一个元素，我们可以通过 rbegin() 来取出。
            if(i >= k - 1) res.push_back(*st.rbegin());
        }
        return res;
    }
};


class Solution {
public:
    vector<int> maxInWindows(vector<int>& nums, int k) {
        vector<int> res;
        priority_queue<pair<int, int>> q;//可以使用优先队列来做（最大堆）不过里面放一个 pair 对儿，由数字和其所在位置组成的，这样就知道每个数字的位置了，而不用再进行搜索了。
        for(int i = 0; i < nums.size(); i++) {
            while(!q.empty() && q.top().second < i - k) q.pop();//q.top().second（位置坐标）
            q.push(nums[i], i);
            if(i >= k - 1) res.push_back(q.top().first);
        }
        return res;
    } 
};


