#include <cstdio>
#include <algorithm>
#include <stack>

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

void insertSort(int A[], int n){
	for(int i=1; i<n; i++){
		//交换法
		for(int j = i; j>0 && A[j-1]>A[j]; j--){
			int temp = A[j];
			A[j] = A[j-1];
			A[j-1] = temp;
		}
		//移位法
		
	}
}

//折半插入排序
void binaryInsertSort(int A[], int n){
	for(int i=1;i<n;i++){
        int temp = A[i];
        int low=0;
        int high = i-1;
        //high作为标记节点，A[high]<A[i]
        while(low<=high){
        	//有序数组的中间坐标，此时用于二分查找，减少查找次数
            int middle = (low+high)/2;
            if(A[middle]<A[i])
                low = middle+1;
            else
                high=middle-1;
        }
        for(int j=i-1;j>=low;j--){
            A[j+1] = A[j];
        }
        A[low] = temp;           
    }
}

//希尔排序
//1.交换法实现希尔排序
void shellSortSwap(int A[], int n){
	for(int gap=n/2; gap>0; gap/=2){
		for(int i=gap; i<n; i++){
			int j = i;
			while(j-gap>=0 && A[j]<A[j-gap]){
				swap(A[j], A[j-gap]);
				j -= gap;
			}
		}
	}
}
//2.移动法实现希尔排序
void shellSortMove(int A[], int n){
	for(int gap=n/2; gap>0; gap/=2){
		for(int i=gap; i<n; i++){
			int j = i, temp = A[i];
			while(j-gap>=0 && temp<A[j-gap]){
				A[j] = A[j-gap];
				j -= gap;
			}
			A[j] = temp;
		}
	}
}

//快速排序
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

//递归版
void quicksort(int A[], int left, int right){
	if(left<right){
		int pos = Partition(A, left, right);
		quicksort(A, left, pos-1);
		quicksort(A, pos+1, right);
	}
}
//快排非递归版
void quicksortNonRecursive(int A[], int left,int right){
    if (left < 0 || right <= 0 || left>right)
        return;
    stack<int> temp;
    int i, j;
    //（注意保存顺序）先将初始状态的左右指针压栈
    temp.push(right);//先存右指针
    temp.push(left);//再存左指针
    while (!temp.empty()){
        i = temp.top();//先弹出左指针
        temp.pop();
        j = temp.top();//再弹出右指针
        temp.pop();
        if (i < j){
            int k = Partition(A, i, j);
            if (k > i){
                temp.push(k - 1);//保存中间变量
                temp.push(i);  //保存中间变量 
            }
            if (j > k){
                temp.push(j);
                temp.push(k + 1);
            }
        }
    }
}

void quickSort(int A[], int n){
	//quicksort(A, 0, n-1);
	quicksortNonRecursive(A, 0, n-1);
}

//归并排序
//1.递归版本
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

//2.非递归版本
void mergeSortNonrecursive(int A[], int n){
	for(int step=2; step/2<n; step*=2){
		for(int i=0; i<n; i+=step){
			int mid = i+step/2-1;
			if(mid-1<n)
				merge(A, i, mid, mid+1, min(i+step-1, n));
		}
	}
}

//堆排序(自上向下调整)
int adjustHeap(int heap[], int i, int n){
	int temp = heap[i];
	//j为i节点的左孩子(heap下标从0开始则为2i+1，从1开始则为2i)
	for(int j=i*2+1; j<n; j=j*2+1){
		if(j+1<n && heap[j+1]>heap[j]){
			j = j+1;
		}
		if(heap[j]>heap[i]){
			swap(heap[i], heap[j]);
			i = j;
		}
		else break;
	}
	heap[i] = temp;
}

void heapSort(int heap[], int n){
	//构建大顶堆(建堆操作)
	for(int i=n/2; i>=0; i--)
		adjustHeap(heap, i, n);
	//交换堆顶元素与末尾元素+调整堆结构
	for(int j=n-1; j>0; j--){
		swap(heap[j],heap[0]);
		adjustHeap(heap, 0, j);
	}
}

//调用C++库函数
void cStandardSort(int A[], int n){
	/*需添加：
	#include <algorithm>
	using namespace std;
	*/
	sort(A, A+n);
}


int main(){
	int A[5] = {3,2,1,6,5};
	quickSort(A, 5);
	for(int i=0; i<5; i++){
		printf("%d ", A[i]);
	}
	return 0;
}
