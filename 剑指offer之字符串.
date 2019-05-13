// 字符串



// 方法一：一个字符一个字符的处理，得到单词之后插入到结果字符串前面

class Solution {
public:
    string ReverseSentence(string str) {
        string result, tmp;
        for(char ch : str) {//一个字符一个字符的处理
            if(ch == ' ') {
                result = ' ' + tmp + result;
                tmp = "";
            }
            else tmp += ch;
        }
        if(tmp.size()) result = tmp + result;
        return result;
    }
};


// 方法二：先整体翻转，再翻转单词内部

 void ReverseWord(string &str, int s, int e)
 {
    while(s < e)
    swap(str[s++], str[e--]);
 }
 
 string ReverseSentence(string str)
 {
      ReverseWord(str, 0, str.size() - 1); //先整体翻转
      int left = 0, right = 0;
      int i = 0;
      while(i < str.size())
      {
          while(i < str.size() && str[i] == ' ') //空格跳过
           i++;
          left = right = i; //记录单词的第一个字符的位置
          while(i < str.size() && str[i] != ' ') //不是空格 找单词最后一个字符的位置
          {
           right++;
          }
          ReverseWord(str, left, right - 1); //局部翻转
          i = right;
      }
      return str;
 }
