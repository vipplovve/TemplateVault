#include <bits/stdc++.h>
using namespace std;

int partition(int *a,int start,int end)
{
    int pivot=a[start];
    int count=0;

    for(int x=start+1;x<=end;x++)
    if(a[x]<=pivot)
    count++;

    int index=start +count;
    swap(a[index],a[start]);
    
    int i=start,j=end;

    while(i<index && j>index)
    {
        while(a[i]<=pivot)
        i++;

        while(a[j]>=pivot)
        j--;

        if(i<index && j>index)
        {
        swap(a[i],a[j]);
        i++;
        j--;
        }
    }

}

void quicksort(int *a,int start, int end)
{
    if(start>=end)
    return;

    int p=partition(a,start,end);
    quicksort(a,start,p-1);
    quicksort(a,p+1,end);
}

int main()
{
    int len;
    cout<<"Enter Array size: ";
    cin>>len;
    int arr[len];
    
    cout<<"Input the Array: ";
    for(int x=0;x<len;x++)
    cin>>arr[x];

    cout<<"The orginal Array is: ";
    for(int x=0;x<len;x++)
    cout<<arr[x]<<" ";

    quicksort(arr,0,len-1);

    cout<<"\nThe Sorted Array is: ";
    for(int x=0;x<len;x++)
    cout<<arr[x]<<" ";
    return 0;
}
