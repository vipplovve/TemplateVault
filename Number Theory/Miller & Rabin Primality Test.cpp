#include <iostream>
using namespace std;

#define lli long long int

lli powermod(lli a, lli n, lli p)
{
	lli result = 1;

	while(n)
	{
		if(n&1)
		{
			n--;
			result = (result*a)%p;
		}

		else
		{
			n = n>>1;
			a = (a*a)%p;
		}
	}

	return result;
}

bool check(lli num, lli a , lli d , lli s)
{
    lli v = powermod(a,d,num);

    if(v==1 || v== num-1)
        return false;
    
    else
    {
        for(int x = 1 ; x < s ; x++)
        {
            v = (v%num)*(v%num)%num;
            if(v==num-1)
                return false;
        }
    }

    return true;
}

bool miller(lli num)
{
    if(num==1)
        return false;
    else
    {
        lli s = 0, d = num - 1;

        while(d%2==0)
        {
            d=d/2;
            s++;
        }

        for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
           if(num==a)
                return true;
           
           if (check(num, a, d, s))
               return false;
    }
    }

    return true;
}

int main()
{
    lli x;
    cin>>x;

    if(miller(x))
        cout<<"It's a Prime as per Miller-Rabin Primality Test.\n";
    else
        cout<<"It's not a Prime as per Miller-Rabin Primality Test.\n";   

    return  0; 
}