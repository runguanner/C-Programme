//考点：STL（nth_element）、partition函数、堆




/*
暴力法：sort, O(nlogn)
方法一：使用自带的stl函数
*/
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(k < 0 || k > input.size()) return vector<int>();
        nth_element(input.begin(),input.begin() + k - 1, input.end());
        vector<int> result(input.begin(), input.begin() + k);
        return result;
    }
};

//方法一：基于partition函数(快排中有用到，stl中也有，但是还是自己实现较好)
/*
多次partition直到枢轴位置为k即可
缺点：会改变输入数组的元素位置
平均O(n)，每次partition 平均O(n),次数未知，真的是O(n)吗，存疑？
思考：最好情况为O(n),最坏情况为O(n^2)（如对于倒序排列的数组）
通过优化partition，比如三数中值枢轴法或随机初始化枢轴法，可以改善时间复杂度
*/
#include <cstdlib>
#include <algorithm>
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(input.empty() || k <= 0 || k > input.size()) return vector<int>();//处理异常输入
        int left = 0; right = input.size() - 1;
        int pivot_pos;
        while(left <= right) {//类似二分查找法
            pivot_pos = partition(input, left, right);//如果要求最大的第k个数，可以对partition函数进行改造
            if(pivot_pos < k - 1) left = pivot_pos + 1;//若在进行一次partition函数以后找到的数的枢轴位置小于目标位置k，那么我们以及目前枢轴左边的数都是小于目标k要找的数，就使得left右移一位
            if(pivot_pos > k - 1) right = pivot_pos - 1;
            else break;//此题要求的是返回最小的前k个数，如果仅返回最小的第k个数，直接在这里return a[pivot_pos]即可
        }
        vector<int> result(input.begin(), input.begin() + k);
        return result;
    }
    
private:
    int partiton(vector<int>& a, int left, int right) {//进行一次partition函数完成一次随机找到的枢轴值，即可判定出这个数是处于第几大的位置的数
        int pivot = left;//枢轴位置
        while(left < right) {
            while(left < right && a[right] >= a[pivot]) right--;//找到本次扫描中第一个不满足枢轴规律的高位数
            while(left < right && a[left] <= a[pivot]) left++;//找到本次扫描中第一个不满足枢轴规律的低位数
            swap(a[left], a[right]);//交换以使满足枢轴规律
        }//最后结果是left和right均指向枢轴位置
        swap(a[left], a[pivot]);//将枢轴移动到位（此时枢轴左边的数均小于枢轴位置的数，右边的数均大于等于枢轴的数）
        return left;//返回枢轴位置
    }
};


/*掌握
方法二：使用堆或者红黑树（平衡二叉搜索树）
用容器存储k个数，遍历输入向量过程中不断更新容器内的数（如果当前数小于容器中的最大值，则插入该数，删除原最大数）
优点：不需要修改输入数组，且适用于处理海量输入数据
O(nlogk)
*/

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(input.empty() || k<=0 || k > input.size()) return vector<int>(); //处理异常输入
        //仿函数中的greater<T>模板，从大到小排序(默认从小到大，左结点<父结点<根结点)
        multiset<int, greater<int>> leastNums;//用红黑树存储这k个数
        for(int ai : input) {
            if(leastNums.size() < k) leastNums.insert(ai);//将前k个元素插入容器
            else {
                //第一个数为最大数
                multiset<int, greater<int>>::iterator greatest_it = leastNums.begin();
                //如果后续元素小于第一个元素，删除第一个，加入当前元素
                if(ai < *greatest_it) {
                    leastNums.erase(greatest_it);
                    leastNums.insert(ai);
                }
            }
        }
        return vector<int>(leastNums.begin(), leastNums.end());
    }
};
