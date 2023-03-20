#include <iostream>
#include <vector>
using namespace std;

// 矩阵快速幂
// https://leetcode.cn/problems/fei-bo-na-qi-shu-lie-lcof/solution/fei-bo-na-qi-shu-lie-by-leetcode-solutio-hbss/
    vector<vector<long>> pow(vector<vector<long>>& a, int n) {
        vector<vector<long>> ret{{1, 0}, {0, 1}}; // unit matrix
        while (n > 0) {
            if (n & 1) {  // 如果是奇数，位运算更快。一定会进入该逻辑。
                ret = multiply(ret, a);
            }
            n >>= 1; // 除以2，位运算更快
            a = multiply(a, a);
        }
        return ret;
    }

    vector<vector<long>> multiply(vector<vector<long>>& a, vector<vector<long>>& b) {
        vector<vector<long>> c{{0, 0}, {0, 0}};
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                c[i][j] = (a[i][0] * b[0][j] + a[i][1] * b[1][j]) % MOD; // 取模是题目要求。
            }
        }
        return c;
    }
    /* case1
    n=8
   a a a a a a a a

   n=4
   a2 a2 a2 a2

   n=2
   a4 a4

   n=1
   a8

   然后(n & 1 == 1)进入if逻辑。ret = I * a8
    */


   /* case2
    n=7
   a a a a a a a 
   一开始就触发奇数逻辑：ret = I * a

   n = 3
   a = a2
    再次触发奇数逻辑：ret = ret * a2 = a3

   n = 1
   a = a4
   
    再次触发奇数逻辑：ret = ret * a4 = a7

   n = 0
   a = a8
   end
   */



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
    if (l >= r) return;
    int i = partition(array, l, r);   
    QuickSort(array, l, i - 1);
    QuickSort(array, i + 1, r);
}

// 最一般的：从小到大，每次以最左边
// 有关快排较为综合的考虑见本脚本末尾。总结了不少。
void QuickSort_dir(int array[], int start, int last) {   
    if (start >= last) return; //只有一个元素时(甚至没有元素时，这种情况是存在的，比如一个已经从小到大排好的数组)到达递归终点
    int i = start, j = last;
    if (j > i + 1) {
        int index = i + rand()%(j-i-1);
        swap(array[i],array[index]);
    }
    int pivot = array[i];
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

void quicksort(int a[],int low, int high) { // 就是上一个函数的简写。没什么不同。
    if (low>=high) return;
    int i = low, j = high,pivot = a[i];
    while(i < j) {
        while(a[j]>=pivot && i<j) j--;
        if (i<j) a[i++] = a[j];
        while(a[i]<pivot && i<j) i++;
        if (i<j) a[j--] = a[i];
    }
    a[i] = pivot;
    quicksort(a,low,i-1);
    quicksort(a,i+1,high);
}

void quicksort(int a[],int low, int high) {
    if (low>=high) return;
    int i = low, j = high,pivot = a[i];
    while(i < j) {
        while(a[j]>=pivot && i<j) j--;
        while(a[i]<=pivot && i<j) i++;
        if (i<j) swap(a[i],a[j]);
    }
    swap(a[low],a[i]);
    quicksort(a,low,i-1);
    quicksort(a,i+1,high);
}

//wk的快速选择方法,选择第k小的数。这个算法其实同时还能够保证最后的数组的前k个数是最小的k个数（可能并非顺序）。
void qsort(vector<int>& input, int start, int end, int k){
        if(end - start + 1 <= k) return;
        int i = start, j = end, mid = input[start];
        while(i < j){
            while(i < j && input[j] >= mid) j--;
            while(i < j && input[i] <= mid) i++;
            if(i < j) swap(input[i], input[j]);
        }
        swap(input[start],input[i]);

        if(i - start + 1> k) qsort(start, i - 1, k, input);    //这个地方注意-1
        else if(i - start + 1 == k) return;
        else qsort(i + 1, end, k - (i - start + 1), input);
    }

// 补一句：选出k个最小的数，可以使用大根堆和小根堆两种思想。全部数据创建小根堆，然后逐一pop选出顶端k次，获取到了k个最小值。
// 也可以仅建立k大小的大根堆，每次把更大的数据pop出去。最后剩下的堆里的就是k个最小的数。后者适合内存相对较小的情况。

//堆排序选出k个最小的数
class Solution {
public:
    void downward(int pos, int k, vector<int>& a){
        int target = -1;
        if(2 * pos < k && a[2 * pos] > a[pos]){ //左叶子结点比根节点大
            swap(a[pos], a[2 * pos]);
            target = 2 * pos;
        }
        if(2 * pos + 1 < k && a[2 * pos + 1] > a[pos]){ //右叶子结点比根节点大
            swap(a[pos], a[2 * pos + 1]);
            target = 2 * pos + 1;
        }
        if(target != -1) downward(target, k, a);
    }
    
    void upward(int pos, vector<int>& a){
        if(pos == 0) return;
        if(a[pos] > a[pos >> 1]){
            swap(a[pos], a[pos >> 1]);
            upward(pos >> 1, a);
        }
    }
    
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        //大根堆
        if(input.size() < k || input.size() == 0 || k == 0) return {};
        vector<int> heap(k);
        for(int i=0; i<k; i++){
            heap[i] = input[i];
            upward(i, heap);
        }
        for(int i=k; i<input.size(); i++){
            if(input[i] < heap[0]){
                heap[0] = input[i];
                downward(0, k, heap);
            }
        }
        return heap;
    }
};


// 延伸：由快速排序衍生出的同类算法，快速选择。第215题。选第k最大的数
int findKthLargest2(vector<int>& nums, int k) {
    int high = nums.size();
    int low = 0;
    while (low < high) {
        int i = low;
        int j = high-1;
        if (j > i + 1) {
            int index = i + rand()%(j-i);
            swap(nums[i],nums[index]);
        }
        int pivot = nums[low];
        while (i <= j) { // i <= j该等号可以去掉
            while (i <= j && nums[i] >= pivot) i++; // i <= j该等号可以去掉
            while (i <= j && nums[j] < pivot) j--; // nums[j] < pivot可加可不加等号。但是前面的i<=j必须加等号。
            if (i < j) swap(nums[i++],nums[j--]); //  if (i < j) 这个条件不能去掉。++ -- 可以去掉。
        }
        swap(nums[low],nums[j]);
        if (j == k-1) return nums[j];
        else if (j < k-1) low = j+1;
        else high = j;   
    }
    return 0;
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

// 堆排序 可以直接百度。大顶（根）堆。priority_queue。
～堆排序，选择第K大的数也可以用快速选择（见wk整理的剑指offer29题）



// 二分查找：见704题
// 旋转数组的二分查找————33题
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
    

// 二分查找的几种变体：
// https://blog.csdn.net/zlx_code/article/details/89081362
// 查找第一个值等于给定值的元素
int search2(vector<int>& a, int target) {
        int l = 0, r = a.size()-1, mid;
        while(l <= r) {
            mid = (l + r) >> 1; 
            if (a[mid] == target) {
                // 如果相等，那么先查mid是否为0，或者 mid的前一个值是否等于value
                // 如果是第一个数，或者mid前一个数不等于 value，那么就找到第一个值等于value的元素
                if( (mid == 0) || (a[mid - 1] != target)) return mid;
                // 否则 value 肯定在 [low , mid - 1] 区间，更新high的值
                else r = mid - 1;   
            }
            else if (a[mid] > target) r = mid - 1;
            else l = mid + 1;
        }
        return -1;
    }
// 查找最后一个值等于给定值的元素
int search2(vector<int>& a, int target) {
        int l = 0, r = a.size()-1, mid;
        while(l <= r) {
            mid = (l + r) >> 1; 
            if (a[mid] == target) {
                if( (mid == a.size()-1) || (a[mid + 1] != target)) return mid;
                // 否则 value 肯定在 [low , mid - 1] 区间，更新high的值
                else l = mid + 1;
            }
            else if (a[mid] > target) r = mid - 1;
            else l = mid + 1;
        }
        return -1;
    }
// 查找第一个大于等于给定值的元素
int search3(vector<int>& a, int target) {
        int l = 0, r = a.size()-1, mid;
        while(l <= r) {
            mid = (l + r) >> 1; 
            if (a[mid] >= target) {
                if((mid == 0) || (a[mid - 1] < target)) return mid;
                else r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return -1;
    }

// 查找最后一个小于等于给定值的元素
int search4(vector<int>& a, int target) {
        int l = 0, r = a.size()-1, mid;
        while(l <= r) {
            mid = (l + r) >> 1; 
            if (a[mid] <= target) {
                if((mid == a.size()-1) || (a[mid + 1] > target)) return mid;
                else l = mid + 1;
            }
            else {
                r = mid - 1;
            }
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
94 中序遍历（同时补充了先序遍历和后序遍历）
102 层序遍历
105 由先序遍历和中序遍历重建二叉树
*/

// KMP 字符串匹配算法
void getnext(vector<int>& next, string& p){
    int k = 0;
    for(int i=1; i<p.size(); i++){
        k = next[i];
        while(k && p[k] != p[i]) k = next[k];
        next[i+1] = (p[k] == p[i]) ? k + 1: 0;
    }
}

int kmp(vector<int>& next, string& s, string& p){
    int k = 0, pLen = p.length();
    for(int i=0; i<s.size(); i++) {
        while(k && s[i] != p[k]) k = next[k];
        if(s[i] == p[k]) k++;
        if(k == pLen) return i - p.size() + 1;
    }
    return -1;
}


//整数转字符串
string transform(int num) {
    string res;
    stringstream ss;
    ss << num;
    ss >> res;
    if (num < 10) res = "0" + res;
    return res;
}



// 最新总结：快排的几种小变体
// 共同点：关键步骤：1~5
void quicksort(vector<int>& a,int l, int r) { // 建议用这种变体。少写两行。
    // 1.终结条件判断
    if (l>=r) return;
    // 2.初始化双指针i、j和  pivot(最好采用随机的写法)
    int i = l, j = r;
    if (j - i > 1) {
        int temp = i + rand() % (j - i - 1);  // +1, -1, +0 应该都可以啦。建议+0。
        swap(a[temp],a[i]);
    }
    int pivot = a[i];
    // 3.循环，双指针彼此靠近，交换。
    while(i<j) {
        while(i<j && a[j]>=pivot) j--;
        while(i<j && a[i]<=pivot) i++; // 此处等号必须有，否则无法过{5,2,3,1}
        if (i < j) swap(a[i],a[j]); // 这一行前面 可以加 if (i < j) ，也可以不加。
    }
    // 4. 把轴点移到中间来。确保轴点位置为i。
    swap(a[l], a[i]); // 不管上面那个小于加不加等号，这一行都是必须的。（只是会导致中间过程不同）
    // 5. 分而治之
    quicksort(a,l,i-1);
    quicksort(a,i+1,r);
}

void quicksort_2(vector<int>& a,int l, int r) {
    // 1.终结条件判断
    if (l>=r) return;
    // 2.初始化双指针i、j和pivot(最好采用随机的写法)
    int i = l, j = r;
    if (j - i > 1) {
        int temp = i + rand() % (j - i - 1);
        swap(a[temp],a[i]);
    }
    int pivot = a[i];
    // 3.循环，双指针彼此靠近，交换。
    while(i<j) {
        while(i<j && a[j]>=pivot) j--;
        if (i<j) a[i++] = a[j];
        while(i<j && a[i]<pivot) i++; // 此处小于号是通过的。等号也可以通过。
        if (i<j) a[j--] = a[i];
    }
    // 4. 把轴点移到中间来。确保轴点位置为i。案例分析：vector<int> a{5,1,2,4,7,8,9};
    a[i] = pivot;
    // 5. 分而治之
    quicksort_2(a,l,i-1);
    quicksort_2(a,i+1,r);
}


// 网上看到一种超快的写法，还能通过leetcode912的极端针对快排的例子：
void quicksort_online(vector<int>& a, int l, int r){
        if(l >= r) return ;
        int i = l - 1, j = r + 1;
        int x = a[l + r >> 1];
        while(i < j){
            i++;
            while(x > a[i]) i++;
            j--;
            while(x < a[j]) j--;
            if(i < j) swap(a[i], a[j]);
        }
        quicksort_online(a, l, j);
        quicksort_online(a, j + 1, r);
    }

// 其他变体：逆序，选择第K大的数。
int findKthLargest2(vector<int>& nums, int k) {
    // 这种方法里有一处等号需要注意。不太自然。
    int high = nums.size();
    int low = 0;
    while (low < high) {
        int i = low;
        int j = high-1;
        if (j > i + 1) {
            int index = i + rand()%(j-i);
            swap(nums[i],nums[index]);
        }
        int pivot = nums[low];
        // 注意，在一般的快排中，i<j的判断条件不能加等号！
        while (i <= j) { // i <= j该等号可以去掉
            while (i <= j && nums[i] >= pivot) i++; // i <= j该等号可以去掉
            while (i <= j && nums[j] < pivot) j--; // i <= j必须加等号！！！nums[j] < pivot可加可不加等号。
            if (i < j) swap(nums[i++],nums[j--]); //  if (i < j) 这个条件不能去掉。++ -- 可以去掉。
        }
        swap(nums[low],nums[j]);
        if (j == k-1) return nums[j];
        else if (j < k-1) low = j+1;
        else high = j;   
    }
    return 0;
}

void quickselect(vector<int>& input, int start, int end, int k){ //wk的快速选择算法,选择第K大的数。
        if(end - start + 1 <= k) return;
        int i = start, j = end, mid = input[start];
        while(i < j){
            while(i < j && input[j] >= mid) j--;
            while(i < j && input[i] <= mid) i++;
            if(i < j) swap(input[i], input[j]);
        }
        swap(input[start],input[i]);

        if(i - start + 1> k) qsort(start, i - 1, k, input);    //这个地方注意-1
        else if(i - start + 1 == k) return;
        else qsort(i + 1, end, k - (i - start + 1), input);
    }

