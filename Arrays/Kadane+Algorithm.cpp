//most optimised way of finding the max sum subarray.

#include <bits/stdc++.h>
using namespace std;
int kadanesAlgo(int arr[],int len)
{
    int sum=0;
    int ans1=INT_MIN;
    for(int y=0;y<len;y++)
    {
        sum+=arr[y];
        if(sum<0)
        sum=0;
        ans1=max(ans1,sum);
    }
    return ans1;

}
int main()

{
    int len;
    cout<<"Enter length of the array: ";
    cin>>len;
    int array[len]; //defining an array of given length and subsequently taking input to add elements to it.
    for(int i=0;i<len;i++)
        cin>>array[i];
    int answer1=kadanesAlgo(array,len);
    int sum2=0;
    for(int y=0;y<len;y++)
    {   
        sum2+=-array[y];
    }
    int answer2=-sum2+kadanesAlgo(array,len);
    cout<<"The maximum possible sum in this array is (considering it to be a circular array): "<<max(answer1,answer2)<<endl;

    return 0;

}