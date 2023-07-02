#include <bits/stdc++.h>
using namespace std;

void menu(void)
{
    cout<<"\nWhich operation would you like to use?\n\n";
    cout<<"1.Check if a number is a power of 2.\n2.Count no. of 1s in a number`s binary representation.\n3.Generate all possible subsets of a set.\n\n";
}

void powof2(int num)
{
    if((num!=0)&&!(num&(num-1)))
    cout<<num<<" is a power of 2.\n";
    else
    cout<<num<<" is not a power of 2.\n";
}

int noof1s(int num)
{
    int c=0;
    while(num!=0)
    {
        num=num&(num-1);
        c+=1;
    }
    return c;
}

void subsets(int arr[],int len)
{
    for(int x=0;x<(1<<len);x++)
    {
        for(int y=0;y<len;y++)
        {
            if( x & (1<<y))
            cout<<arr[y]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    menu();
    int choice;
    cout<<"Enter your choice: ";
    cin>>choice;
    switch(choice)
    {
        case  1:
        {
            int num;
            cout<<"\nEnter the number: ";
            cin>>num;
            powof2(num);
            break;

        }

        case 2:
        {
            int num;
            cout<<"\nEnter the number: ";
            cin>>num;
            cout<<"\nNo. of 1s in "<<num<<" are: "<<noof1s(num);
            cout<<endl;
            break;
        }

        case 3:
        {
            int len;
            cout<<"Enter length of set: ";
            cin>>len;
            int num[len];
            cout<<"Enter the set: ";
            for(int x=0;x<len;x++)
            cin>>num[x];
            cout<<"\nPossible Subsets are: \n";
            subsets(num,len);

        }
    }
    return 0;
}
