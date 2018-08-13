/*
	题目描述：
	输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
    例如，如果输入如下4 X 4矩阵： 
    1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
    则依次打印出数字：
    1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
*/
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int row = matrix.size(), col = matrix[0].size();
        if(row<=0||col<=0) return matrix[0];
        vector<int> v;
        int circle=((row<col?row:col)-1)/2+1;
        
        for(int k=0; k<circle; k++){
            int i=k, j;
            for(j=k; j<=col-k-1; j++) v.push_back(matrix[i][j]);
            j = col-k-1;
            for(i=k+1; i<=row-k-1; i++) v.push_back(matrix[i][j]);
            i = row-k-1;
            for(j=col-k-2; j>=k&&(row-k-1!=k); j--) v.push_back(matrix[i][j]);
            j = k;
            for(i=row-k-2; i>k&&(col-k-1!=k); i--) v.push_back(matrix[i][j]);
        }
        return v;
    }
};