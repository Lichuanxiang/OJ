/*
	题目描述：
	将一个字符串转换成一个整数(实现Integer.valueOf(string)的功能，但是string不符合数字要求时返回0)，
	要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0。
	输入描述:
	输入一个字符串,包括数字字母符号,可以为空
	输出描述:
	如果是合法的数值表达则返回该数字，否则返回0
	示例1
	输入
	+2147483647
	    1a33
	输出
	2147483647
	    0
*/
class Solution {
public:
    enum Status {kValid=0, kInvalid};
    int g_nStatus = kValid;
    
    int StrToInt(string str) {
        g_nStatus = kInvalid;
        long long num = 0;
        if(!str.empty()){
            int i=0;
            int flag = 1; //符号
            if(str[0]=='+') i++;
            if(str[0]=='-'){
                flag = -1;
                i++;
            }
            if(i<str.size()){
                num = StrToIntCore(str, i, flag);
            }
        }
        return (int)num;
    }
    long long StrToIntCore(string str, int i, int flag){
        long long num = 0;
        for(; i<str.size(); i++){
            if(str[i]>='0'&&str[i]<='9'){
                num = num*10 + flag*(str[i]-'0');
                if((flag==1&&num>0x7FFFFFFF) || (flag==-1&&num<(int)0x80000000)){
                    num = 0;
                    break;
                }
            }
            else{
                num = 0;
                break;
            }
        }
        g_nStatus = kValid;
        return num;
    }
};