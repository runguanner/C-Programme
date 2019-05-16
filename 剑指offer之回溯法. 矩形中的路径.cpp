// 回溯法、DFS、递归



class Solution {
public:
    bool hasPathCore(char *matrix, int rows, int cols, int row, int col, char *str, int& pathLength, bool* visited) {
        if(str[pathLength] == '\0') return true;
        bool hasPath = false;
        if(row >= 0 && row < rows && col >= 0 && col < cols && matrix[row * cols + col] == str[pathLength] && !visited[row*cols + col]) {
            ++pathLength;
            visited[row * cols + col] = true;
            //如果矩阵格子(row,col)与路径字符串中下标为pathLength的字符一样时，从它的4个相邻格子中寻找与路径字符串下标为pathLength+1的字符相等的格子
            hasPath = hasPathCore(matrix, rows, cols, row, col - 1, str, pathLength, visited) || 
                hasPathCore(matrix, rows, cols, row - 1, col, str, pathLength, visited) || 				
                hasPathCore(matrix, rows, cols, row, col + 1, str, pathLength, visited) || 				
                hasPathCore(matrix, rows, cols, row + 1, col, str, pathLength, visited);
            if(!hasPath) {
                --pathLength;//如果没找到，则说明当前第pathLength个字符定位不正确，返回上一个位置重新定位
                visited[row * cols + col] = false;
            }
        }
        return hasPath;
    }
    
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if(matrix == NULL || rows < 1 || cols < 1 || str == NULL) return false;
        bool* visited = new bool[rows * cols];//定义一个辅助矩阵，用来标记路径是否已经进入了每个格子
        memset(visited, 0, rows * cols);
        int pathLength = 0;
        for(int row = 0; row < rows; row++) {//该循环是为了实现从任何一个位置出发，寻找路径
            for(int col = 0; col < cols; col++) {
                if(hasPathCore(matrix, rows, cols, row, col, str, pathLength, visited)) return true;
            }
        }
        delete[] visited;
        return false;
    }
};




class Solution
{
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty() || board[0].empty()) return false;
        int m = board.size(), n = board[0].size();
        vector<vector<int>> visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(search(board, word, 0, i, j, visited)) return true;
            }
        }
        return false;
    }

    bool search(vector<vector<char>>& board, string word, int idx, int i, int j, vector<vector<bool>>& visited) {
        if(idx == word.size()) return true;
        int m = board.size(), n = board[0].size();
        if(i < 0 || j < 0 || i >= m || j >= n || visited[i][j] || board[i][j] != word[idx]) return false;
        visited[i][j] = true;
        bool res = search(board, word, idx + 1, i - 1, j, visited) ||
                search(board, word, idx + 1, i + 1, j, visited) ||
                search(board, word, idx + 1, i, j - 1, visited) ||
                search(board, word, idx + 1, i, j + 1, visited);
        visited[i][j] = false;
        return res;
    }
};
