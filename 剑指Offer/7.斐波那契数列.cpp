/*
	题目描述：
	大家都知道斐波那契数列，现在要求输入一个整数n，
    请你输出斐波那契数列的第n项（从0开始，第0项为0）。
    n<=39
*/
//迭代法实现，还需掌握动态规划法，递归法
class Solution {
public:
    int Fibonacci(int n) {
        if(n<=0) return 0;
        if(n==1) return 1;
        
        int n1 = 1, n2 = 0;
        int fibn = 0;
        for(int i=2; i<=n; i++){
            fibn = n1+n2;
            n2 = n1;
            n1 = fibn;
        }
        return fibn;
    }
};