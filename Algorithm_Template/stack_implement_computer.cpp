//1.中缀表达式转后缀表达式
//2.计算后缀表达式

#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <map>

using namespace std;

struct node
{
	double num;
	char op;
	bool flag; //true为操作数，false为操作符
};

string str;
stack<node> s; //操作符栈
queue<node> q; //后缀表达式序列
map<char, int> op;

void change(){ //中缀转后缀
	node temp;
	for(int i=0; i<str.length();){
		if(str[i]>='0' && str[i]<='9'){
			temp.flag = true;
			temp.num = str[i++] - '0';
			while(i<str.length() && str[i]>='0' && str[i]<='9'){
				temp.num = temp.num*10 + (str[i] - '0');
				i++;
			}
			q.push(temp);
		}
		else{
			temp.flag = false;
			while(!s.empty() && op[str[i]]<=op[s.top().op]){
				q.push(s.top());
				s.pop();
			}
			temp.op = str[i];
			s.push(temp);
			i++;
		}
	}
	while(!s.empty()){
		q.push(s.top());
		s.pop();
	}
}
double calculate(){ //计算后缀表达式
	double num1, num2;
	node cur, temp;
	while(!q.empty()){
		cur = q.front();
		q.pop();
		if(cur.flag==true) s.push(cur);
		else{
			num2 = s.top().num;
			s.pop();
			num1 = s.top().num;
			s.pop();
			if(cur.op=='+') temp.num = num1+num2;
			else if(cur.op=='-') temp.num = num1-num2;
			else if(cur.op=='*') temp.num = num1*num2;
			else temp.num = num1/num2;
			s.push(temp);
		}
	}
	return s.top().num;
}

int main(){
	op['+'] = op['-'] = 1;
	op['*'] = op['/'] = 2;
	while(getline(cin, str), str!="0"){
		for(string::iterator it=str.end(); it!=str.begin(); it--)
			if(*it==' ') str.erase(it);
		while(!s.empty()) s.pop();
		change();
		printf("%.2f\n", calculate());
	}
}