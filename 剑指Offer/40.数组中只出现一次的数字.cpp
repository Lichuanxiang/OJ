/*
	题目描述：
	一个整型数组里除了两个数字之外，其他的数字都出现了偶数次。请写程序找出这两个只出现一次的数字。
*/
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if(data.size() < 2) return ;
        int result = 0;
        int flag = 1;
        for(int i = 0 ; i < data.size(); i++)
            result ^= data[i];
        //从低位开始找出第一个为1的位
        while((result & flag) == 0) flag <<= 1;
        *num1 = result;
        *num2 = result;
        for(int i=0; i<data.size(); i++){
            if((flag & data[i])==0) *num2 ^= data[i];
            else *num1 ^= data[i];
        }
    }
};