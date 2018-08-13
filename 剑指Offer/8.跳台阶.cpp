/*
	题目描述：
	一只青蛙一次可以跳上1级台阶，也可以跳上2级。
    求该青蛙跳上一个n级的台阶总共有多少种跳法
    （先后次序不同算不同的结果）。
*/
//斐波那契数列的应用，重点看书
class Solution {
public:
    int jumpFloor(int number) {
        if(number<1) return 0;
        else if(number==1) return 1;
        else if(number==2) return 2;
        int f1=2, f2=1, fn=0;
        for(int i=3; i<=number; i++){
            fn = f1+f2;
            f2 = f1;
            f1 = fn;
        }
        return fn;
    }
};