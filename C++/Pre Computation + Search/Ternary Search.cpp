#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int ternarySearch2(int d[], int v, int l,int r, int &steps)
{
	steps++;

	if(l>r)
		return -2;

	int m = l + (r-l)/2;

	if(d[m]==v)
		return m;

	else if(d[m]>v)
		return ternarySearch2(d,v,l,m - 1,steps);

	else
		return ternarySearch2(d,v,m + 1,r,steps);
}

int ternarySearch(int d[], int v, int s, int &steps)
{
	int l = 0;
	int r = s - 1;

	while(l<=r)
	{
		steps++;

		int middle1 = l + (r-l)/3;
		int middle2 = r - (r-l)/3;

		if(d[middle2]==v)
			return middle2;

		else if(d[middle1]==v)
			return middle1;

		else
		{
			if(v > d[middle2])
				l = middle2 + 1;

			else if(v < d[middle1])
				r = middle1 - 1;

			else
			{
				l = middle1 + 1;
				r = middle2 - 1;
			}
		}
	}

	return -2;
}

int main()
{
	int size;
	cin>>size;

	int data[size];

	for(int x = 0 ; x < size ; x++)
		cin>>data[x];

	sort(data,data+size);
	
	int value,steps = 0;

	cin>>value;

	int ans = ternarySearch2(data,value,0,size-1,steps);

	cout<<"Sorted Sequence is :- \n\n";

	for(auto &i : data)
		cout<<i<<' ';

	cout<<"\n\nValue found at : "<<ans + 1<<"\n\n";
	cout<<"Steps taken : "<<steps<<" Log3N = "<<ceil(log(size)/log(3))<<endl;

	return 0;
}