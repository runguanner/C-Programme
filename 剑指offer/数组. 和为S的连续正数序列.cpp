// 双指针（往后遍历）



class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> result;
        if(sum < 3) return result;//至少需包含两个数 
        int left = 1, right = 2;
        while(left < right) {//注意从开头开始扫描，直到left与right相遇
            int cursum = (left + right) * (right - left + 1) / 2;//用等差数列的求和公式
            if(cursum < sum) right++;
            else if(cursum > sum) left++;
            else {
                vector<int> temp;
                for(int i = left; i <= right; i++) temp.push_back(i);
                result.push_back(temp);//push符合要求的连续正数序列
                left++;//继续下个序列的寻找
            }
        }//最后退出循环时，left = right = sum / 2 + 1的位置，比如找10，最后指向 5、6，再均指向6，退出循环
        return result;
    }
};
