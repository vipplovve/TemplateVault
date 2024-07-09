#include <iostream>
#include <vector>
using namespace std;

int PoliceThief(string s, int vic)
{
	vector<int> p,t;

	for(int x = 0 ; x < s.size() ; x++)
	{
		if(s[x]=='p')
			p.push_back(x);
		else
			t.push_back(x);
	}

	int pS = 0, tS = 0;

	int ans = 0;

	while(pS < p.size() && tS < t.size())
	{
		if(abs(p[pS] - t[tS]) <= vic)
		{
			ans++;
			pS++;
			tS++;
		}

		else
			t[tS]>p[pS]?pS++:tS++;
	}

	return ans;
}

int main()
{
	string seq;

	cin>>seq;

	int vic;

	cin>>vic;

	int ans = PoliceThief(seq,vic);

	cout<<"Total Thieves Caught are : "<<ans<<endl;

	return 0;
}