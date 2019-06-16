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


//Leetcode 234.Palindrome Linked List 回文链表 
//方法一：利用栈（链表比字符串难的地方就在于不能通过坐标来直接访问，而只能从头开始遍历到某个位置）：O(n^2),O(n)
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool palindromeList(ListNode *head) {
        ListNode *cur = head;
        stack<int> st;
        while(cur) {
            st.push(cur->val);
            cur = cur->next;
        }
        while(head) {
            int t = st.top();
            st.pop();
            if(head->val != t) return false;
            head = head->next;
        }
        return true;
    }
};
//方法二：使用快慢指针
class Solution {
public:
    bool isPalindromeList(ListNode *head) {
        if(!head || !head->next) return true;
        ListNode *slow = head, *fast = head;
        stack<int> st{{head->val}};
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            st.push(slow->val);
        }
        
        if(!fast->next) st.pop();
        while(slow->next) {
            slow = slow->next;
            int tmp = st.top();
            st.pop();
            if(tmp != slow->val) return false;
        }
        return true;
    }
};
//方法三：O(1)的空间：在找到中点后，将后半段的链表翻转一下，这样我们就可以按照回文的顺序比较了
class Solution {
public:
    bool isPalindromeList(ListNode *head) {
        if(!head || !head->next) return true;
        ListNode *slow = head, *fast = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *last = slow->next, *pre = head;
        while(last->next) {
            ListNode *tmp = last->next;
            last->next = tmp->next;
            tmp->next = slow->next;
            slow->next = tmp;
        }
        
        while(slow->next) {
            slow = slow->next;
            if(pre->val != slow->val) return false;
            pre = pre->next;
        }
        return true;
    }
};


//Leetcode 9.Palindrome Number 验证回文数
//方法一：
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int div = 1;
        while(x / div >= 10) div *= 10;
        while(x > 0) {
            int left = x / div;
            int right = x % 10;
            if(left != right) return false;
            x = (x % div) / 10;
            div /= 100;
        }
        return true;
    }
};
//方法二：
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x % 10 == 0  && x != 0)) return false;
        return reverse(x) == x;
    }
    
    int reverse(int x) {
        int res = 0;
        while(x != 0) {
            if(res > INT_MAX / 10) return -1;
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
};



//【2】寻找回文串类题目
//Leetcode 5.Longest Palindromic Substring 最长回文子串 
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2) return s;
        int n = s.size(), maxLen = 0, start = 0;
        for (int i = 0; i < n - 1; ++i) {
            searchPalindrome(s, i, i, start, maxLen);
            searchPalindrome(s, i, i + 1, start, maxLen);
        }
        return s.substr(start, maxLen);
    }
    void searchPalindrome(string s, int left, int right, int& start, int& maxLen) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left; ++right;
        }
        if (maxLen < right - left - 1) {
            start = left + 1;
            maxLen = right - left - 1;
        }
    }
};



