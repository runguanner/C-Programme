// 数组、定义新cmp


class Solution {
public:
    static bool cmp(int a, int b) {//必须定义成static类型才能被sort使用
        string A = to_string(a) + to_string(b);
        string B = to_string(b) + to_string(a);
        return A < B;//利用字符串的比较方法
    }
    string PrintMinNumber(vector<int> numbers) {
        sort(numbers.begin(), numbers.end(), cmp);
        string result;
        for(int nums : numbers) result += to_string(nums);
        return result;
    }
};//O(nlogn)


//定义新的大小关系，对vector容器内的数据进行排序,按照 将a和b转为string后,若 a＋b < b+a,则a排在b之前的规则排序,
//如 2、21 因为 21 2 < 2 21 所以排序后为 21 2 
//to_string() 可以将int转化为string，方便组合后比较，不用管各数的位数
