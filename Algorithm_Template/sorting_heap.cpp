/*	堆排序：
	大顶堆：arr[i] >= arr[2i+1] && arr[i] >= arr[2i+2]  
	小顶堆：arr[i] <= arr[2i+1] && arr[i] <= arr[2i+2]  
*/

#include <cstdio>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int adjustHeap(int heap[], int i, int n){
	int temp = heap[i];
	//j为i节点的左孩子(heap下标从0开始则为2i+1，从1开始则为2i)
	for(int j=i*2+1; j<n; j=j*2+1){
		if(j+1<n && heap[j+1]>heap[j]){
			j = j+1;
		}
		if(heap[j]>heap[i]){
			swap(heap+i, heap+j);
			i = j;
		}
		else break;
	}
	heap[i] = temp;
}

void heapSort(int heap[], int n){
	//构建大顶堆
	for(int i=n/2; i>=0; i--)
		adjustHeap(heap, i, n);
	//交换堆顶元素与末尾元素+调整堆结构
	for(int j=n-1; j>0; j--){
		swap(heap+j,heap);
		adjustHeap(heap, 0, j);
	}
}

int main(){
	int A[5] = {3,2,1,6,5};
	heapSort(A, 5);
	for(int i=0; i<5; i++){
		printf("%d ", A[i]);
	}
	return 0;
}