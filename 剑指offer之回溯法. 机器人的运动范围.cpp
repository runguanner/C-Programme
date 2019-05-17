// 回溯法、递归



// 方法一：暴力法枚举，练成路径
// 方法二：回溯法，试探的走，如果不满足条件或越界则回溯
class Solution
{
public:
    int movingCount(int threshold, int rows, int cols) {
        // vector<bool> visited(rows*cols,false); //创建访问数组
        // 也可用（vector<vector<bool> > visited(m, vector<bool>(n, false)); //创建访问矩阵
        bool *visited = new bool[rows * cols];
        for(int i = 0; i < rows * cols; i++) visited[i] = false;
        int count = helper(0, 0, rows, cols, visited, threshold);
        delete[] visited;//释放内存
        return count;
    }

private:
    int helper(int i, int j, int rows, int cols, bool* visited, int threshold) {
        bool temp1 = i < 0 || i >= rows || j < 0 || j >= cols;
        bool temp2 = (numSum(i) + numSum(j)) > threshold;
        if(visited[cols * i + j] || temp1 || temp2) return 0;//如果已经访问过或越界或者不满足约束条件，则不走这个格子，回溯
        else visited[cols * i + j] = true;

        return helper(i - 1, j, rows, cols, visited, threshold) +
                helper(i + 1, j, rows, cols, visited, threshold) +
                helper(i, j - 1, rows, cols, visited, threshold) +
                helper(i, j + 1, rows, cols, visited, threshold) + 1;//递归统计所能走的格子数
    }

    int numSum(int num) {
        int sum = 0;
        while(num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
};
