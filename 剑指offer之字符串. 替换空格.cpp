// 字符串



/*
问题1：替换字符串，是在原来的字符串上做替换，还是新开辟一个字符串做替换！
问题2：在当前字符串替换，怎么替换才更有效率（不考虑java里现有的replace方法）。
      从前往后替换，后面的字符要不断往后移动，要多次移动，所以效率低下
      从后往前，先计算需要多少空间，然后从后往前移动，则每个字符只为移动一次，这样效率更高一点。
*/
class Solution
{
public:
    void replaceSpace(char *str,int length)
    {
        int spacenum = 0;
        for(int i = 0; i<length; i++) //统计空格数
        {
            if(str[i] == ' ') spacenum++;
        }
       
        int newlength = length + spacenum*2; //新长度
        int indexold = length - 1, indexnew = newlength - 1; //设置新旧两个指针
        for(; indexold >= 0 && indexnew>indexold; indexold--) //indexold从后往前扫描整个字符串
        {
            if(str[indexold]  == ' ') //将空格替换为“20%”
            {
                str[indexnew--] = '0';
                str[indexnew--] = '2';
                str[indexnew--] = '%';
            }
            else
                str[indexnew--] = str[indexold];
        }
    }
};


