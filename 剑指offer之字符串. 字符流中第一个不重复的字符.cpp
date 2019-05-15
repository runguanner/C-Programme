// 字符串、哈希表




class Solution
{
private:
    string str;
    int count[256] = {0};
public:
  //Insert one char from stringstream
    void Insert(char ch)
    {
        str += ch;
        count[ch]++;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        int len = str.size();
        for(int i = 0; i < len; i++) {
            if(count[str[i]] == 1) return str[i];
        }
        return '#';
    }

};
