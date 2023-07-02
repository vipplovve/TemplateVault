#include <iostream>
using namespace std;

int factorial(int num)
{
    int ans=1;
    for(int i=2;i<=num;i++)
    {
        ans*=i;
    }
    return ans;
}

int main()
{   
    int ll;
    cout<<"Enter No. of Layers you wish to have: ";
    cin>>ll;
    cout<<endl;
    for(int j=0;j<ll;j++)
    {
        for(int b=0;b<=j;b++)
        {
            int val=factorial(j)/(factorial(b)*factorial(j-b));
            cout<<" "<<val;
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;

}