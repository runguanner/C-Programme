// 数组、二分查找



// 考虑到数组中有重复的情况：如[2,2,2,0,1,1,2]  平均O(logn),最坏O(n)

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.empty()) return 0;
        if(rotateArray.size() == 1) return rotateArray[0];
        
        int res = rotateArray[0];
        int left = 0, right = rotateArray.size() - 1;
        if(rotateArray[left] >= rotateArray[right]) {
            while(left < right - 1) {
                int mid = (left + right) / 2;
                if(rotateArray[left] < rotateArray[mid]) {
                    res = min(res, rotateArray[left]);
                    left = mid;
                } else if (rotateArray[left] > rotateArray[mid]) {
                    res = min(res, rotateArray[right]);
                    right = mid;
                } else //若left与mid指向数字相等，将left右移一位,略过相同数字
                    left++;
            }//退出时，left = right -1,left指向左子数组的末尾或右子数组的开头
            res = min(res, rotateArray[left]);
            res = min(res, rotateArray[right]);
            return res;
        }
        else return rotateArray[0];//若无旋转
    }
};



// 不含重复数的情况：如[3,4,5,1,2]  O(logn), O(1)

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1;
        if (nums[left] > nums[right]) //若有旋转
        {
            while (left < right - 1)
            {
                int mid = (left + right) / 2;
                if (nums[left] < nums[mid]) //若中间的数大，移动left指针到中间
                    left = mid;
                else                        //若中间的数小，移动right指针到中间
                    right = mid;
            }//退出时，left = right -1,left指向左子数组的末尾，right指向右子数组的开头
            return nums[right];
        }
        else //若无旋转，直接返回第一个数
            return nums[0];
    }
};
/*
其他写法
    if (nums[mid] < nums[right]) //这种写法表示，右半段是有序的
        right = mid;
    else                        
        left = mid;
*/
