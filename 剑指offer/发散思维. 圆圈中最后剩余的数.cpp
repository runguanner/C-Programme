/*
约瑟夫环问题
方法一：用数组模拟过程，删除之后剩下的元素即为最后结果(可用状态数组)
81ms,有点慢
O(nlogm(n)), O(n)
*/
class Solution {
public:
    int lastRemaining_Solution(int n, int m) {
        vector<int> state(n, 1);//定义一个数组存储各元素的状态
        int count_del = 0;//对删除的数字计数
        int count = 0;//用于数哪个数被删除
        int i = 0;//索引
        for( ; count_del < n; i++) {
            if(i == n) i = 0;//构成循环
            if(state[i] == 1) count++;
            if(count == m) {//第m个数时进行“删除”
                count = 0;
                count_del++;
                state[i] = 0;//更改状态，0表示已经被删除
            }
        }//退出循环时，最后一个元素状态被置0,i++会执行一次，故应返回i-1
        return i - 1;
    }
};


/*
约瑟夫环问题
方法一：用数组模拟过程，删除之后剩下的元素即为最后结果(可用状态数组)
81ms,有点慢
O(nlogm(n)), O(n)
*/
class Solution {
public:
    int lastRemaining_Solution(int n, int m) {
        vector<int> state(n, 1);//定义一个数组存储各元素的状态
        int count_del = 0;//对删除的数字计数
        int count = 0;//用于数哪个数被删除
        int i = 0;//索引
        for( ; count_del < n; i++) {
            if(i == n) i = 0;//构成循环
            if(state[i] == 1) count++;
            if(count == m) {//第m个数时进行“删除”
                count = 0;
                count_del++;
                state[i] = 0;//更改状态，0表示已经被删除
            }
        }//退出循环时，最后一个元素状态被置0,i++会执行一次，故应返回i-1
        return i - 1;
    }
};
