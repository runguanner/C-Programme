//最小堆、partition函数


//方法一：最小堆
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {  //最小堆，最后留下来的就是最大的K个数，堆顶就是第K大的数
        priority_queue<int, vector<int>, greater<int> > Q;
        for(int i = 0; i < nums.size(); i++) {  //遍历nums数组
            if(Q.size() < k) {  //如果堆顶元素小于K个，则直接push元素进入堆中
                Q.push(nums[i]);
            }
            else if(Q.top() < nums[i]) {  //如果堆顶比新元素小，则弹出堆顶元素，push入新元素（即替换堆顶）
                Q.pop();
                Q.push(nums[i]);
            }
        }
        return Q.top();  //返回堆顶。即为第K大的数
    }
};

//方法二：partition函数
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while (true) {
            int pos = partition(nums, left, right);
            if (pos == k - 1) return nums[pos];
            else if (pos > k - 1) right = pos - 1;
            else left = pos + 1;
        }
    }
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left], l = left + 1, r = right;
        while (l <= r) {
            if (nums[l] < pivot && nums[r] > pivot) {
                swap(nums[l++], nums[r--]);
            }
            if (nums[l] >= pivot) ++l;
            if (nums[r] <= pivot) --r;
        }
        swap(nums[left], nums[r]);
        return r;
    }
};


#include <algorithm>
class Solution
{
public:   
    int findKthLargest(vector<int>& nums, int k)
    {
        //nth_element(nums.begin(), nums.begin()+k-1, nums.end(),customMore);
        nth_element(nums.begin(), nums.begin()+k-1, nums.end(),greater<int>()); //原理为快排
        //这里直接用STL里的函数，比较函数设置为greater(默认为小数在前)，注意中间(k-1)表示第k个最大的数
        return nums[k-1]; //第k个数，注意这里索引为k-1
       
    }
};
*/
/*
    // 用自定义函数对象排序
    struct
    {
        bool operator()(int a, int b) const
        {  
            return a > b;
        }  
    }customMore;
*/


