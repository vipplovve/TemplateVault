#include <iostream>
using namespace std;
int main()
{   while(1)
    {
        int len,choice;
        cout<<"Enter Length of the Array you wish to create: ";
        cin>>len;
        int arr[len];
        for(int i=0;i<=len-1;i++)
        {
            cin>>arr[i];
        }
        cout<<"The Array is: ";
        for(int x=0;x<=len-1;x++)
        cout<<arr[x]<<" ";
        cout<<endl;

        cout<<"Which Sorting technique would you like to use? \n";
        cout<<"\n1. Selection Sort.\n2. Bubble Sort.\n3. Insertion Sort.\n";
            cin>>choice;
            switch(choice)
            {
                case 1: //defining the algo for selection sort.
                {
                    for(int x=0;x<=len-1;x++)
                    {
                        for(int y=x+1;y<=len;y++)
                        {
                            if(arr[y]<arr[x])
                            {
                                int temp=arr[y];
                                arr[y]=arr[x];
                                arr[x]=temp;
                            }
                        }
                    }
                    cout<<"The Sorted Array is: \n";
                    for(int x=0;x<=len-1;x++)
                    cout<<arr[x]<<" ";
                    cout<<endl;

                }
                break;

                case 2: //defining the algo for bubble sort.
                {
                    int c=1;
                    while(c<len)
                    {
                        for(int i=0;i<=len - c;i++)
                        {
                            if(arr[i]>arr[i+1])
                            {
                                int temp=arr[i];
                                arr[i]=arr[i+1];
                                arr[i+1]=temp;
                                
                            }
                        }
                        c+=1;
                    }
                    cout<<"The Sorted Array is: \n";
                    for(int x=0;x<=len-1;x++)
                    cout<<arr[x]<<" ";
                    cout<<endl;
                }
                break;

                case 3: //defining the algo for insertion sort.
                {
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
                    cout<<"The Sorted Array is: \n";
                    for(int x=0;x<=len-1;x++)
                    cout<<arr[x]<<" ";
                    cout<<endl;
                }
                break;

                default:
                cout<<"Invalid input/Terminating the program...";
                exit(1);
            }
    }
    return 0;
}