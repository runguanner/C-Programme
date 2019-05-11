// 数组



// 法1：保证奇偶排序后奇数与奇数、偶数与偶数之间顺序不变，用一个临时数组存奇数和偶数，O(n), O(n)用空间换时间

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        if(array.empty()) return;
        vector<int> result;
        int n = array.size();
        for(int i = 0; i < n; i++) {
            if(array[i] % 2 == 1) result.push_back(array[i]);
        }
        for(int i = 0; i < n; i++) {
            if(array[i] % 2 == 0) result.push_back(array[i]);
        }
        array = result;
    }
};



// 法2：无法保证调整后奇数与奇数，偶数与偶数之间相对位置不变（可优化，用stable_partition，O(nlogn)）和partition函数比较像：O(n), O(1)
// 双指针法

void reOrderArray(vector<int> &a)
{
    if(a.empty()) return;
    int left = 0, right = a.size()-1;
    while(left < right) //从两边向中间扫描
    {
        //向右移动left指针，直到指向偶数
        while(left<right && a[left]%2 != 0) left++;//若为奇数时，向前移动
        //向左移动right，直到指向奇数
        while(left<right && a[right]%2 == 0) right--;
        //交换
        swap(a[left], a[right]);
    }
}


// partition函数
// 分割函数：选择一枢轴分割序列，并返回其位置


int partition(vector<int>& a, int left, int right)
{
    int pivot = left;           
    while (left < right)    //从序列的两端交替地向中间扫描（在此循环中a[pivot]不动，退出循环后在被交换）
    {
        while (left < right && a[right] >= a[pivot]) right--;//找到本次扫描中第一个不满足枢轴规律的高位数
        while (left < right && a[left] <= a[pivot]) left++;   //找到本次扫描中第一个不满足枢轴规律的低位数
        swap(a[left], a[right]);                        //交换以使满足枢轴规律
    }//最后结果是left和right均指向枢轴位置
    swap(a[left], a[pivot]);//将枢轴移动到位
    return left;            //返回枢轴位置
}


//可以把while中的第二个条件剥离出来，变成一个函数指针，以传入不同规则（判断数字应该在前半部分还是在后半部分）
//STL中partition函数的做法
//如果要保证调整后，各自部分的相对顺序不变，则可用stable_partition函数

//问题举例
//调整数组使奇数在前，偶数在后
//调整数组使小于某个数(pivot)的数在前，大于的在后
//调整数组使负数在前，非负数在后
//调整数组使能被3整数的数在前，不能整数的在后

