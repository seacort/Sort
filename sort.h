#ifndef SORT_H_
#define SORT_H_

#include <iostream>
#include <vector>

#define SIZEOF(ar) (sizeof(ar)/sizeof(ar[0]))

using namespace std;

void show (int *ar ,int a)
{
    for (int temp= 0 ;temp <a ;temp++)
        cout << ar[temp] <<" " ;
    cout <<endl;
}

//交换两个数
void swap (int &a ,int &b )
{
    a = a^b;
    b = a^b;
    a = a^b;
}

//冒泡法
bool bubble_sort_v0(int *ar_begin,int * ar_end)
{
    bool flag=0;
    for (int timer=0;(ar_begin+timer) != ar_end ; timer++)
    {
        if(*(ar_begin+timer) > *(ar_begin+timer+1))
        {
            swap(*(ar_begin+timer), *(ar_begin+timer+1));
            flag = 1;
        }
    }
    return flag;
}

void bubble_sort(int *ar,int n,int &timer )
{
    for ( ; n > 0  ; n--)
    {
        if(bubble_sort_v0(ar, ar+n-1)==0)
            break;
        timer ++;
    }
}


//选择排序
void ChoiceSortTemp(int *ar_begin,int *ar_end)
{
    for (int temp=1 ;ar_begin+temp < ar_end ; temp++)
    {
        if (*(ar_begin) > *(ar_begin+temp))
            swap(*(ar_begin) , *(ar_begin+temp));
    }
}

void ChoiceSort(int *ar, int a)
{
    for(int temp=0 ; temp < a ;temp++)
    {
        ChoiceSortTemp((ar+temp), (ar+a));
    }
}


//简单插入排序,n为数量，非数组下标
void InsertSortTemp (int *ar , int n ,int add)
{
    for (int temp = 0; temp < n ; temp++)
    {
        if( ( add < ar[temp]) )                                      //添加数字小于该扫描的数字时
        {
            for (int * ptr = (ar+n-1) ;ptr >= ar+temp ; ptr--)         //移动
                *(ptr+1)= *ptr;
            ar[temp] = add;                                          //
            break;
        }
        else if (temp == n-1)
            ar[n] = add;
    }
}

void InsertSort_mid(int *ar1,int n1 ,int *ar2,int n2)
{
    int temp_ar[n2];
    memcpy(temp_ar, ar2, n2*sizeof(ar2[0]));
    for (int m=0;m<n2;m++)
    {
        InsertSortTemp(ar1, n1+m, temp_ar[m]);
    }
}

void InsertSort (int *ar ,int n)
{
    int array[n];
    memcpy(array, ar, n*sizeof(ar[0]));
    
    for (int temp = 1 ; temp < n ;temp++)
    {
        InsertSortTemp(ar, temp, array[temp]);
    }
}

//希尔排序
bool ShellSort_smaller (int &a , int &b)
{
    if (a > b)
    {
        swap(a, b);
        return 1;
    }
    return 0;
}

void ShellSort (int *ar, int n)
{
    for (int m = n/2 ; m > 1 ; m = m/2)       // m = step_width
    {
        int temp = 0;
        while ((temp+m) < n)
        {
            ShellSort_smaller(ar[temp], ar[temp+m]);
            ++temp;
        }
    }
    
    //gap = 1 ,insert sort
    for (int temp = n-1 ; temp >= 1  ; temp--)
    {
        int tep = temp;
        while (ShellSort_smaller(ar[tep-1], ar[tep]) == 1)
            tep++;
    }
}

//快速排序
int FastSort_basic (int *ar,int left, int right )
{
    int stand = ar[left];
    while (right > left)
    {
        while(right > left)
        {
            if (ar[right] < stand )
            {
                ar[left]=ar[right];
                left++;
                break;
            }
            right--;
        }
        while (right > left)
        {
            if (ar[left] > stand )
            {
                ar[right]=ar[left];
                right--;
                break;
            }
            left++;
        }
    }
    ar[left]=stand;
    return left;
}

void FastSort(int *ar , int left ,int right)
{
    if(left>right)
        return;
    int mid = FastSort_basic(ar, left, right);
    
    FastSort(ar, left,mid-1);
    FastSort(ar, mid+1,right);
}

//归并排序的调用函数 包含数组1和数组2以及其长度信息（数量，非下标）
void GuibingSort_basic (int *ar1,int n1,int *ar2,int n2)
{
  //  cout << "deeper"<< " n1 , n2 = " << n1 <<" " <<n2 <<endl;
    if((n1 + n2) == 2)
    {
        if(ar1[0]>ar1[1])
            swap(ar1[0], ar1[1]);
 //       cout << "After 1:1 sort :"<<endl;
//        show(ar1,2);
 //       cout << "lighter : " <<endl;
        return;
    }
    else if (n1+n2 < 2)
    {
 //       cout << "lighter : " <<endl;
        return;
    }
    
//    cout << "ar1 : " ;
 //   show(ar1, n1);
//    cout << "ar2 : " ;
//  show(ar2, n2);
    
    //判断数组长度的奇偶性 ar1 ar2奇偶
    GuibingSort_basic(ar1, n1/2, ar1+n1/2, (n1%2)+n1/2);
    GuibingSort_basic(ar2, n2/2, ar2+n2/2, (n2%2)+n2/2);
    
    //排序
    //复制ar2 因为排序算法会损坏一个数组内的数据
 //   cout << "Before sort : " << " n1 , n2 = " << n1 <<" " <<n2 <<endl;
 //   show(ar1, n1+n2);
    InsertSort_mid(ar1, n1, ar2, n2);
//    cout << "After sort : " ;
 //   show(ar1, n1+n2);
}

void GuibingSort (int *ar,int n)
{
    //判断数组长度的奇偶性 ar1奇偶
    GuibingSort_basic(ar, n/2, ar+n/2, (n%2)+n/2);
}

//i is root ,n is max number of the array,i is the index of array ,not ar[] num
void HeapSort_Max(int *ar,int i,int n)
{
    i--;
    if (ar[i] < ar[2*i] and 2*i < n)
        swap(ar[i], ar[2*i]);
    if (ar[i] < ar[2*i+1] and 2*i+1 < n)
        swap(ar[i], ar[2*i+1]);
}

void HeapSort (int *ar,int n)
{
    if(n<=1)
        return;
    // root_index is index (1 to n),not array number []
    for (int root_index = n/2;root_index >=1;root_index--)
    {
        HeapSort_Max(ar, root_index, n);
    }
    HeapSort(++ar, --n);
}

#endif
