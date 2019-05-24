//【1】Ugly Number I：判断一个数是否为丑数

class Solution
{
public:
    bool isUgly(int num)
    {
        if(num <= 0) return false;
        while(num % 2 == 0) num/=2; //提取因子（如果除得进就一直除）
        while(num % 3 == 0) num/=3;
        while(num % 5 == 0) num/=5;
       
        return (num == 1);
    }
};


//【2】Ugly Number II：第n个丑数

#include <algorithm>
class Solution
{
public:
    int nthUglyNumber(int n)
    {
        if(n <= 0) return 0; //表示不存在
       
        vector<int> k(n); //用于存各丑数
        k[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0; //对需要乘因子2,3,5的数的指针 
        for(int i = 1; i<n; i++) //i = 1~n-1
        {
            k[i] = min(k[p2]*2, min(k[p3]*3, k[p5]*5));
            if(k[i] == k[p2]*2) p2++; //只要相等就要移动，如6，需同时移动2和3的指针
            if(k[i] == k[p3]*3) p3++;
            if(k[i] == k[p5]*5) p5++;
        }
        return k[n-1];
    }
};


//【3】Super Ugly Number：
//类似ugly number II
#include <climits>
class Solution
{
public:
    int nthSuperUglyNumber(int n, vector<int>& primes)
    {
        if(n <= 0) return 0; //表示不存在丑数
        int k = primes.size();
        vector<int> index(k, 0); //用于指向要乘某因子的丑数,初始化为0
        vector<int> ugly(n);
        ugly[0] = 1;
        for(int i = 1; i<n; i++) //i=1~n-1
        {
            int temp = INT_MAX; //初始化为最大数,初始化为ugly[index[0]] * primes[0]较好
            for(int j = 0; j<k; j++) temp = min(temp, ugly[index[j]] * primes[j]);
            for(int j = 0; j<k; j++) //如果选取的是之前某个丑数乘某因子作为下个丑数，则该因子指针移动到下一个位置（否则下次乘出来还是最小的）
            {
                if(temp == ugly[index[j]] * primes[j]) index[j]++;
            }
            ugly[i] = temp;
        }
        return ugly[n-1];
    }
};



