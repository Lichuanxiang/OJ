/*
	题目描述：
	在一个二维数组中（每个一维数组的长度相同），每一行都按照
	从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
	请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中
	是否含有该整数。
*/
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int i = array.size();
        int j = array[0].size();
        int col = j-1, row = 0;
        while(row<i && col>=0){
            if(array[row][col]==target) return true;
            else if(array[row][col]>target) col--;
            else row++;
        }
        return false;
    }
};