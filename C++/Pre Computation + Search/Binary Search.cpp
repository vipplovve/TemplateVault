#include <iostream>
#include <algorithm>

using namespace std;

int binS(int a[], int size, int value)
{
	int l = 0, r = size - 1;

	while(l<=r)
	{
		int m = l + (r-l)/2;

		if(a[m]==value)
			return m;

		if(a[m]<value)
			l = m + 1;

		else
			r = m - 1;
	}

	return -2;
}

int binS2(int a[], int l , int r, int v)
{
	if(l>r)
		return -1;

	int m = l + (r-l/2);

	if(a[m]==v)
		return m;

	else if(a[m] < v)
		return binS2(a,m + 1, r , v);

	else
		return binS2(a,l,m-1,v);
}

int main()
{
	int size;

	cin>>size;

	int a[size];

	for(int x = 0 ; x < size ; x++)
		cin>>a[x];

	for(int x = 0 ; x < size ; x++)
		cout<<a[x]<<' ';

	cout<<endl<<endl;

	sort(a, a + size);

	int v1,v2;

	cin>>v1>>v2;

	int ans = binS(a,size,v1);

	for(int x = 0 ; x < size ; x++)
		cout<<a[x]<<' ';

	cout<<"\n\n"<<v1<<" at position : "<<ans+1<<endl;

	ans = binS2(a,0,size - 1,v2);

	cout<<"\n"<<v2<<" at position : "<<ans<<endl;

	return 0;
}