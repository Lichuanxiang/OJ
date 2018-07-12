//Solution 1：底层依然是乘法
class Solution {
public:
    int Sum_Solution(int n) {
        bool a[n][n+1];
        return sizeof(a)>>1;
    }
};

//Solution 2：递归
class Solution {
public:
    int Sum_Solution(int n) {
        int ans = n;
        ans && (ans += Sum_Solution(n-1));
        return ans;
    }
};