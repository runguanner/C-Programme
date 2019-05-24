// 二分查找、堆、upper_bound函数

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> q;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                q.emplace(matrix[i][j]);
                if(q.size() > k) q.pop();
            }
        }
        return q.top();
    }
};


/*
 方法一：二分查找法，整体二分查找，在每行二分查找，统计每行小于等于目标数的个数
 upper_bound：函数是查找第一个大于目标数的元素，如果目标数在比该行的尾元素大，则upper_bound返回该行元素的个数，如果目标数比该行首元素小，则upper_bound返回0。
 我们遍历完所有的行可以找出中间数是第几小的数，然后k比较，进行二分查找，left和right最终会相等，并且会变成数组中第k小的数字
*/
class Solution
{
public:
    int kthSmallest(vector<vector<int>>& matrix, int k)
    {
        int n = matrix.size();
        int left = matrix[0][0], right = matrix[n - 1][n - 1];
        int mid = 0;
        while(left < right) //扫描整个矩阵，这里left,right为值，一般的二分查找为索引
        {
            mid = left + (right-left)/2;
            int count = 0;
            for (int i = 0; i < n; i++) //扫描每行
            {
                int pos = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin(); //用二分查找查找第一个大于目标数的位置，可统计该行中比目标数小的数量
                count += pos;
            }
            if (count < k) //这里赋left = mid+1和right = mid不是太懂 
                left = mid + 1; //比k小时，left往中间移,增大新mid,增大count
            else
                right = mid; //比k大或者等于时，right往中间移
        } //退出循环时left = right，移动至第k小的元素处
        return left;
    }
};


/*
方法二：二分查找 + 直接统计法（利用行列有序性）
我们并不用对每一行都做二分搜索法，我们注意到每列也是有序的，我们可以利用这个性质，依次统计每一列中小于等于目标值的元素数量
1.从数组的左下角开始查找（i = n-1,j = 0），扫描至矩阵上边界或者右边界，共执行次数最多2n
2.如果a[i][j] <= target，因为当前元素以上的元素均比目标值小，cnt += i+1，继续下一列的判断（j++）；
3.如果a[i][j] > target，则向上移一位（i--），这样我们也能算出cnt的值。
复杂度为O(logm * n)
*/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k)
    {
        int left = matrix[0][0], right = matrix.back().back();
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            int cnt = search_less_equal(matrix, mid);
            
            if (cnt < k) 
                left = mid + 1;
            else 
                right = mid;
        }
        return left;
    }
    int search_less_equal(vector<vector<int>>& matrix, int target)
    {
        int n = matrix.size(), i = n - 1, j = 0, res = 0; //从矩阵左下角开始扫描
        while (i >= 0 && j <= n-1) //如果行或列超出边界就退出循环
        {
            //统计每列小于等于目标值的数量
            if (matrix[i][j] <= target) //当前元素小于或等于目标值
            {
                res += i + 1; //统计每列小于等于目标值的数量
                j++; //扫描下一列
            } else //当前元素比目标值大
            {
                i--; //扫描上一行
            }
        }
        return res;
    }
};

