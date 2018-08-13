/*
	题目描述：
	请实现一个函数，将一个字符串中的每个空格替换成“%20”。
    例如，当字符串为We Are Happy.则经过替换之后的字符串为
    We%20Are%20Happy
*/
class Solution {
public:
    void replaceSpace(char* str,int length) {
        if(str==NULL||length<=0) return;
        int count = 0, oldlen = 0;
        for(int i=0; str[i]!='\0'; i++){
            oldlen++;
            if(str[i]==' ') count++;
        }
        int p2 = oldlen+2*count;
        int p1 = oldlen;
        if(p2>length) return;
        while(p1!=p2){
            if(str[p1]==' '){
                str[p2--] = '0';
                str[p2--] = '2';
                str[p2--] = '%';
            }
            else str[p2--] = str[p1];
            p1--;
        }
    }
};