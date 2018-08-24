//动态规划总结
//若动态规划算法一时无法理解，则打印出dp数组观察状态变化
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxNum = 100;
const int maxn = 10010;

class DP{
public:
	int fibnacci(int n, int* dp);
	int numTower();
	int largestSubsequenceSum();
	int LIS();
	int LCS();
	int LPS();
	int Knapsack_binary(); //0-1背包问题
	int Knapsack_complete(); //完全背包问题
	int Knapsack_multiple(); //多重背包问题
	int minEditDistance(); //最小编辑距离
};

//斐波那契数列，避免重复计算结果
int DP::fibnacci(int n, int* dp){
	if(n==0 || n==1) return 1;
	if(dp[n]!=-1) return dp[n];
	else{
		dp[n] = fibnacci(n-1, dp)+fibnacci(n-2, dp);
		return dp[n];
	}
}

//数塔问题(求所有从根到叶路径中的最大和)
//边界：dp[n][j] = f[n][j]
//状态转移方程：dp[i][j] = max{dp[i+1][j], dp[i+1][j+1]}+f[i][j]
int DP::numTower(){
	int f[maxNum][maxNum], dp[maxNum][maxNum];
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=i; j++)
			scanf("%d", &f[i][j]);
	for(int j=1; j<=n; j++)
		dp[n][j] = f[n][j];
	for(int i=n-1; i>=1; i--) //从n-1层开始向上计算dp
		for(int j=1; j<=i; j++)
			dp[i][j] = max(dp[i+1][j], dp[i+1][j+1])+f[i][j];
	return dp[1][1];
}

//最大连续子序列和
//dp[i]表示以A[i]为末尾的连续序列的最大和
//边界：dp[0] = A[0]
//状态转移方程：dp[i] = max{A[i], dp[i-1]+A[i]}
int DP::largestSubsequenceSum(){
	int n, dp[maxn], A[maxn];
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", A+i);
	dp[0] = A[0]; //边界
	for(int i=1; i<n; i++)
		dp[i] = max(A[i], dp[i-1]+A[i]);
	int k=0;
	for(int i=1; i<n; i++)
		if(dp[k]<dp[i])
			k = i;
	return dp[k];
	//若要寻找该连续子序列，则以k为末尾开始向前加和，若为dp[k]则返回该端点
}

//最长不下降子序列(Longest Incresing Subsequence, LIS)
//dp[i]表示以A[i]结尾的LIS长度
//状态转移方程：dp[i] = max{1, dp[j]+1}, (j=1,...,i-1 && A[j]<A[i])
//方程中隐含了边界：dp[i] = 1 (1<=i<=n) (先假设每个元素自成一个子序列)
int DP::LIS(){
	int n, A[maxn], dp[maxn];
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		scanf("%d", A+i);
	int ans = -1; //记录最大的dp[i]
	for(int i=1; i<=n; i++){
		dp[i] = 1; //************//
		for(int j=1; j<i; j++)
			if(A[i]>=A[j] && dp[j]+1>dp[i])
				dp[i] = dp[j] + 1;
		ans = max(ans, dp[i]);
	}
	return ans;
}

//最长公共子序列(Longest Common Subsequence, LCS, O(nm))
//dp[i][j]表示字符串A的i号位与字符串B的j号位之前的LCS(下标从1开始)
//边界：dp[i][0] = dp[0][j] = 0 (0<=i<=n,0<=j<=m)
//状态转移方程:
//dp[i][j] = 1. dp[i-1][j-1]+1, if A[i]==B[j]
//			 2. max{dp[i-1][j], dp[i][j-1]}, if A[i]!=B[j]
int DP::LCS(){
	int dp[maxNum][maxNum];
	char A[maxNum], B[maxNum];
	gets(A+1); //从下标1开始读入
	gets(B+1);
	int n = strlen(A+1);
	int m = strlen(B+1);
	//边界
	for(int i=0; i<=n; i++)
		dp[i][0] = 0;
	for(int j=0; j<=m; j++)
		dp[0][j] = 0;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			if(A[i]==B[j])
				dp[i][j] = dp[i-1][j-1]+1;
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
	return dp[n][m];
}

//最长回文子串(Longest Palindromic Substring, LPS)
//dp[i][j]表示S[i]到S[j]所表示的子串是否是回文子串，是为1，否为0
//状态转移方程：
//d[i][j] = 1. dp[i+1][j-1], if S[i]==S[j]
//			2. 0, if S[i]!=S[j]
//边界：dp[i][i] = 1, dp[i][i+1] = (S[i]==S[i+1]) ? 1 : 0.
int DP::LPS(){
	char S[maxNum];
	int dp[maxNum][maxNum];
	gets(S);
	int n = strlen(S), ans = 1;
	memset(dp, 0, sizeof(dp));
	//边界
	for(int i=0; i<n; i++){
		dp[i][i] = 1;
		if(i<n-1)
			if(S[i]==S[i+1]){
				dp[i][i+1] = 1;
				ans = 2;
			}
	}
	//边界计算出长度为1和2的子串dp值，因此第一遍先计算长度为3的子串dp，
	//然后才能继续之后的长度
	//状态转移方程
	for(int L=3; L<=n; L++){
		for(int i=0; i+L-1<n; i++){
			int j = i+L-1;
			if(S[i]==S[j] && dp[i+1][j-1]==1){
				dp[i][j] = 1;
				ans = L;
			}
		}
	}
	return ans;
}

//0-1背包问题
//每种物品只有1件(选择或者不选)
//dp[i][v]表示前i件物品恰好装入容量为v的背包中所能获得的最大价值
//状态转移方程：dp[i][v] = max{dp[i][v], dp[i-1][v-w[i]]+c[i]}
//上面用状态转移方程一层一层的存储下了每次放物品的所有容量的最大价值，这就会显得没有必要，
//因为最后需要的只有最后一行的最大容量的价值。故使用滚动数组进行空间优化：
//状态转移方程：d[v] = max{d[v], d[v-w[i]]+c[i]}
/*	后面这个状态转移方程所有可能背包容量必须从最大值到最小值(必须逆序枚举v！)。
	因为如果从最小值开始，那么比它大的背包容量就可能取到多次当前物品！
	比如说在还是空的的容量是10的背包里放容量价值都是1的物品，dp[1] = 1, dp[2] = dp[1] +1 = 2。
	显然这里出错误了，之后一直到dp[10]一直会递增下去。错误的根本原因是，从dp[2]开始状态转移方程
	用到的dp[v-w[i]]并不是历史数据了，而是放入当前物品刷新之后的dp数组。因为v-w[i]肯定是小于v的，
	所以应该从最大值开始滚动,这样每次滚动用到的历史数据都会保证是没放入当前物品的旧数据。
*/
int Knapsack_binary(){
	int maxN = 100; //物品最大件数
	int maxv = 1000; //容量的上限
	int w[maxN], c[maxN], dp[maxv]; //w为重量，c为价值
	int n, V;
	scanf("%d%d", &n, &V);
	for(int i=0; i<n; i++)
		scanf("%d", w+i);
	for(int i=0; i<n; i++)
		scanf("%d", c+i);
	//边界
	for(int v=0; v<=V; v++)
		dp[v] = 0;
	//滚动数组(节省空间,一维数组存放时v的枚举必须是逆序！)
	for(int i=1; i<n; i++)
		for(int v=V; v>=w[i]; v--)
			dp[v] = max(dp[v], dp[v-w[i]]+c[i]);
	//寻找dp[0...V]中最大的即为最大背包容量
	int maxV = 0;
	for(int v=0; v<=V; v++)
		if(maxV<dp[v])
			maxV = dp[v];
	return maxV;
}

//完全背包问题
//每种物品可有无穷件
int Knapsack_complete(){
	int maxN = 100; //物品最大件数
	int maxv = 1000; //容量的上限
	int w[maxN], c[maxN], dp[maxv];
	int n, V;
	scanf("%d%d", &n, &V);
	for(int i=0; i<n; i++)
		scanf("%d", w+i);
	for(int i=0; i<n; i++)
		scanf("%d", c+i);
	//边界
	for(int v=0; v<=V; v++)
		dp[v] = 0;
	//滚动数组(正向枚举！代表可多次选择当前物品)
	for(int i=1; i<=n; i++)
		for(int v=w[i]; v<=V; v++)
			dp[v] = max(dp[v], dp[v-w[i]]+c[i]);
	//寻找dp[0...V]中最大的即为最大背包容量
	int maxV = 0;
	for(int v=0; v<=V; v++)
		if(maxV<dp[v])
			maxV = dp[v];
	return maxV;
}

//多重背包问题
//每种物品可有限定数量件
//解决多重背包问题，只需要把它转化为0-1背包问题即可。
//比如，有2件价值为5，重量为2的同一物品，我们就可以分为物品a和物品b，
//a和b的价值都为5，重量都为2，但我们把它们视作不同的物品。
int Knapsack_multiple(){
	const int V = 1000
	int weight[50 + 1];
	int value[50 + 1];
	int num[20 + 1];
	int f[V + 1];
	int n, m;
    cout << "请输入物品个数:";
    cin >> n;
    cout << "请分别输入" << n << "个物品的重量、价值和数量:" << endl; 
    for (int i = 1; i <= n; i++) {
        cin >> weight[i] >> value[i] >> num[i];
    }
    int k = n + 1;
    for (int i = 1; i <= n; i++) {
        while (num[i] != 1) {
            weight[k] = weight[i];
            value[k] = value[i];
            k++;
            num[i]--;
        }
    }
    cout << "请输入背包容量:";
    cin >> m;
    for (int i = 1; i <= k; i++) {
        for (int j = m; j >= 1; j--) {
            if (weight[i] <= j) f[j] = max(f[j], f[j - weight[i]] + value[i]);
        }
    }
    cout << "背包能放的最大价值为:" << f[m] << endl;
}

//最小编辑距离
//时间复杂度O(mn),空间复杂度O(mn)
//dp[i][j]表示源串S[0...i]和目标串T[0...j]的最短编辑距离
int minEditDistance(){
	int m, n; //两字符串的长度
	scanf("%d%d", &m, &n);
	char A[m], B[n];
	scanf("%s", A);
	scanf("%s", B);
	int i, j, cost;
	int dp[m+1][n+1];
	for(i=0; i<=m; i++) 
		dp[i][0] = i;
	for(j=0; j<=n; j++)
		dp[0][j] = j;
	for(i=1; i<=m; i++){
		for(j=1; j<=n; j++){
			cost = A[i-1]==B[j-1] ? 0 : 1;
			int deletion = dp[i-1][j]+1;
            int insertion = dp[i][j-1]+1;
            int substitution = dp[i-1][j-1]+cost;
			dp[i][j] = min(deletion, min(insertion, substitution));
		}
	}

	return dp[m][n];
}
//使用滚动数组优化最短编辑距离算法
//时间复杂度O(mn),空间复杂度O(m+n)
//dp为滚动数组
int minEditDistanceByScrollArray(){
	int m, n; //两字符串的长度
	scanf("%d%d", &m, &n);
	char A[m], B[n];
	scanf("%s", A);
	scanf("%s", B);
	int i, j, cost, temp1, temp2;
	int dp[n+1];
	for(j=0; j<=n; j++)
		dp[j] = j;
	for(i=1; i<=m; i++){
		temp1 = dp[0]++;
		for(j=1; j<=n; j++){
			temp2 = dp[j];
			cost = A[i-1]==B[j-1] ? 0 : 1;
			int deletion = dp[j]+1;
            int insertion = dp[j-1]+1;
            int substitution = temp1+cost;
			dp[j] = min(deletion, min(insertion, substitution));
			temp1 = temp2;
		}
	}

	return dp[n];
}


int main(){

	DP dptest;
	/*
		//fibonacci数列
		int dp[maxn];
		fill(dp, dp+maxn, -1);
	*/
	//int result = dptest.fibnacci(6, dp);

	/* numTower测试用例
		5
		5
		8 3
		12 7 16
		4 10 11 6
		9 5 3 9 4
	*/
	//int result = dptest.numTower();

	/*	largestSubsequenceSum测试用例
		6
		-2 11 -4 13 -5 -2
	*/
	//int result = dptest.largestSubsequenceSum();

	/*	LIS测试用例
		8
		1 2 3 -9 3 9 0 11
	*/
	//int result = dptest.LIS();

	/*	LCS测试用例
		sadstory
		adminsorry
	*/
	//int result = dptest.LCS();

	/*	LPS测试用例
		abba
		ABCDSDUDCBA
	*/
	//int result = dptest.LPS();

	/*	背包问题测试用例
		5 8
		3 5 1 2 2
		4 5 2 1 3
	*/
	//int result = Knapsack_binary();
	//int result = Knapsack_complete();

	//int result = minEditDistance();
	int result = minEditDistanceByScrollArray();

	printf("result = %d\n", result);
}