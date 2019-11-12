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

void qsort(int* &a, int start, int end) {
    if (end<=start) return;
    int i = start, j = end, pivot = a[i];
    while (i<j) {
        while(a[j]>=pivot && i<j) j--;
        if (i<j) a[i++] = a[j];
        while(a[i]< pivot && i<j) i++;  
        if (i<j) a[j--] = a[i];
    }
    a[i] = pivot;
    qsort(a,start,i-1);
    qsort(a,i+1,end);
}

// 插入排序
void insertion(vector<int>& arr){ //如果采用数组的话，需要将数组长度统计出来，或者直接通过参数传递进去。
	for(int i=1;i<arr.size();i++){
		int temp=arr[i];
		int j=i-1;
		for(;j>=0 && temp<arr[j];j--){
			arr[j+1] = arr[j];
		}
		arr[j+1] = temp;
	}
}


int main() {
	int array[11] = {15,7, 3, 19, 4, 63, 2, 99, 18, 1, 25}; 
	// qsort(array, 0, 10);
	for(int i = 0; i < 11; i++)  
		cout << array[i] << "  ";   
    cout<<endl;  
    return 0;  
}
