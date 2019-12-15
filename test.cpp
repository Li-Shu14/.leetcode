void quicksort(int a[], int start, int end) {
    if (start>=end) return;
    int i=start,j=end,pivot=a[i];
    while (i<j) {
        while (a[j] >= pivot && i<j) j--;
        if (i < j) a[i++] = a[j];
        while (a[i] < pivot &&  i<j) i++;
        if (i<j)   a[j--] = a[i];
    }
    a[i] = pivot;
    quicksort(a,start,i-1);
    quicksort(a,i+1,end);
}

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