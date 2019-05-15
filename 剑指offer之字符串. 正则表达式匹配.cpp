// 字符串、递归、动态规划


// 【1】分四种情况讨论
/*
首先，考虑特殊情况：
    1>两个字符串都为空，返回true
    2>当第一个字符串不空，而第二个字符串空了，返回false，因为这样，就无法匹配成功了。
     （而如果第一个字符串空了，第二个字符串非空，还是可能匹配成功的，比如第二个字符串是“a*a*a*a*”,由于‘*’之前的元素可以出现0次，所以有可能匹配成功）
 
之后，就开始匹配第一个字符，这里有两种可能：匹配成功或匹配失败。但考虑到pattern下一个字符可能是‘*’， 这里我们分两种情况讨论：pattern下一个字符为‘*’或不为‘*’：
    1>pattern下一个字符不为‘*’：这种情况比较简单，直接匹配当前字符。如果匹配成功，继续匹配下一个；如果匹配失败，直接返回false。注意这里的“匹配成功”，除了两个字符相同的情况外，还有一种情况，就是pattern的当前字符为‘.’,同时str的当前字符不为‘\0’。
    2>pattern下一个字符为‘*’时，稍微复杂一些，因为‘*’可以代表0个或多个。
        这里把这些情况都考虑到：
        a>当‘*’匹配0个字符时，str当前字符不变，pattern当前字符后移两位，跳过这个‘*’符号；
        b>当‘*’匹配1个或多个时，str当前字符移向下一个，pattern当前字符不变。（这里匹配1个或多个可以看成一种情况，因为：当匹配一个时，由于str移到了下一个字符，而pattern字符不变，就回到了上边的情况a；当匹配多于一个字符时，相当于从str的下一个字符继续开始匹配）
*/
class Solution {
public:
    bool match(char* str, char* pattern)
    {
        if(*str == '\0' && *pattern == '\0') return true;//两个字符串都为空，返回true
        if(*str != '\0' && *pattern == '\0') return false;//当第一个字符串不空，而第二个字符串空了，返回false
        //之后就开始匹配第一个字符，这里有两种可能：匹配成功或匹配失败。但考虑到pattern下一个字符可能是‘*’，这里我们分两种情况讨论：pattern下一个字符为‘*’或不为‘*’：
        if(*(pattern + 1) != '*') {//pattern下一个字符不为‘*’这种情况比较简单，直接匹配当前字符。如果匹配成功，继续匹配下一个；如果匹配失败，直接返回false
            if(*str == *pattern || (*str != '\0' && *pattern == '.')) return match(str + 1, pattern + 1);
            else return false;
        } else {//*(pattern + 1) == '*'时
            //当‘*’匹配0个字符时，str当前字符不变，pattern当前字符后移两位，跳过这个‘*’符号；当‘*’匹配1个或多个时，str当前字符移向下一个，pattern当前字符不变
            if(*str == *pattern || (*str != '\0' && *pattern == '.')) return match(str, pattern + 2) || match(str + 1, pattern);
            else return match(str, pattern + 2);
        }
    }
};


class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();  //若p为空，若s也为空，返回true，反之返回false。
        if(p.size() == 1) {  //若p的长度为1，若s长度也为1，且相同或是p为'.'则返回true，反之返回false。
            return (s.size() == 1 && (s[0] == p[0] || p[0] == '.'));
        }
        if(p[1] != '*') {  //若p的第二个字符不为*，若此时s为空返回false，否则判断首字符是否匹配，且从各自的第二个字符开始调用递归函数匹配。
            if (s.empty()) return false;
            return (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
        }
        while(!s.empty() && (s[0] == p[0] || p[0] == '.')) {  //若p的第二个字符为*，进行下列循环，条件是若s不为空且首字符匹配（包括p[0]为点）。
            if (isMatch(s, p.substr(2))) return true;  //调用递归函数匹配s和去掉前两个字符的p（假设此时的星号作用是让前面字符出现0次，验证是否匹配）
            s = s.substr(1);  //否则s去掉首字母（因为首字母匹配了可以去掉s的首字母，而p由于星号的作用，可以有任意个首字母，不需要去掉）继续进行循环。
        }
        return isMatch(s, p.substr(2));  //比如s="", p="a*"，由于s为空，不会进入任何的if和while，只能到最后的return来比较了，返回true。
    }
};
