#include <iostream>
#include <string>
#include <deque>
using namespace std;

//对基数排序的第n位进行排序 如个位数就输入 1 ，十位数输入 10
void RadixSortMiddle(int digit,int *ar,int n)
{
    deque<int> que_main,que1,que2,que3,que4,que5,que6,que7,que8,que9,que0;
    
    //个位数排序
    for(int m=0;m<n;m++)
    {
        switch (ar[m]%(digit*10)/digit)
        {
            case 0:
                que0.push_back(ar[m]);
                break;
            case 1:
                que1.push_back(ar[m]);
                break;
            case 2:
                que2.push_back(ar[m]);
                break;
            case 3:
                que3.push_back(ar[m]);
                break;
            case 4:
                que4.push_back(ar[m]);
                break;
            case 5:
                que5.push_back(ar[m]);
                break;
            case 6:
                que6.push_back(ar[m]);
                break;
            case 7:
                que7.push_back(ar[m]);
                break;
            case 8:
                que8.push_back(ar[m]);
                break;
            case 9:
                que9.push_back(ar[m]);
                break;
        }
    }
    while(!que0.empty())
    {
        que_main.push_back(que0.front());
        que0.pop_front();
    }
    while(!que1.empty())
    {
        que_main.push_back(que1.front());
        que1.pop_front();
    }
    while(!que2.empty())
    {
        que_main.push_back(que2.front());
        que2.pop_front();
    }
    while(!que3.empty())
    {
        que_main.push_back(que3.front());
        que3.pop_front();
    }
    while(!que4.empty())
    {
        que_main.push_back(que4.front());
        que4.pop_front();
    }
    while(!que5.empty())
    {
        que_main.push_back(que5.front());
        que5.pop_front();
    }
    while(!que6.empty())
    {
        que_main.push_back(que6.front());
        que6.pop_front();
    }
    while(!que7.empty())
    {
        que_main.push_back(que7.front());
        que7.pop_front();
    }
    while(!que8.empty())
    {
        que_main.push_back(que8.front());
        que8.pop_front();
    }
    while(!que9.empty())
    {
        que_main.push_back(que9.front());
        que9.pop_front();
    }
    
    for(int m=0;m<n;m++)
    {
        ar[m]=que_main.front();
        que_main.pop_front();
    }
    
}

void RadixSort(int *ar,int n)
{
    RadixSortMiddle(1,ar,n);
    RadixSortMiddle(10,ar,n);
    RadixSortMiddle(100,ar,n);
}

int main()
{
    int array[] ={221,513,44,17,3,1,20};
    
    RadixSort(array, sizeof(array)/sizeof(array[0]));
    for (int m=0;m<sizeof(array)/sizeof(array[0]);m++)
        cout << array[m] << ' ' ;
    cout <<endl;

}
