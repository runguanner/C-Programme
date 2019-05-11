// 数组、STL



//由于是有序数组，可以用二分查找,用STL中函数lower_bound 和 upper_bound：O(logn) O(1)

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.empty()) return 0;
        vector<int>::iterator first = lower_bound(data.begin(), data.end(), k);//返回第一个大于等于k的位置
        vector<int>::iterator last = upper_bound(data.begin(), data.end(), k);//返回第一个大于k的位置
        return last - first;
    }
};



// 自己实现lower_bound 和 upper_bound 函数：二分查找O(Logn)、O(1)

class Solution
{
public:
    int getNumberOfK(vector<int>& data, int k) {
        if(data.empty()) return 0;
        int first = my_lower_bound(data, k);
        int last = my_upper_bound(data, k);
        return last - first;
    }
    
private:
    int my_lower_bound(vector<int>& data, int target) {
        int left = 0, right = data.size();//与stl中喜欢把end指向末尾后一个元素的做法类似
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(a[mid] < target) left = mid;//没有单独考虑等于的情况,因为要把“=”放在else里面，因为要找到的是相同元素的第一个target的位置
            else right = mid;
        }
        return right;//最终的情况是left位于小于target的前一位，right位于等于target的第一位
    }
    
    int my_upper_bound(vector<int>& data, int target) {
        int left = 0, right = data.size();//与stl中喜欢把end指向末尾后一个元素的做法类似
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(a[mid] <= target) left = mid;//因为要找到第一个大于目标值的target
            else right = mid;
        }
        return right;//最终的情况是left位于等于target的最后位，right位于等于target的最后位的下一位
    }
};



