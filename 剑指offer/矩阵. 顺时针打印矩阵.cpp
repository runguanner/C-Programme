//Spiral Matrix：将矩阵螺旋输出为数组

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> result;
        if(matrix.empty()) return result;
        
        int begin = 0, rowend = matrix.size() - 1, colend = matrix[0].size() - 1;
        while(begin <= rowend && begin <= colend) {
            for(int j = begin; j <= colend; j++) {
                result.push_back(matrix[begin][j]);
            }
            for(int i = begin + 1; i <= rowend; i++) {
                result.push_back(matrix[i][colend]);
            }
            if(begin < rowend) {//防止最后只有一行
                for(int j = colend - 1; j >= begin; j--) {
                    result.push_back(matrix[rowend][j]);
                }
            }
            if(begin < colend) {
                for(int i = rowend - 1; i >= begin + 1; i--) {
                    result.push_back(matrix[i][begin]);
                }
            }
            begin++;
            rowend--;
            colend--;
        }
        return result;
    }
};


//Spiral Matrix II：将数组螺旋输出为矩阵
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> a(n, vector<int>(n));
        if(n<1) return a;
       
        int begin = 0; //起始点坐标
        int rowend = n-1; //对角点坐标
        int colend = n-1;
        int val = 1;
       
        while(begin <= rowend && begin <= colend)
        {
            for(int j = begin; j <= colend; j++) //赋值上行 i = begin,j = begin ~ colend
            {
                a[begin][j] = val++; //++在后为先用后加，故val初值为1
            }
            for(int i = begin+1; i <= rowend; i++) //赋值右边列 i = begin+1 ~ rowend, j = colend
            {
                a[i][colend] = val++;
            }
          
            if(begin < rowend) //防止最后只有一行
            {
                for(int j = colend-1; j >= begin; j--) //赋值下行 若begin<rowend, i = rowend, j = colend-1 ~ begin
                {
                    a[rowend][j] = val++;
                }
            }
          
            if(begin < colend) //防止最后只有一列
            {
                for(int i = rowend-1; i >= begin+1; i--) //赋值左边列 若begin<colend, i = rowend-1 ~ begin+1, j = begin
                {
                    a[i][begin] = val++;
                }              
            }
          
            begin++; //缩至内圈
            rowend--;
            colend--;
        }
        return a;
    }
};





