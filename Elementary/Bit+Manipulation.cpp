#include <bits/stdc++.h>
using namespace std;

int get_bit(int num,int pos)
{
    int ans;
    int num2=1<<pos;
    if((num2&num)!=0)
    ans=1;
    else
    ans=0;
    cout<<"The Bit Present at the spcified position is: "<<ans;
}

int set_bit(int num, int pos)
{
    int ans;
    int num2=1<<pos;
    ans=num2|num;
    cout<<"The Updated Number is: "<<ans;
}

int clear_bit(int num,int pos)
{
    int ans;
    int num2=~(1<<pos);
    ans=(num2&num);
    cout<<"The Updated Number is: "<<ans; 
}

int update_bit(int num, int pos,bool newval)
{
    int ans;
    int num2=~(1<<pos);
    ans=(num2&num);
    int ans2;
    int num3=(newval<<pos);
    ans2=(num3|ans);
    cout<<"The Updated Number is: "<<ans2;
}

int main()
{
    int x;
    cout<<"Welcome!\n";
    cout<<"0.Exit\n1.Get Bit\n2.Set Bit\n3.Clear Bit\n4.Update Bit\n";
    while(true)
    {
        cout<<"Enter your choice: ";
        cin>>x;

        switch(x)
        {
            int num,pos;
            bool newval;
            case 1:
            cin>>num>>pos;
            get_bit(num,pos-1);
            cout<<endl;
            break;
            case 2:
            cin>>num>>pos;
            set_bit(num,pos-1);
            cout<<endl;
            break;
            case 3:
            cin>>num>>pos;
            clear_bit(num,pos-1);
            cout<<endl;
            break;
            case 4:
            cin>>num>>pos>>newval;
            update_bit(num,pos-1,newval);
            cout<<endl;
            break;
            case 0:
            cout<<"Terminating the Program...";
            cout<<endl;
            exit(0);
            default:
            cout<<"Invalid Input.\nTry Again.";
            cout<<endl;
        }
    }
    return 0;
}