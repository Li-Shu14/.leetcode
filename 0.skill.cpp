#include <iostream>
#include <vector>
using namespace std;

// 函数传递数组的方法：
// 指针传递1
void test_fun_array_transfer(int* a) {
    int temp = a[1]+1;
}
// 指针传递2
void test_fun_array_transfer2(int a[]) { //若长度已知，中括号里可以输入确定的数组
    int temp = a[1]+1;
}
// 引用传递1
void test_fun_array_transfer3(int* &a) {
    int temp = a[1]+1;
}
// 引用传递2
void test_fun_array_transfer4(int (&a)[]) { //若长度已知，中括号里可以输入确定的数组
    int temp = a[1]+1;
}

// 求数组长度
template <class T>
int getArrSize(T& arr){
	return sizeof(arr) / sizeof(arr[0]);
}
template <class T>
int getArrLength(T& arr){
    return end(arr) - begin(arr);
}

// 快速排序，分组版+直接版
void swap(int& p, int& q) {
    int temp = p;
    p = q;
    q = temp;
}
int partition1(int array[], int l, int r) {
    int i = l, j = r+1;
    int pivot = array[i]; //pivot
    while(true) {
        while(array[++i] < pivot);
        while(array[--j] > pivot);
        if (i>=j) break;
        swap(array[i],array[j]);
        array[l] = array[j];
        array[j] = pivot;  
        return j;
    }
}

int partition2(int arr[], int l, int r){
	int pivot = arr[l];
	int i=l+1, j=r;
	while(i<=j) {
		if(arr[i]<pivot) i++;
		else if(arr[j]>pivot) j--;
		else if(arr[i]>=pivot && arr[j]<=pivot) swap(arr[i++], arr[j--]);
	}
	swap(arr[r], arr[r]);
	return r;
}

int partition3(int arr[], int l, int r){
	int pivot = arr[l];
	int index = l+1;
	for(int i=index;i<=r;i++){
		if(arr[i]<pivot){
			swap(arr[i], arr[index++]);
		}
	}
	swap(arr[l],arr[index-1]);
	return index-1;
}

int partition(int array[], int l, int r){
    return partition1(array,l,r);
}

void QuickSort(int array[], int l, int r) {
    if (l < r) {
        int pivot = partition(array,l,r);   
        QuickSort(array,l,pivot-1);
        QuickSort(array,pivot+1,r);
    }
}
// 最一般的：从小到大，每次以最左边
void QuickSort_dir(int array[], int start, int last) {   
    if (start >= last) return; //只有一个元素时(甚至没有元素时，这种情况是存在的，比如一个已经从小到大排好的数组)到达递归终点
    int i = start, j = last, pivot = array[i];
    while (i < j) {
        while (array[j] >= pivot && i < j) j--;
        if (i < j) array[i++] = array[j];
        while (array[i] <  pivot && i < j) i++;
        if (i < j) array[j--] = array[i];
    }
    array[i] = pivot; //把基准数放到i位置
    QuickSort_dir(array, start, i - 1);
    QuickSort_dir(array, i + 1, last);
}

//从右往左排。
void QuickSort_dir2(int array[], int start, int last) {   // 逆序
    if (start >= last) return; //只有一个元素时到达递归终点
    int i = start, j = last, pivot = array[j];  //从右边找pivot
    while (i < j) {
        while (array[i] <= pivot && i < j) i++; 
        if (i < j) array[j--] = array[i];
        while (array[j] >  pivot && i < j) j--;
        if (i < j) array[i++] = array[j];
    }
    array[j] = pivot; //把基准数放到j位置
    QuickSort_dir2(array, start, j - 1);
    QuickSort_dir2(array, j + 1, last);
}
// 从大到小
void QuickSort_inv(int array[], int start, int last){ // 逆序
    if (start >= last) return; //只有一个元素时到达递归终点
    int i = start, j = last, pivot = array[j];  //从右边找pivot
    while (i < j) {
        while (array[i] >= pivot && i < j) i++; 
        if (i < j) array[j--] = array[i];
        while (array[j] <  pivot && i < j) j--;
        if (i < j) array[i++] = array[j];
    }
    array[j] = pivot; //把基准数放到j位置
    QuickSort_inv(array, start, j - 1);
    QuickSort_inv(array, j + 1, last);
}

// 插入排序
void insertion(vector<int>& arr){ //如果采用数组的话，需要将数组长度统计出来，或者直接通过参数传递进去。
	for(int i=1;i<arr.size();i++){
		int pivot=arr[i];
        int j = 0;
		for(j=i-1; j>=0 ; j--){
            if (pivot<arr[j]) arr[j+1] = arr[j];
            else break;
		}
		arr[j+1] = pivot;
	}
}

// 归并排序
// 这两种方法，前者将创建新空间用来装子数组的过程放到Merge函数里，后者把该过程放到MergeSort主函数内。我感觉前者所占用的空间更小，更好。
//https://blog.csdn.net/misayaaaaa/article/details/66478422
void Merge(int a[],int left,int mid,int right) {
	int length1 = mid-left+1;
	int length2 = right-mid;
	int *l1 = new int[length1];
	int *l2 = new int[length2];
	for (int i = 0; i < length1; ++i) l1[i] = a[left+i];
	for (int j = 0; j < length2; ++j) l2[j] = a[j+mid+1];
	//存入原内容之后，比较两个序列
	int i = 0,j = 0;
	while (i<length1 && j<length2) {
		if (l1[i] < l2[j]) a[left++] = l1[i++];
		else a[left++] = l2[j++];
	}
	//两序列的剩余部分分别放于结尾
	while (i<length1) a[left++] = l1[i++];
	while (j<length2) a[left++] = l2[j++];
	//分配的内存需要释放掉
	delete []l1;
	delete []l2;
}

void MergeSort(int a[],int left,int right) {
	if (left >= right) return;
    int mid = (left+right)/2;//首先进行分区，然后递归操作
    MergeSort(a,left,mid);
    MergeSort(a,mid+1,right);//第一次将其分为两个区间，进行合并操作
    Merge(a,left,mid,right); //其实Merge直接放到主函数MergeSort里也可以，就是有点冗长。
}

// 归并排序2
//https://blog.csdn.net/a130737/article/details/38228369
void Merge(int *A, int *L, int leftLength, int *R, int rightLength) {
	int i = 0, j = 0, k = 0; 
	while (i < leftLength && j < rightLength) {
		if(L[i] < R[j]) A[k++] = L[i++];
		else A[k++] = R[j++];
	}
	while(i < leftLength)  A[k++] = L[i++];
	while(j < rightLength) A[k++] = R[j++];
}
 
void MergeSort(int *A, int n) {
	if (n < 2) return;
    int mid = n/2, i = 0;
	// create left and right subarrays
    int* L = new int[mid];
    int* R = new int [n - mid];
	for(i = 0;i<mid;i++) L[i] = A[i];
	for(i = mid;i<n;i++) R[i-mid] = A[i];
	MergeSort(L,mid);  
	MergeSort(R,n-mid);  
	Merge(A,L,mid,R,n-mid);
	// the delete operations is very important
	delete [] R;
	delete [] L;
}


// 二分查找：见704题
// 如果把移位操作换成普通的除以2，则内存占用会稍微多一点点。速度影响不大。
    int search(vector<int>& a, int target) {
        int l = 0, r = a.size()-1, mid;
        while(l <= r) {
            mid = (l + r) >> 1; 
            if (a[mid] == target) return mid;
            else if (a[mid] > target) r = mid - 1;
            else l = mid + 1;
        }
        return -1;
    }

/*
补充一个形象地记忆除以2效果的内容：
   数组          | (l+r)/2    |  (l+r+1)/2
[0, 1, 2, 3]    |  (0+3)/2=1 |  (0+3+1)/2=2
[0, 1, 2, 3, 4] |  (0+4)/2=2 |  (0+4+1)/2=2
*/

/* 二叉树的相关算法：
102 中序遍历（同时补充了先序遍历和后序遍历）
105 由先序遍历和中序遍历重建二叉树

*/