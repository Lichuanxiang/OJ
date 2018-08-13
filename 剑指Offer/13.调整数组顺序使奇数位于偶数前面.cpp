/*
	题目描述：
	输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
    使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，
    并保证奇数和奇数，偶数和偶数之间的相对位置不变。
*/
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int odd_num=0;
        for(int i=0; i<array.size(); i++){
            if(array[i]&1) odd_num++;
        }
        vector<int> v(array.size());
        int j=0, k=odd_num;
        for(int i=0; i<array.size();i++){
            if(array[i]&1) v[j++] = array[i];
            else v[k++] = array[i];
        }
        array = v;
    }
};