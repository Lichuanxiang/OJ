/*
	题目描述：
	定义栈的数据结构，请在该类型中实现一个能够得到
    栈中所含最小元素的min函数（时间复杂度应为O（1））。
*/
class Solution {
public:
    void push(int value) {
        if(!s_data.empty()&&!s_help.empty()){
            s_data.push(value);
            if(value<s_help.top()) s_help.push(value);
            else s_help.push(s_help.top());
        }
        else{
            s_data.push(value);
            s_help.push(value);
        }
    }
    void pop() {
        if(!s_data.empty()&&!s_help.empty()){
            s_data.pop();
            s_help.pop();
        }
    }
    int top() {
        if(!s_data.empty())
            return s_data.top();
        else return -1;
    }
    int min() {
        return s_help.top();
    }
private:
    stack<int> s_data;
    stack<int> s_help;
};