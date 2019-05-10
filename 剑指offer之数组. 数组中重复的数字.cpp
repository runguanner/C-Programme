// 数组



#include <algorithm>
class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false

//下标比较交换法
    
    bool duplicate(int numbers[], int length, int* duplication) {
        //1.数组异常情况处理
        if(numbers == nullptr || length <= 0) return false;
        //2.数组值不符合条件情况处理
        for(int i = 0; i < length; i++) {
            if(numbers[i] < 0 || numbers[i] > length - 1) return false;
        }
        //3.比较a[i]与i：如果相等，i++；如果不相等，比较a[i]与a[a[i]],若相等，为重复数，退出；若不相等就交换。
        for(int i = 0; i < length; i++) {
            while(numbers[i] != i) {
                if(numbers[i] == numbers[numbers[i]]) {
                    *duplication = numbers[i];
                    return true;
                } else {
                    swap(numbers[i], numbers[numbers[i]]);//每个数字最多交换2次（第一次为被交换方，第二次为交换方，到应处位置），故整个程序复杂度为O(n),o(1)
                }
            }
        }
        return false;
    }
};
