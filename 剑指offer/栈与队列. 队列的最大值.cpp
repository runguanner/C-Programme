// https://blog.csdn.net/kk55guang2/article/details/86183220



template<typename T> class QueueWithMax {
public:
    QueueWithMax() :currentIndex(0) {}
    void push_back(T number) { //该函数无需考虑队首索引所指向的元素已经不在窗口中了就弹出的情况，因为滑动窗口相当于整个队列
        while (!maximums.empty() && number >= maximums.back().number) //剔除最大值队列中较当前值小的元素
            maximums.pop_back(); //保证最大值队列中存的是主极大与次极大
        InternaData internaData = {number, currentIndex};
        data.push_back(internaData);
        maximums.push_back(internaData); //push当前元素，有可能其为之后窗口的最大值
        ++currentIndex;
    }
    void pop_front() {
        if (maximums.empty())
           throw new exception("queue is empty.");
        if (maximums.front().index == data.front().index) //如果弹出的元素即为当前最大值，注意把最大值队列队首元素也出队
            maximums.pop_front();
        data.pop_front();
    }
    T max() const {
        if (maximums.empty())
            throw new exception("queue is empty.");
        return maximums.front().number; //最大值队列队首即为当前窗口最大值
    }
private:
    struct InternaData  //自定义数据结构（数+索引）
    {
        T number;
        int index;
    };
    deque<InternaData> data; //存储队列数据
    deque<InternaData> maximums; //窗口相当于整个队列
    int currentIndex;
}; 



