/*
	题目描述：
	把只包含质因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含质因子7。 
	习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
*/
class Solution {
public:
    //空间换时间
    int GetUglyNumber_Solution(int index) {
        if(index<=0) return index;
        vector<int> result(index);
        result[0] = 1;
        int t2 = 0, t3 = 0, t5 = 0;
        for (int i = 1; i<index; ++i)
        {
            result[i] = min(result[t2]*2, min(result[t3]*3, result[t5]*5));
            if (result[i] == result[t2]*2)
                t2++;
            if (result[i] == result[t3]*3)
                t3++;
            if (result[i] == result[t5]*5)
                t5++;
        }
        return result[index - 1];
    }
    /*穷举
    bool isUgly(int number){
        while(number%2==0)
            number /= 2;
        while(number%3==0)
            number /= 3;
        while(number%5==0)
            number /= 5;
        return (number==1) ? true : false;
    }
    int GetUglyNumber_Solution(int index) {
        if(index<0) return 0;
        int number=0, uglyfound=0;
        while(uglyfound<index){
            number++;
            if(isUgly(number))
                uglyfound++;
        }
        return number;
    }*/
};