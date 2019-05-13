// 核心思想：“分”与“合”
// 主体流程：先将一个序列分成很多个不能再分割的子序列，将各个子序列分别排序后再将子序列合并。其实就是重复两个步骤：【1】分【2】合并。


/* 
   【1】怎么分?
   比如说一个序列:12,23,1,44,233,10,9,8。
   我们先分成两段：12,23,1,44 和 233,10,9,8。
   发现还能再分成4段：12,23 和 1,44----233,10 和 9,8。
   再分成8段：12--23--1--44 和 233--10--9--8。

   【2】怎么排序怎么合并?
   这时候开始把子序列进行“排序”和“合并”，一个元素就是有序的。所以不用排序。
   合并成2个一组排序得到：12,23--1,44----10,233--8,9。
   再合并成4个一组排序得到：1,12,23,44----8,9,10,233。
   最后合并得到最终结果：1,8,9,10,12,23,44,233。
*/

// 【1】分段的代码
void mergesort(int a[], int first, int last, int temp[])  
{  
    if (first < last)  
    {  
        int mid = (first + last) / 2;  
        mergesort(a, first, mid, temp);    //左边有序  
        mergesort(a, mid + 1, last, temp); //右边有序  
        mergearray(a, first, mid, last, temp); //再将二个有序数列合并  
    }  
}

// 【2】合并的代码
void mergearray(int a[], int first, int mid, int last, int temp[])  
{  
    int i = first, j = mid + 1;  
    int m = mid,   n = last;  
    int k = 0;        
    while (i <= m && j <= n)  
    {  
        if (a[i] <= a[j])  
            temp[k++] = a[i++];  
        else  
            temp[k++] = a[j++];  
    }  
    while (i <= m)  
        temp[k++] = a[i++];    
    while (j <= n)  
        temp[k++] = a[j++];
}

// 【3】整体代码
#include<iostream>  
#include<math.h>  
#include<stdlib.h>  
using namespace std;  
  
//将有二个有序数列a[first...mid]和a[mid...last]合并。  
void mergearray(int a[], int first, int mid, int last, int temp[])  
{  
    int i = first, j = mid + 1;  
    int m = mid,   n = last;  
    int k = 0;        
    while (i <= m && j <= n)  
    {  
        if (a[i] <= a[j])  
            temp[k++] = a[i++];  
        else  
            temp[k++] = a[j++];  
    }       
    while (i <= m)  
        temp[k++] = a[i++];    
    while (j <= n)  
        temp[k++] = a[j++];     
    for (i = 0; i < k; i++)  
        a[first + i] = temp[i];  
}  

void mergesort(int a[], int first, int last, int temp[])  
{  
    if (first < last)  
    {  
        int mid = (first + last) / 2;  
        mergesort(a, first, mid, temp);    //左边有序  
        mergesort(a, mid + 1, last, temp); //右边有序  
        mergearray(a, first, mid, last, temp); //再将二个有序数列合并  
    }  
}  

bool MergeSort(int a[], int n)  
{  
    int *p = new int[n];  
    if (p == NULL)  
        return false;  
    mergesort(a, 0, n - 1, p);  
    delete[] p;  //删除p临时数组
    return true;  
}  

int main()  
{  
    int i=0,temp=0;  
    int a[10]={0};  
    for(i=0;i<10;i++)  
{    
 a[i]=rand();  
 cout<<a[i]<<" ";  
}  
cout<<endl;  
MergeSort(a,10);  
for(i=0;i<10;i++) 
{     
    cout<<a[i]<<" ";  
}  
return 0;  
 }  
