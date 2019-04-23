// 总结七种排序算法的C++代码（https://blog.csdn.net/liqinzhe11/article/details/78743743）


/*
    算法	  平均时间复杂度	  最好情况	  最坏情况	  空间复杂度	      稳定性
  冒泡排序	   O(N^2)	       O(N)	      O(N^2)	     O(1)	      稳定
  插入排序	   O(N^2)	       O(N)	      O(N^2)	     O(1)	      稳定
  选择排序	   O(N^2)	       O(N^2)	  O(N^2)	     O(1)	      稳定
  希尔排序	  O(N^3/2)	 	              O(N^2)	     O(1)	    不稳定
  堆排序	   O(NlogN)	     O(NlogN)	  O(NlogN)	    O(1)	     不稳定
  归并排序	  O(NlogN)	    O(NlogN)	 O(NlogN)	     O(N)	      稳定
  快速排序	  O(NlogN)	    O(NlogN)	  O(N^2)	    O(logN)	    不稳定
*/


// 插入排序类（1、2）

// 1. 插入排序【时间复杂度：平均O(n^2)，最好O(n)，最坏O(n^2) / 空间复杂度：O(1) / 稳定性：稳定】
void insertSort(int a[], int n) {
    int i, j, tmp;
    for(int i = 1; i < n; ++i) {
        tmp = a[i];
        for(int j = i - 1; j >= 0 && tmp < a[j]; --j) {
            a[j + 1] = a[j]
        }
        a[j + 1] = tmp;  //每一次比较(tmp < a[j])的情况的后一位即a[j + 1]位置是空着的，当不满足上述for循环，则将备份的tmp赋值给那个位置的值。
    }
}


// 2. 希尔排序【时间复杂度：平均O(n1.3)，最好O(n)，最坏O(n2) / 空间复杂度：O(1) / 稳定性：不稳定】
void shellsort(vector<int>& a)
{
    int n = a.size();
    for (int increment = n / 2; increment > 0; increment /= 2)
    {
        for (int i = increment; i < n; i++)
        {
            int insert_num = a[i], j;
            for (j = i - increment; j >= 0; j -= increment)
            {
                if (a[j] > insert_num)
                    a[j + increment] = a[j];
                else
                    break;
            }
            a[j + increment] = insert_num;
        }
    }
}


// 选择排序类（3、4）

// 3. 选择排序【时间复杂度：平均O(n^2)，最好O(n^2)，最坏O(n^2) / 空间复杂度：O(1) / 稳定性：不稳定】
void selectSort(int a[], int n) {
    int tmp, k;
    for(int i = 0; i < n; ++i) {
        k = i;
        for(int j = i + 1; j < n; ++j) {
            if(a[k] > a[j])
                k = j;
        }
        tmp = a[i];
        a[i] = a[k];
        a[k] = tmp;
    }
}


// 4. 堆排序【时间复杂度：平均O(nlogn)，最好O(nlogn)，最坏O(nlogn) / 空间复杂度：O(1) / 稳定性：不稳定】
void make_heap(vector<int>& a, int size) //size的当前堆的大小，也就是数组的前size个数
{
    for (int i = size - 1; i > 0; i--)
    {  //为什么是N/2，是因为堆中树叶的个数是N/2：建立最大堆，建堆的过程是从N/2的位置开始，将父节点与子节点比较，如果子节点大于父节点则交换
        if (i % 2 && a[i] > a[(i - 1) / 2])  //奇数
            swap(a[i], a[(i - 1) / 2]);
        else if (i % 2 == 0 && a[i] > a[(i - 2) / 2])  //偶数
            swap(a[i], a[(i - 2) / 2]);
    }
}
void heapsort(vector<int>& a)
{
    int n = a.size();
    while (n)
    {
        make_heap(a, n);  //每次把新的最大元素移到堆顶，也就是a[0]
        n--;
        swap(a[0], a[n]);  //然后把当前最大移动到后面来作为排好序的元素
    }
}


// 交换排序类（5、6）

// 5. 冒泡排序【时间复杂度：平均O(n2)，最好O(n)，最坏O(n2) / 空间复杂度：O(1) / 稳定性：稳定】
void bubbleSort(int a[], int n) {
    int tmp;
    for(int i = 0; i < n; ++i) {
        for(int j = n - 1; j > 0; --j) {
            if(a[j] < a[j - 1]) {
                tmp = a[j];
                a[j] = a[j - 1];
                a[j - 1] == tmp;
            }
        }
    }
}

// 5. 冒泡排序优化一
//设置一个标记来标志一趟比较是否发生交换，如果没有发生交换，则数组已经有序
void bubblesort2(vector<int>& a)
{
    int n = a.size();
    bool flag;
    for (int i = 0; i < n; i++)
    {
        flag = false;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j+1])
            {
                swap(a[j], a[j+1]);
                flag = true;
            }
        }
        if (!flag)
            break;
    }
}

// 5. 冒泡排序优化二
//用一个变量记录下最后一个发生交换的位置，后面没有发生交换的已经有序，所以可以用这个值来作为下一次比较结束的位置
void bubblesort3(vector<int>& a)
{
    int n = a.size();
    int flag = n;
    int stop_pos;
    for (int i = 0; i < n; i++)
    {
        stop_pos = flag - 1;
        flag = 0;
        for (int j = 0; j < stop_pos; j++)
        {
            if (a[j] > a[j+1])
            {
                swap(a[j], a[j+1]);
                flag = j + 1;
            }
        }
    }
}


// 6. 快速排序
void quicksortHelper(vector<int>& a, int start, int end)
{
    if (start >= end) return;
    int l = start, r = end;
    int pivot = a[(end - start) / 2 + start];
    while (l <= r)
    {
        while (l <= r && a[r] > pivot)  r--;
        while (l <= r && a[l] < pivot)  l++;
        if (l <= r) swap(a[l++], a[r--]);
    }
    quicksortHelper(a, start, r);
    quicksortHelper(a, l, end);
}
void quicksort(vector<int>& a)
{
    quicksortHelper(a, 0, a.size() - 1);
}


//快排的最差时间复杂度为O(n²)
//通常出现在选择的轴值(pivot)不能将数组划分为两个长度相等的子数组的时候
//一个较好的办法是“三数取中”，查看当前数组的第一个、中间一个和最后一个位置的数组，取其中位数，以此来降低轴值选择得不好的可能性。
int findmiddle(int a, int b, int c)
{
    if (a >= b && a <= c)
        return a;
    else if (b >= a && b <= c)
        return b;
    else
        return c;
}
void quicksortHelper(vector<int>& a, int start, int end)
{
    if (start >= end) return;
    int l = start, r = end;
    int pivot = findmiddle(a[start], a[end], a[(end - start) / 2 + start]);
    while (l <= r)
    {
        while (l <= r && a[r] > pivot)  r--;
        while (l <= r && a[l] < pivot)  l++;
        if (l <= r) swap(a[l++], a[r--]);
    }
    quicksortHelper(a, start, r);
    quicksortHelper(a, l, end);
}
void quicksort(vector<int>& a)
{
    quicksortHelper(a, 0, a.size() - 1);
}


// 7. 归并排序【时间复杂度：平均O(nlogn)，最好O(nlogn)，最坏O(nlogn) / 空间复杂度：O(1) / 稳定性：稳定】
vector<int> mergeHelper(vector<int> &a, int left, int right)
{
    if (left == right) return vector<int> (1, a[left]);
    int mid = (right - left) / 2 + left;
    vector<int> l = mergeHelper(a, left, mid);
    vector<int> r = mergeHelper(a, mid + 1, right);
    //merge
    vector<int> ret;
    int ll = 0, rr = 0;
    while (ll < l.size() && rr < r.size())
    {
        if (l[ll] <= r[rr])     ret.push_back(l[ll++]);
        else                    ret.push_back(r[rr++]);
    }
    while (ll < l.size()) ret.push_back(l[ll++]);
    while (rr < r.size()) ret.push_back(r[rr++]);
    return ret;
}
 
void mergesort(vector<int>& a)
{
    a = mergeHelper(a, 0, a.size() - 1);
}
