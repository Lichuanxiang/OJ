/*
	题目描述：
	在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组,
	求出这个数组中的逆序对的总数P，并将P对1000000007取模的结果输出，即输出P%1000000007。
	输入描述:
	题目保证输入的数组中没有的相同的数字

	数据范围：

		对于%50的数据,size<=10^4

		对于%75的数据,size<=10^5

		对于%100的数据,size<=2*10^5

	示例1
	输入
	复制
	1,2,3,4,5,6,7,0
	输出
	复制
	7
*/
class Solution {
public:
    long countRes ;
    int InversePairs(vector<int> data) {
        countRes = 0;
        if(data.size() == 0)
            return 0;
        MergeSort(data,0,data.size()-1);
        return countRes%1000000007 ;
    }
    
    void MergeSort(vector<int>& data,int first,int end){
        if(first < end){
            int mid = (first + end)/2;
            MergeSort(data,first,mid);
            MergeSort(data,mid+1,end);
            MergeArray(data,first,mid,end);
        }
    }
    void MergeArray(vector<int>& data,int first,int mid,int end){
        int i = first, j = mid + 1, m = mid, n = end;
        vector<int> tmp;
        while(i<=m && j<=n){
            if(data[i] > data[j]){
                tmp.push_back(data[i++]);
                countRes += n - j + 1;
            }
            else{
                tmp.push_back(data[j++]);
            }
        }
        while(i<=m)
            tmp.push_back(data[i++]);
        while (j<=n)
            tmp.push_back(data[j++]);
        //更新data数组
        int k = 0;
        for (int i = first; i <= end &&k<tmp.size(); i++)
            data[i] = tmp[k++];
    }
};