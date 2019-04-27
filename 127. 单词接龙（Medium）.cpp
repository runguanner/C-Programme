// 广度优先搜索BFS


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return 0;
        unordered_map<string, int> pathCnt{{{beginWord, 1}}};  ////需要一个HashMap，来建立某条路径结尾单词和该路径长度之间的映射，并把起始单词映射为1
        queue<string> q{{beginWord}};  ////既然是BFS，需要一个队列queue，把起始单词排入队列中，开始队列的循环，取出队首词，然后对其每个位置上的字符用26个字母进行替换
        while (!q.empty()) {
            string word = q.front(); q.pop();
            for (int i = 0; i < word.size(); ++i) {
                string newWord = word;
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    newWord[i] = ch;
                    if (wordSet.count(newWord) && newWord == endWord) return pathCnt[word] + 1;  //如果此时和结尾单词相同了，就可以返回取出词在哈希表中的值加一
                    if (wordSet.count(newWord) && !pathCnt.count(newWord)) {  //如果替换词在字典中存在但在哈希表中不存在，则将替换词排入队列中，并在哈希表中的值映射为之前取出词加一。如果循环完成则返回0
                        q.push(newWord);
                        pathCnt[newWord] = pathCnt[word] + 1;
                    }   
                }
            }
        }
        return 0;
    }
};


// 其实并不需要上面解法中的HashMap，由于BFS的遍历机制就是一层一层的扩大的，那么我们只要记住层数就行，然后在while循环中使用一个小trick，加一个for循环，表示遍历完当前队列中的个数后，层数就自增1

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return 0;
        queue<string> q{{beginWord}};
        int res = 0;
        while (!q.empty()) {
            for (int k = q.size(); k > 0; --k) {
                string word = q.front(); q.pop();
                if (word == endWord) return res + 1;
                for (int i = 0; i < word.size(); ++i) {
                    string newWord = word;
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        newWord[i] = ch;
                        if (wordSet.count(newWord) && newWord != word) {
                            q.push(newWord);
                            wordSet.erase(newWord);
                        }   
                    }
                }
            }
            ++res;  //这样就省去了HashMap，而仅仅用一个变量res来记录层数即可
        }
        return 0;
    }
};


