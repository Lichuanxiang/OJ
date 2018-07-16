#include <cstdio>
#include <algorithm>

using namespace std;

void selectSort(int A[], int n){
	for(int i=0; i<n; i++){
		int k = i;
		for(int j=i; j<n; j++){
			if(A[j]<A[k]){
				k = j;
			}
		}
		int temp = A[k];
		A[k] = A[i];
		A[i] = temp;
	}
}

void insertSort(int A[], int n){
	for(int i=1; i<n; i++){
		for(int j = i; j>0 && A[j-1]>A[j]; j--){
			int temp = A[j];
			A[j] = A[j-1];
			A[j-1] = temp;
		}
	}
}

void bubbleSort(int A[], int n){
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			if(A[j]<A[i]){
				int temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
		}
	}
}

int Partition(int A[], int left, int right){
	int pivot = A[left];
	while(left<right){
		if(left<right && A[right]>pivot)
			right--;
		A[left] = A[right];
		if(left<right && A[left]<pivot)
			left++;
		A[right] = A[left];
	}
	A[left] = pivot;
	return left;
}

void quicksort(int A[], int left, int right){
	if(left<right){
		int pos = Partition(A, left, right);
		quicksort(A, left, pos-1);
		quicksort(A, pos+1, right);
	}
}

void quickSort(int A[], int n){
	quicksort(A, 0, n-1);
}

//归并排序递归版本
void merge(int A[], int L1, int R1, int L2, int R2){
	int i=L1, j=L2;
	int temp[R1-L1+R2-L2+3], index=0;
	while(i<=R1 && j<=R2){
		if(A[i]<=A[j]) temp[index++] = A[i++];
		else temp[index++] = A[j++];
	}
	while(i<=R1) temp[index++] = A[i++];
	while(j<=R2) temp[index++] = A[j++];
	for(int i=0; i<index; i++){
		A[L1+i] = temp[i];
	}
}

void mergesort(int A[], int left, int right){
	if(left<right){
		int mid = (left+right)/2;
		mergesort(A, left, mid);
		mergesort(A, mid+1, right);
		merge(A, left, mid, mid+1, right);
	}
}

void mergeSort(int A[], int n){
	mergesort(A, 0, n-1);
}

//归并排序非递归版本
void mergeSortNonrecursive(int A[], int n){
	for(int step=2; step/2<n; step*=2){
		for(int i=0; i<n; i+=step){
			int mid = i+step/2-1;
			if(mid-1<n)
				merge(A, i, mid, mid+1, min(i+step-1, n));
		}
	}
}

void heapSort(int A[], int n){

}

void cStandardSort(int A[], int n){
	/*需添加：
	#include <algorithm>
	using namespace std;
	*/
	sort(A, A+n);
}


int main(){
	int A[5] = {3,2,1,6,5};
	mergeSortNonrecursive(A, 5);
	for(int i=0; i<5; i++){
		printf("%d ", A[i]);
	}
	return 0;
}