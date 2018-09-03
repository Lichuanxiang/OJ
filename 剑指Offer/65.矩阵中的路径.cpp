/*
	题目描述：
	请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一个格子开始，
	每一步可以在矩阵中向左，向右，向上，向下移动一个格子。如果一条路径经过了矩阵中的某一个格子，则之后不能再次进入这个格子。
	例如 a b c e s f c s a d e e 这样的3 X 4 矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，
	因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
*/
class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if(matrix==NULL || rows<1 || cols<1 || str==NULL)
            return false;
        bool *visited=new bool[rows*cols];
        memset(visited,0,rows*cols);
        for (int i = 0;i<rows;++i) {
            for (int j = 0;j<cols;++j) {
                if(dfs(matrix, rows, cols, i, j, visited, str))
                    return true;
            }
        }
        delete[] visited;
        return false;
    }
    bool dfs(char* matrix, int rows, int cols, int i, int j, bool* visited, char* str) {
        if (*str == '\0')
            return true;
        if(i<0 || i>=rows || j<0 || j>=cols)
            return false;
        if (visited[i*cols+j]==true || (visited[i*cols+j]==false && matrix[i*cols+j]!=*str))
            return false;
        else {
            visited[i*cols+j] = true;
            bool hasPath=dfs(matrix, rows, cols, i, j-1, visited, str+1)//左
                ||dfs(matrix, rows, cols, i, j+1, visited, str+1)//右
                ||dfs(matrix, rows, cols, i-1, j, visited, str+1)//上
                ||dfs(matrix, rows, cols, i+1, j, visited, str+1);//下
            //这样从1处开始进入的DFS即使没找到路径，但是visited最后全部置为false(未访问)
            if(!hasPath)
                visited[i*cols+j]=false;
            return hasPath;
        }
    }
};