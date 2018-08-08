//由Knuth,Morris,Pratt共同发现
//时间复杂度O(n+m),穷举为O(nm)
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