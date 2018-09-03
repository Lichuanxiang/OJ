/*
	题目描述：
	输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8
	这8个数字，则最小的4个数字是1,2,3,4,。
*/
//基于排序
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> v;
        if(k>input.size()) return v;
        sort(input.begin(), input.end());
        for(int i=0; i<k; i++){
            v.push_back(input[i]);
        }
        return v;
    }
};
//基于Partition
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> result;
        if(k>input.size() || input.empty() || k<=0)
            return vector<int>();
        int begin = 0;
        int end = input.size() - 1;
        int index = Partition(input, begin, end);
        while(index!=k-1)
        {
            if(index>k-1)
            {
                end = index - 1;
                index = Partition(input, begin, end);
            }
            
            if(index<k-1)
            {
                begin = index + 1;
                index = Partition(input, begin, end);
            }
        }
        for(int i=0; i<=index; i++)
            result.push_back(input[i]);
        return result;
    }
    
    int Partition(vector<int> &array, int low, int high)
    {
        int pivot = array[low];
        while(low<high)
        {
            while(low<high && pivot<=array[high])
                high--;
            array[low] = array[high];
            while(low<high && pivot>array[low])
                low++;
            array[high] = array[low];
        }
        array[low] = pivot;
        return low;
    }
};
//基于容器multiset
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        int len=input.size();
        if(len<=0||k>len) return vector<int>();
        //仿函数中的greater<T>模板，从大到小排序
        multiset<int, greater<int> > leastNums;
        vector<int>::iterator vec_it=input.begin();
        for(;vec_it!=input.end();vec_it++){
            //将前k个元素插入集合
            if(leastNums.size()<k)
                leastNums.insert(*vec_it);
            else{
                //第一个元素是最大值
                multiset<int, greater<int> >::iterator greatest_it=leastNums.begin();
                //如果后续元素<第一个元素，删除第一个，加入当前元素
                if(*vec_it<*(leastNums.begin())){
                    leastNums.erase(greatest_it);
                    leastNums.insert(*vec_it);
                }
            }
        }
        return vector<int>(leastNums.begin(),leastNums.end());
    }
};