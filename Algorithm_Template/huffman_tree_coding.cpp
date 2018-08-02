/**
	哈夫曼树：带权路径最小的树
	**树的带权路径长度要会计算**
	构建思想：反复选择两个最小的元素，合并，直到只剩下一个元素
	使用优先队列(小顶堆)实现
**/

#include <cstdio>
#include <queue>

using namespace std;

priority_queue<long long, vector<long long>, greater<long long> > q; //greater为小顶堆

int main(){
	int n;
	long long temp, x, y, ans=0;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%lld", &temp);
		q.push(temp);
	}
	//Huffman树思想
	while(q.size()>1){ //优先队列中至少有两个元素
		x = q.top();
		q.pop();
		y = q.top();
		q.pop();
		q.push(x+y);
		ans += x+y;
	}
	return 0;
}