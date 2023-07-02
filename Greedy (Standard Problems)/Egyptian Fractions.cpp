#include <iostream>
#include <vector>

using namespace std;

class frac
{
public:

	int num;
	int den;
};

void EgyptianFraction(int n, int d, vector<frac> &ans)
{
	frac f;

	if (d == 0 || n == 0)
        return;
    if (d % n == 0) {
        f.num = 1;
        f.den = d/n;
        ans.push_back(f);
        return;
    }
    if (n % d == 0) {
       	f.den = 1;
        f.num = n/d;
        ans.push_back(f);
        return;
    }
    if (n > d) {
        f.num = n/d;
        f.den = 1;
        ans.push_back(f);
        EgyptianFraction(n % d, d,ans);
        return;
    }
    int x = d / n + 1;
    f.num = 1;
    f.den = x;
    ans.push_back(f);
    EgyptianFraction(n * x - d, d * x,ans);
}
int main()
{
	int n,d;

	cin>>n>>d;

	vector<frac> ans;

	EgyptianFraction(n,d,ans);

	cout<<"The Egyptian Fractions are :- \n\n";

	for(int x = 0 ; x < ans.size() ; x++)
	{
		if(x!=ans.size() - 1)
		{
			if(ans[x].num==1)
				cout<<ans[x].num<<'/'<<ans[x].den<<" + ";
		
			else
				cout<<ans[x].num<<" + ";
		}
		
		else
		{
			if(ans[x].num==1)
				cout<<ans[x].num<<'/'<<ans[x].den;
		
			else
				cout<<ans[x].num;
		}

	}

	return 0;
}