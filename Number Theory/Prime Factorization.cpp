#include <bits/stdc++.h>
using namespace std;

map<long long, long long> PrimeFactorization(long long num)
{
    map<long long, long long> factorization;

    while(num % 2 == 0)
    {
        factorization[2]++;
        num /= 2;
    }

    for(long long x = 3 ; x*x <= num ; x++)
    {
        while(num % x == 0)
        {
            factorization[x]++;
            num /= x;
        }
    }

    if(num > 1)
        factorization[num]++;

    return factorization;
}

int main()
{
    long long number;
    
    cin >> number;

    map<long long, long long> factorization = PrimeFactorization(number);

    cout << "The Prime Factorization of " << number << " is :\n\n";
    
    for(auto i : factorization)
        cout << i.first << " : " << i.second << endl;
    cout << endl;

    return 0;
}