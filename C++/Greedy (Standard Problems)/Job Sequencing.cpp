#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class job
{
public:

	string name;
	int profit;
	int deadline;

};

bool maxprofitsort(job a, job b)
{
	return a.profit > b.profit;
}

vector<job> JobSequencing(job a[], int s)
{
    vector<job> A;

    bool checker[s] = {0};
    
    for(int y = 0 ; y < s ; y++)
    {	
        for(int x = min(s,a[y].deadline) ; x >= 1 ; x--)
            if(!checker[x])
            {
                A.push_back(a[y]);
                checker[x] = true;
                break;
            }
    }

    return A;
}

int main()
{
    int size;
    cin>>size;

    job arr[size];

    string s;
    int p,d;

    for(int x = 0 ; x < size ; x++)
    {
        cin>>s>>d>>p;
        arr[x].name = s;
        arr[x].profit = p;
        arr[x].deadline = d;
    }
       
    sort(arr, arr + size, maxprofitsort);

   	vector<job> solution = JobSequencing(arr,size);
    
    cout<<"The Jobs Completed are :- (in this sequence) \n\n";

    for(auto i : solution)
    	cout<<i.name<<' ';

    return 0;	
}