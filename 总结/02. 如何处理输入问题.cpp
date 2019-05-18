// 如何处理输入问题

// 1. 头文件可以直接用 #include<bits/stdc++.h> 包含了目前c++所包含的所有头文件。
// 2. 注意：当数据以空格分隔时，可以直接用cin来读入！
// 3. 思路：使用 getline 和 stringstream 以 ',' 为分隔符来切分数据，然后使用标准库 string 的数值转换函数例如字符串转整形 stoi 进行解析。


// (一)、整数输入问题

/*
最简单的输入，输入单行
Sample Input 1 2
Sample Output 3
*/
#include <iostream>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    cout >> a + b >> endl;  //对于其他题目，换成要求的复杂处理和输出
    return 0;
}


/*
输入多行数时，直到读至输入文件末尾（EOF）为止
说明1：当读到输入结束时，cin >> a >> b 返回0，循环也结束。
说明2：在调试程序时，键盘输入的数据，用 ctrl+z 组合作为输入结束，此谓键盘输入设备的“文件末尾”。
Sample Input
1 5
10 20
400 516
Sample Output
6
30
916
*/
#include <iostream>
using namespace std;
int main() {
    int a, b;
    while(cin >> a >> b) {  //当题目输入行数不确定时使用此方法
        cout << a + b << endl;
    }
    return 0;
}


/*
多组由两个整数（a和b）构成的输入，a和b之间用空格隔开，每组输入单独占一行。
当输入为0 0时，输入结束。
Sample Input
1 5
10 20
0 0
Sample Output
6
30
*/
#include <iostream>
using namespace std;
int main() {
    int a, b;
    while(cin >> a >> b && (a || b)) {
        cout << a + b << endl;
    }
    return 0;
}


/*
第一行是数据的组数N
从第二行是N组由两个整数（a和b）构成的输入，a和b之间用空格隔开，每组输入单独占一行
Sample Input
2
1 5
10 20
Sample Output
6
30
*/
#include <iostream>
using namespace std;
int main() {
    int a, b, n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;  //cin以空格或者回车作为输入输出分隔符
        cout << a + b << endl;
    }
    return 0;
}


/*
利用文件重定向提高调试效率
*/
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);  //将输入重定向到文件input.txt（注意文件路径）
    int a, b;
    cin >> a >> b;
    cout << a + b << endl;
    return 0;
}  //在运行程序前，本该由键盘输入的数据，写到文件input.txt中，而在运行程序时，数据将不再需要人为去输入



// (二)、读取和解析标点字符（如逗号）分割数据

/*
处理输入问题：读取以逗号间隔的数字到数组中
例：
输入：1,12,123
数组a：a[0] = 1, a[1] = 12, a[2] = 123
*/
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main() {
    vector<int> a;
    string s;
    cin >> s;  //读取输入字符串到s
    stringstream input(s);
    string numstr;
    while(getline(input, numstr, ',')) {  //按逗号分隔为字符串（getline每次读一个）
        a.push_back(stoi(numstr));
    }
    return 0;
}


/* 例子
输入：
2
19:90:23
23:59:59
输出：
19:00:23
23:59:59
*/
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;
int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        string numstr;
        string output;
        string inputstr;
        cin >> inputstr;  //读取一行字符串，方便处理
        stringstream input(inputstr);  //将字符串s转化为流，用cin需要考虑回车问题，用流就比较方便（因为inputstr已经跳过回车字符）
        
        int count = 1;
        while(getline(input, numstr, ':')) {  //getline会将其分隔符换成字符串
            int num = stoi(numstr);  //假设num一定为正数
            if(count == 1) {
                if(num > 23)
                    numstr[0] = '0';
                output += numstr + ':';
            }
            else {
                if(num > 59)
                    numstr[0] = '0';
                output += numstr + ':';
            }
            
            count++;
        }
        output.pop_back();  //移除末尾字符':'
        cout << output << endl;
    }
}

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string raw_data("3,4,5,76"), tmp;
    vector<string> data;
    stringstream input(raw_data);

    while(getline(input, tmp, ',')) data.push_back(tmp);

    for(auto s : data) cout << stoi(s) << endl;

    return 0;
}
