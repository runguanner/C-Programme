// 数组

/*
1、排序
2、计算所有相邻数字间隔总数
3、计算0的个数
4、如果2、3相等，就是顺子
5、如果出现对子，则不是顺子
*/

class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.empty()) return false;
        int num_of_zero = 0;
        int num_of_interval = 0;
        
        sort(numbers.begin(), numbers.end());
        for(int i = 0; i < numbers.size() - 1; i++) {//注意这里是0~n-2的范围，因为后面需要计算numbers[i+1]
            //统计癞子数量
            if(numbers[i] == 0) {
                num_of_zero++;
                continue;//继续循环
            }
            //如果存在对子，直接返回
            if(numbers[i] == numbers[i + 1]) 
                return false;
            //统计间隔数量
            num_of_interval += numbers[i + 1] - numbers[i] - 1;
        }
        if(num_of_zero >= num_of_interval) return true;
        else return false;
    }
};



