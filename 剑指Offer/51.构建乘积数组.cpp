/*
	题目描述：
	给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。
*/
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> B;
        if(A.empty()) return B;
        int temp1=1, temp2=1;
        B.push_back(temp1);
        for(int i=1; i<A.size(); i++){
            temp1 = A[i-1]*B[i-1];
            B.push_back(temp1);
        }
        for(int i=A.size()-2; i>=0; i--){
            temp2 *= A[i+1];
            B[i] *= temp2;
        }
        return B;
    }
};