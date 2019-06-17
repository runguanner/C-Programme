//48 最长不含重复字符的子字符串（3. Longest Substring Without Repeating Characters）
//方法：Sliding Window 本质是枚举法 O(n)
#include <unordered_set>
#include <algorithm>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {     
        unordered_set<char> set; //用hash表存滑动窗中的数，方便查找是否有重复的数（用vector应该也可以，只不过hash表如果查找得到元素时效率高一点）
        int left = 0,right = 0; //双指针，指向子串区间的左右两端点
        int max_length = 0;
       
        while(right < s.size() {
            if(set.find(s[right]) == set.end())//如果不是重复字符，插入字符，更新最大长度
            {
                set.insert(s[right++]); //插入右边元素，右指针加一
                max_length = max(max_length, int(set.size())); //由于max函数只能对同类型的进行比较，这里强制转换
            }
            else//如果为重复字符，则移除区间首字符，直到set中不再含此字符为止（会多次判断，多次执行移除操作） 
            {
                set.erase(s[left++]); //移除左边元素，左指针加一
            }
        }
        return max_length;
    }
};



//剑指 59.队列（滑动窗口）的最大值
//方法一：暴力法（每个滑动窗口都计算最大值，O(nk),O(1), k为滑动窗的长度）
//方法二：用一个双端队列来存各阶段的最大值，用O(1)时间得到滑动窗口的最大值,队列最大长度为k：O(n),O(k)（存索引，这样可以判断窗口位置，从而决定是否移除队首元素）
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
        vector<int> result;
        if(size > num.size() || size < 1) return result;
        
        deque<int> index;//双端队列
        //队列中存的元素中，队首元素为当前窗口下的最大值，队首外的元素为最大值之后的次大值（队列中索引指向元素为从大到小，均为局部极大值点）
        for(unsigned int i = 0; i < num.size(); i++) {
            while(!index.empty() && num[i] >= num[index.back()]) 
                index.pop_back();
            index.push_back(i);
            
            if(!index.empty() && i - index.front() + 1 > size)
                index.pop_front();
            
            if(i >= size - 1)
                result.push_back(num[index.front()]);
        }
        return result;
    }
};
              
              
