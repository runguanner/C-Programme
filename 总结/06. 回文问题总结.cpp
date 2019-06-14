//总结：
//【1】验证回文串的方法就是两个两个的对称验证是否相等（双指针法）
//【2】寻找回文字串的问题，就要以每一个字符为中心，像两边扩散来寻找回文串，要注意奇偶情况，由于回文串的长度可奇可偶
//    a.对于奇数形式的，我们就从遍历到的位置为中心，向两边进行扩散
//    b.对于偶数情况，我们就把当前位置和下一个位置当作偶数行回文的最中间两个字符，然后向两边进行搜索


//【1】验证回文串类题目
//Leetcode 125.Valid Palindrome
//方法：双指针法，分别从开头和结尾扫描
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        for(int i = 0, j = s.size() - 1; i < j; i++, j--) {
            while(isalnum(s[i]) == false && i < j) i++;
            while(isalnum(s[j]) == false && i < j) j--;
            
            if(toupper(s[i]) != toupper(s[j])) return false;
        }
        return true;
    }
};


//Leetcode 680.Valid Palindrome II
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool validPalindrome(string s) {
        for(int i = 0, j = s.size() - 1; i < j; i++, j--) {
            if(s[i] != s[j]) {//扫描到不匹配字符时，删除其中一个，然后继续扫描
                int i1 = i, j1 = j - 1;//“删除”右边元素
                int i2 = i + 1, j2 = j;//“删除”左边元素
                
                while(i1 < j1 && s[i1] == s[j1]) {
                    i1++;
                    j1--;
                }
                while(i2 < j2 && s[i2] == s[j2]) {
                    i2++;
                    j2--;
                }
                return i1 >= j1 || i2 >= j2;
            }
        }
        return true;
    }
};



//【2】寻找回文串类题目





