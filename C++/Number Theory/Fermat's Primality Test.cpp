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

bool fermat(lli number)
{
	if(number < 4)
		return number == 2 || number == 3;

	else
	{
		int x = 3;

		while(x--)
		{
			lli c = 2 + rand()%(number - 3);

			lli ans = powermod(c,number-1,number);

			if(ans!=1)
				return false;
		}

		return true;
	}
}
int main()
{
	int x;
	cin>>x;

	if(fermat(x))
		cout<<"It's a Prime as per Fermat's Primality Test.\n";
	else
		cout<<"It's not a Prime as per Fermat's Primality Test.\n";
	
	return 0;
}