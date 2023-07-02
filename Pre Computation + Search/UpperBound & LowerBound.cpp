#include <iostream>
#include <algorithm>

using namespace std;

int lowerBound(int a[], int size, int lower)
{
	int l = 0, r = size - 1;
	int ans = -1;

	while(l<=r)
	{
		int m = l + (r-l)/2;

		if(a[m] >= lower)
		{
			ans = a[m];
			r = m - 1;
		}

		else
			l = m + 1;
	}

	return ans;
}

int upperBound(int a[], int size, int upper)
{
	int l = 0, r = size - 1;
	int ans = -1;

	while(l<=r)
	{
		int m = l + (r-l)/2;

		if(a[m] <= upper)
		{
			ans = a[m];
			l = m + 1;
		}

		else
			r = m - 1;
	}

	return ans;
}

int main()
{
	int size; 

	cin>>size;

	int arr[size];

	for(int x = 0 ; x < size ; x++)
		cin>>arr[x];

	sort(arr, arr + size);

	int x;

	cin>>x;
	
	int ans = lowerBound(arr,size,x);

	cout<<"Lower Bound of "<<x<<" is : "<<ans<<endl<<endl;

	cin>>x;
	
	ans = upperBound(arr,size,x);

	cout<<"Upper Bound of "<<x<<" is : "<<ans<<endl<<endl;
	
	return 0;
}