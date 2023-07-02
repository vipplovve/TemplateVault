#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    int m,n; //input the order of the matrix.
    cout<<"enter order of the matrix: ";
    cin>>m>>n;

    int arr[m][n];
    cout<<"Enter the matrix: -"<<endl;
    for(int x=0;x<m;x++) //taking input in the matrix
        for(int y=0;y<n;y++)
            cin>>arr[x][y];

    int i, k = 0, l = 0;
    
    cout<<"Printing the Spiral Form: -\n";
    while (k < m && l < n) 
    {

        for (i = l; i < n; ++i) {
            cout << arr[k][i] << " ";
        }
        k++;

        for (i = k; i < m; ++i) {
            cout << arr[i][n - 1] << " ";
        }
        n--;
  
        if (k < m) {
            for (i = n - 1; i >= l; --i) {
                cout << arr[m - 1][i] << " ";
            }
            m--;
        }
  
        if (l < n) {
            for (i = m - 1; i >= k; --i) {
                cout << arr[i][l] << " ";
            }
            l++;
        }
    }

    return 0;
}