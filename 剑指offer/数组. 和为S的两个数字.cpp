// 双指针（从两边开始往中间扫描）



class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        if(array.size() < 2) return vector<int>();
        
        int min_product = INT_MAX;
        int left = 0, right = array.size() - 1;
        int a1, a2;
        bool find_flag = false;
        while(left < right) {
            int cursum = array[left] + array[right];
            if(cursum > sum) right--;
            else if(cursum < sum) left++;
            else {
                if(array[left] * array[right] < min_product) {
                    find_flag = true;
                    min_product = array[left] * array[right];
                    a1 = array[left];
                    a2 = array[right];
                }
                left++;
            }
        }
        if(find_flag) return vector<int>{a1, a2};
        else return vector<int>();
    }
};
