#include <iostream>

using namespace std;

int* prefixSum(int d[],int size)
{
	int *prefix = new int[size];
	
	prefix[0] = d[0];

	for(int x = 1 ; x < size ; x++)
	{
		prefix[x] = d[x] + prefix[x-1];
	}

	return prefix;
}

int* suffixSum(int d[],int size)
{
	int *suffix = new int[size];
	
	suffix[size-1] = d[size-1];

	for(int x = size-2 ; x >-1 ; x--)
	{
		suffix[x] = d[x] + suffix[x+1];
	}

	return suffix;
}

int main()
{
	int size; 

	cin>>size;

	int a[size];

	for(int x = 0 ; x < size ; x++)
		cin>>a[x];

	int *suffix = suffixSum(a,size);

	int *prefix = prefixSum(a,size);

	cout<<"Suffix Sum is : -\n\n";
	for(int x = 0 ; x < size ; x++)
		cout<<*(suffix+x)<<' ';
	cout<<"\n\n";

	cout<<"Prefix Sum is : -\n\n";
	for(int x = 0 ; x < size ; x++)
		cout<<*(prefix+x)<<' ';
	cout<<"\n\n";

	return 0;

}