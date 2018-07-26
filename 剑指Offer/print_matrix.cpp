#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int row = matrix.size(), col = matrix[0].size();

        if(row<=0||col<=0) return matrix[0];
        vector<int> v;
        for(int i=0; i<v.size(); i++)
            cout<<v[i]<<" ";
        cout<<endl;
        int circle = 0;
        if(row&1) circle = (row>>1)+1;
        else circle = row>>1;
        cout<<circle<<" "<<row<<" "<<col<<endl;

        for(int k=0; k<circle; k++){
            int i=k, j;
            for(j=k; j<=col-k-1; j++) v.push_back(matrix[i][j]);
            j = col-k-1;
            for(i=k+1; i<=row-k-1; i++) v.push_back(matrix[i][j]);
            i = row-k-1;
            for(j=col-k-2; j>=k; j--) v.push_back(matrix[i][j]);
            j = k;
            for(i=row-k-2; i>k; i--) v.push_back(matrix[i][j]);
        }

        for(int i=0; i<v.size(); i++)
            cout<<v[i]<<" ";
        cout<<endl;
        return v;
    }
};


int main()
{
    vector<vector<int> > matrix(2);
    matrix[0].push_back(1);
    matrix[0].push_back(2);
    matrix[1].push_back(3);
    matrix[1].push_back(4);
    vector<int> v;
    Solution sol;
    v = sol.printMatrix(matrix);


    return 0;
}
