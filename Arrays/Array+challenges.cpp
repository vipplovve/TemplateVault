//array challenges.

//1. given an array, output the max element until the ith element inputted by the user.

//2. given an array, output the sum of each subarray.

//3. find the longest length of arithmetic subarray in a given array. google kickstart#1.

//4. find no. of record-breaking days. google kickstart #2.

//5. minimum index of repetitive element.

//6. returning indices of subarray containing the required sum.

//7. find the smallest positive number missing from the given array.

//8. find the pair of elements which give out the input sum value.

#include <bits/stdc++.h>
using namespace std;

int main()  

{   int op;
    cout<<"Which Operations? ";
    cin>>op;
    switch(op)
    {
        case 1:
        {int minn=INT_MIN;
        int len,ind;
        cout<<"Enter the length of the Array: ";
        cin>>len;
        int arr[len];
        cout<<"Enter the elements of the Array:- \n";
        for(int j=0;j<len;j++)
        {
            cin>> arr[j];
        }
        cout<<"Enter the index: ";
        cin>>ind;
        for(int j=0;j<=ind;j++)
        {
            minn=max(arr[j],minn);
        }
        cout<<minn;
        }
        break;

        case 2:
        {
            int len;
            cout<<"Enter the length of the Array: ";
            cin>>len;
            int arr[len];
            cout<<"Enter the elements of the Array:- \n";
            for(int j=0;j<len;j++)
            {
                cin>>arr[j];
            }
            cout<<"Printing the sum of all possible subarrays:- \n";
            for(int x=0;x<len;x++)
            {
                int sum=0;
                for(int y=x;y<len;y++)
                {
                    sum+=arr[y];
                    cout<<sum<<endl;
                }

            }
        }
        break;

        case 3:
        {
            int len;
            cout<<"Enter the length of the Array: ";
            cin>>len;
            int arr[len];
            cout<<"Enter the elements of the Array:- \n";
            for(int j=0;j<len;j++)
            {
                cin>>arr[j];
            }

            int ans=2;
            int diff=arr[1]-arr[0];
            int x=2;
            int curr=2;

            while(x<len)
            {
                if(diff == arr[x]-arr[x-1])
                {curr++;}
                else
                {
                    diff=arr[x]-arr[x-1];
                    curr=2;
                }

                ans=max(ans,curr);
                x++;

            }
            cout<<"The maximum length of arithmetic subarray is: "<<ans<<endl;
        }
        break;

        case 4:
        {
            int len;
            cout<<"Enter the length of the Array: ";
            cin>>len;
            int arr[len+1];
            arr[len]=-1;
            cout<<"Enter the elements of the Array:- \n";
            
            for(int j=0;j<len;j++)
            {
                cin>>arr[j];
            }
            
            int ans=0;
            int check=-1;

            for(int x=0;x<len;x++)
            {
                if(arr[x]>check || arr[x]>arr[x+1])
                {
                    ans++;
                }
                check=max(check,arr[x]);
            }
            cout<<"No. of record breaking days are: "<<ans<<endl;
        }
        break;

                
        case 5:
        {
            int len;
            cout<<"Enter the length of the Array: ";
            cin>>len;
            int arr[len];
            cout<<"Enter the elements of the Array:- \n";
            for(int j=0;j<len;j++)
            {
                cin>>arr[j];
            }

            int number=INT_MAX;
            const int len2=1e5;
            int checkarray[len2];
            for(int x=0;x<=len2;x++)
            {
                checkarray[x]=-1;
            }
            for(int y=0;y<len;y++)
            {
                if(checkarray[arr[y]] != -1)
                {
                    number=min(checkarray[arr[y]],number);
                }
                else
                {
                    checkarray[arr[y]]=y;
                }

            }
            if(number==INT_MAX)
            {cout<<-1;}
            else
            {cout<<"The minimum repetitive element's index is: "<<number<<endl;}
        }
        break;

        case 6:
        {
            int len;
            cout<<"Enter the length of the Array: ";
            cin>>len;
            int arr[len];
            cout<<"Enter the elements of the Array:- \n";
            for(int j=0;j<len;j++)
            {
                cin>>arr[j];
            }
            int sum,p1=0,p2=0,checksum=0,x,y;
            cout<<"Enter the sum you wish to get: ";
            cin>>sum;
            while(p2<len && checksum+arr[p2]<=sum)
            {
                checksum+=arr[p2];
                p2++;
            }
            if(checksum==sum)
            {
                cout<<"The required indices are: "<<p1<<" to "<<p2<<endl;
                break;
            }
            while(p2<len)
            {
                checksum+=arr[p2];
                while(checksum>sum)
                {
                    checksum-=arr[p1];
                    p1++;

                }
                if(checksum==sum)
                {
                    x=p1;
                    y=p2;
                    break;
                }
                p2++;

            }
            cout<<"The required indices are: "<<p1<<" to "<<p2<<endl;
        }
        break;

        case 7:

        {
            int len;
            cout<<"Enter the length of the Array: ";
            cin>>len;
            int arr[len];
            cout<<"Enter the elements of the Array:- \n";
            for(int j=0;j<len;j++)
            {
                cin>>arr[j];
            }
            const int e6=1e5;
            int checkarr[e6];
            for(int y=0;y<e6;y++)
                checkarr[y]=0;

            for(int y=0;y<len;y++)
            {
                if(arr[y]>=0)
                    checkarr[arr[y]]=1;

            }
            for(int z=1;z<e6;z++)
            {
                if(checkarr[z]==0)
                {
                    cout<<"The smallest non-negative missing number is: "<<z;
                    break;
                }
            }
        }
        break;

        case 8:
        {
            int len;
            cout<<"Enter the length of the Array: ";
            cin>>len;
            int arr[len];
            cout<<"Enter the elements of the Array:- \n";
            for(int j=0;j<len;j++)
            {
                cin>>arr[j];
            }

            for(int i=1;i<=len;i++)
                    {
                        int cur=arr[i];
                        int x=i-1;
                        while(arr[x]>cur && x>=0)
                        {
                            arr[x+1]=arr[x];
                            x--;
                        }
                        arr[x+1]=cur;
                    }
            int sum;
            cout<<"Enter the Sum you wish to find: ";
            cin>>sum;

            int a=0,b=len-1;
            while(a<b)
            {
                if(arr[a]+arr[b]==sum)
                    {   
                        cout<<"The required pair elements are present at the indices (in the sorted array): "<<a<<" & "<<b<<endl;
                        break;
                    }
                else if(arr[a]+arr[b]<sum)
                    a++;
                else
                    b--;
            }

        }
        break;

        default:
        {cout<<"Invalid Input/Terminating the program...";}
    }
   
    return 0;
}