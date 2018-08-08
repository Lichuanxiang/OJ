//由Knuth,Morris,Pratt共同发现
//时间复杂度O(n+m),穷举为O(nm)
/*
	考察目标字符串ptr： 
	ababaca 
	这里要计算一个长度为m的转移函数next。

	next数组的含义就是一个固定字符串的最长前缀和最长后缀相同的长度。

	比如：abcjkdabc，那么这个数组的最长前缀和最长后缀相同必然是abc。 
	cbcbc，最长前缀和最长后缀相同是cbc。 
	abcbc，最长前缀和最长后缀相同是不存在的。

	**注意最长前缀：是说以第一个字符开始，但是不包含最后一个字符。 
	比如aaaa相同的最长前缀和最长后缀是aaa。** 
	对于目标字符串ptr，ababaca，长度是7，所以next[0]，...，next[6]分别计算的是:
	a，ab，aba，abab，ababa，ababac，ababaca的相同的最长前缀和最长后缀的长度。
	由于a，ab，aba，abab，ababa，ababac，ababaca的相同的最长前缀和最长后缀是
	“”，“”，“a”，“ab”，“aba”，“”，“a”,所以next数组的值是[-1,-1,0,1,2,-1,0]，
	这里-1表示不存在，0表示存在长度为1，2表示存在长度为3。这是为了和代码相对应。
*/
#include <cstdio>
#include <cstring>

const int maxn = 1000;

void getNext(char s[], int* next, int len){
	int j = -1;
	next[0] = -1;
	for(int i=1; i<len; i++){
		while(j!=-1 && s[i]!=s[j+1])
			j = next[j]; //回退
		if(s[i]==s[j+1])
			j++;
		next[i] = j;
	}
	for(int i=0; i<len; i++)
		printf("%d ", next[i]);
	printf("\n");
}

//返回模式串pattern匹配的次数
int KMP(char* text, char* pattern){
	int n = strlen(text), m = strlen(pattern);
	int next[m];
	getNext(pattern, next, m);
	int ans=0, j=-1;
	for(int i=0; i<n; i++){
		while(j!=-1 && text[i]!=pattern[j+1])
			j = next[j];
		if(text[i]==pattern[j+1])
			j++;
		if(j==m-1){
			ans++;
			j = next[j];
		}
	}
	return ans;
}

int main(){
	char *text = "ababaababaab", *pattern = "ababaab";
	printf("%d\n", KMP(text, pattern));
	return 0;
}