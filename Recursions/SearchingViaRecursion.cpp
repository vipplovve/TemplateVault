#include <bits/stdc++.h>
using namespace std;

bool sortedornot(int *arr,int size)
{
    if(size ==0 || size==1)
    return true;
    else if(arr[0]>arr[1])
    return false;
    else
    {
        return sortedornot(arr+1,size-1);
    }
}
int main()
{
    int choice,len;
    cout<<"Enter Array Length: ";
    cin>>len;

    int arr[len];
    for(int x=0;x<len;x++)
    cin>>arr[x];

    cout<<"Enter your choice: ";
    cin>>choice;

    switch(choice)
    {
        case 1:
        
        switch(sortedornot(arr,len))
        {
            case 1:
            cout<<"Array is Sorted.";
            break;
            case 0:
            cout<<"Array is Unsorted.";
            break;
        }
        break;
    }
    return 0;
}