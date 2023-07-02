#include <iostream>
using namespace std;

int factorial(int num)
{
    float fact=1;
    for(int i=1;i<=num;i++)
    {
        fact=fact*i;

    }
    return fact;
}

int main()
{
    int choice,num,c;
    cout<<"1. nCr"<<endl<<"2. nPr"<<endl;
    cout<<"What do you want to Do? ";
    cin>>choice;

    switch(choice)
    {
        case 1:
        cout<<"Enter Two Numbers(n and c): ";
        cin>>num>>c;
        float ans=(factorial(num)/(factorial(c)*factorial(num-c)));
        cout<<"The value of "<<num<<"C"<<c<<": "<<ans;


    }

    return 0;
}