/*
	题目描述：
	给定一个double类型的浮点数base和int类型的整数exponent。
    求base的exponent次方。
*/
class Solution {
public:
    double Power(double base, int exponent) {
        double result=1.0;
        bool flag = true;
        if(exponent==0) return 1;
        if(exponent<0) flag = false;
        while(exponent>0 && flag){
            if(exponent&1) result = result*base;
            base *= base;
            exponent = exponent >> 1;
        }
        if(!flag){
            exponent = -1*exponent;
            while(exponent>0){
                if(exponent&1) result = result*base;
                base *= base;
                exponent = exponent >> 1;
            }
            result = 1.0/result;
        }
        return result;
    }
};