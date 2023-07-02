#include <iostream>
using namespace std;

int main()
{
    //creating a user inputted 2D Array.
    int n,m;
    cout<<"Enter Dimensions of the Matrix you wish to create: ";
    cin>>n>>m;
    int twoDArray[n][m];
    for(int x=0;x<n;x++)
    {
        for(int y=0;y<m;y++)
        {
            cin>>twoDArray[x][y];
        }
    }
    int ans;
    cout<<"Enter the element to be searched: ";
    cin>>ans;

    //we can directly put 2 loops and search accordingly for an element at every position.
    
    //or, we can create a better approach(given that the matrix has sorted rows and columns).
    int row=1,col=m-1;
    int j=0;
    while(j<row && j<col)
    {   int val=twoDArray[row][col];
        if(val==ans)
        {
            cout<<ans<<" has been found!\n";
            cout<<"The coordinates being: "<<row+1<<" & "<<col+1;
            break;
        }
        else if(val<ans)
        {
            row++;
            j++;
        }
        else if(val>ans)
        {
            col--;
            j++;
        }
        if(j>row || j>col)
        {
            cout<<"Sorry! Element not found.";
            break;
        }
    }
    return 0;
}