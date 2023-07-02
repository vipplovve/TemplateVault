#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int c,num,p=0;
    cout<<"1-Prime"<<endl<<"2-Armstrong"<<endl<<"3-Reverser"<<endl<<"All Other-Quit"<<endl;   
    while(1)
    {   
        cout<<"What do You wish to Do? "<<endl;   
        cin>>c;
        switch(c)
        {case 1:

        {
            cout<<"Enter A Number: ";
            cin>>num;
            for(int y=2;y<=sqrt(num);y++)
            {
                if(num%y==0)
                {
                    cout<<num<<" Is Not a Prime Number."<<endl;
                    p=1;
                    break;
                }
            
            }
            if(p==0)
            cout<<num<<" Is a Prime Number."<<endl;
        }
        break;

        case 2:
        {
            cout<<"Enter a Number: ";
            cin>>num;
            int sum=0;
            int buff=num;
            while(num>0)
            {
                int lastdig=num%10;
                sum=sum + (lastdig*lastdig*lastdig);
                num=num/10;

            }
            if(sum==buff)
            {cout<<buff<<" Is an Armstrong Number."<<endl;}
            else
            {cout<<buff<<" Is Not an Armstrong Number."<<endl;}
        }
        break;

        case 3:
        {
            cout<<"Enter a Number: ";
            cin>>num;
            int sum=0;
            while(num>0)
            {
                int r=num%10;
                sum=sum*10+ r;
                num=num/10;

            }
            
            cout<<"The reversed number is: "<<sum<<endl;
        }
        break;

        default:
        {
            cout<<"Thanks For Using!"<<endl;
            exit(1);
        }
        }
    }
        
    return 0;
}