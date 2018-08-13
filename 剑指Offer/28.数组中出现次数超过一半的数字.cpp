/*
    题目描述
    数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
    例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
    由于数字2在数组中出现了5次，超过数组长度的一半，
    因此输出2。如果不存在则输出0。
*/

// Solution 1: 出现次数超过一半的数比其他各数出现次数之和还要多
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int n = numbers.size();
        if(n==0) return 0;
        int count = 1, num = numbers[0];
        for(int i=1; i<n; i++){
            if(numbers[i]==num) count++;
            else count--;
            if(count==0){
                num = numbers[i];
                count = 1;
            }
        }
        count = 0;
        for(int i=0; i<n; i++)
            if(numbers[i]==num) count++;
        if(count*2>n) return num;
        return 0;
    }
};

//Solution 2: 基于快排Partition法，找到第n/2大的数，肯定是符合条件的
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int n = numbers.size();
        if(n<=0) return 0;
        int middle = n>>1;
        int start=0, end=n-1;
        int index = Partition(numbers, start, end);
        while(index!=middle){
            if(index>middle){
                end = index - 1;
                index = Partition(numbers, start, end);
            }
            else{
                start = index + 1;
                index = Partition(numbers, start, end);
            }
        }
        int count = 0;
        for(int i=0; i<n; i++){
            if(numbers[i]==numbers[middle])
                count++;
        }
        if(count*2>n) return numbers[middle];
        return 0;
    }
    int Partition(vector<int> numbers, int start, int end){
        int pivot = numbers[start];
        while(start<end){
            while(pivot<numbers[end]&&start<end)
                end--;
            while(pivot>=numbers[start]&&start<end)
                start++;
            swap(numbers[start], numbers[end]);
        }
        return start;
    }
};
