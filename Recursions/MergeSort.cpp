#include <bits/stdc++.h>

using namespace std;

void merge(int *a,int start,int end)
{
    int mid=(start+end)/2;

    int l1=mid-start+1,l2=end-mid;

    int *f= new int[l1];
    int *s=new int[l2];

    int mainarrayindex=start;

    for(int i=0;i<l1;i++)
    f[i]=a[mainarrayindex++];

    mainarrayindex=mid+1;

    for(int i=0;i<l2;i++)
    s[i]=a[mainarrayindex++];

    int i1=0,i2=0;
    mainarrayindex=start;

    while(i1<l1 && i2<l2)
    {
        if(f[i1]<s[i2])
        a[mainarrayindex++]=f[i1++];
        else
        a[mainarrayindex++]=s[i2++];
    }

    while(i1<l1)
    a[mainarrayindex++]=f[i1++];

    while(i2<l2)
    a[mainarrayindex++]=s[i2++];
 
}
void mergesort(int *a,int start, int end)
{
    if(start>=end)
    return;

    int mid=(start+end)/2;
        
    mergesort(a,start,mid);
    mergesort(a,mid+1,end);
    merge(a,start,end);

}

int main()
{
    int len;
    cout<<"Enter Array Length: ";
    cin>>len;
    int *arr=new int[len];
    for(int z=0;z<len;z++)
    cin>>arr[z];
    cout<<"The Original array is: ";
    for(int x=0;x<len;x++)
    cout<<arr[x]<<" ";
    mergesort(arr,0,len);
    cout<<"\nThe Sorted array is: ";
    for(int x=0;x<len;x++)
    cout<<arr[x]<<" ";
    return 0;
}
