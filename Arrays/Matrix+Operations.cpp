#include <bits/stdc++.h>
using namespace std;

int main()
{
    int choice;
    cout<<"Which Operation would you like to use? \n";
    cout<<"1. Matrix Addition"<<endl<<"2. Matrix Subtraction"<<endl<<"3. Scalar Multiplication"<<endl;
    cout<<"4. Matrix Multiplication"<<endl<<"5. Transpose Calculation(for Square Matrices)"<<endl;
    
    while(true)
    {
        cout<<"Which Operation would you like to use? \n";
        cin>>choice;

        switch(choice)
        {
            case 1: //matrix addition
            {int r1,r2,c2,c1;
            cout<<"Enter order of Matrix #1: ";
            cin>>r1>>c1;
            int arr1[r1][c1];
            for(int x=0;x<=r1-1;x++)
            {
                for(int y=0;y<=c1-1;y++)
                cin>>arr1[x][y];

            }
            cout<<endl;
            cout<<"Enter order of Matrix #2: ";
            cin>>r2>>c2;
            int arr2[r2][c2];
            for(int x=0;x<=r2-1;x++)
            {
                for(int y=0;y<=c2-1;y++)
                cin>>arr2[x][y];

            }
            int ans[r1][c1];
            for(int x=0;x<=r2-1;x++)
            {
                for(int y=0;y<=c2-1;y++)
                ans[x][y]=arr1[x][y]+arr2[x][y];
            }
            cout<<endl;
            cout<<"The solution Matrix is:- "<<endl;
            for(int x=0;x<=r2-1;x++)
            {
                for(int y=0;y<=c2-1;y++)
                cout<<ans[x][y]<<" ";

                cout<<endl;
            }
            cout<<endl;
            }
            break;
            case 2: // matrix subtraction
            {
            int r1,r2,c2,c1;
            cout<<"Enter order of Matrix #1: ";
            cin>>r1>>c1;
            int arr1[r1][c1];
            for(int x=0;x<=r1-1;x++)
            {
                for(int y=0;y<=c1-1;y++)
                cin>>arr1[x][y];

            }
            cout<<endl;
            cout<<"Enter order of Matrix #2: ";
            cin>>r2>>c2;
            int arr2[r2][c2];
            for(int x=0;x<=r2-1;x++)
            {
                for(int y=0;y<=c2-1;y++)
                cin>>arr2[x][y];

            }
            cout<<endl;
            int ans[r1][c1];
            for(int x=0;x<=r2-1;x++)
            {
                for(int y=0;y<=c2-1;y++)
                ans[x][y]=arr1[x][y]-arr2[x][y];
            }
            cout<<endl;
            cout<<"The solution Matrix is:- "<<endl;
            for(int x=0;x<=r2-1;x++)
            {
                for(int y=0;y<=c2-1;y++)
                cout<<ans[x][y]<<" ";

                cout<<endl;
            }
            cout<<endl;
            }
            break;

            case 3: //scalar multiplication
            {
            int r1,c1,k;
            cout<<"Enter order of Matrix: ";
            cin>>r1>>c1;
            int arr1[r1][c1];

            for(int x=0;x<=r1-1;x++)
            {
                for(int y=0;y<=c1-1;y++)
                cin>>arr1[x][y];

            }
            
            cout<<endl;
            cout<<"Enter value of scalar: ";
            cin>>k;
            cout<<endl;
            int ans[r1][c1];

            for(int x=0;x<=r1-1;x++)
            {
                for(int y=0;y<=c1-1;y++)
                ans[x][y]=arr1[x][y]*k;
            }
            cout<<endl;
            cout<<"The solution Matrix is:- "<<endl;
            for(int x=0;x<=r1-1;x++)
            {
                for(int y=0;y<=c1-1;y++)
                cout<<ans[x][y]<<" ";

                cout<<endl;
            }
            cout<<endl;
            }
            break;

            case 4:
            {
                int r1,z,c2;
                cout<<"Enter order of Matrix #1: ";
                cin>>r1>>z;
                int arr1[r1][z];
                for(int x=0;x<=r1-1;x++)
                {
                    for(int y=0;y<=z-1;y++)
                    cin>>arr1[x][y];

                }
                cout<<endl;
                cout<<"Enter order of Matrix #2: ";
                cin>>z>>c2;
                int arr2[z][c2];
                for(int x=0;x<=z-1;x++)
                {
                    for(int y=0;y<=c2-1;y++)
                    cin>>arr2[x][y];

                }
                cout<<endl;
                int ans[r1][c2];
                for(int x=0;x<=r1-1;x++)
                {
                    for(int y=0;y<=c2-1;y++)
                    ans[x][y]=0;

                }
                for(int a=0;a<r1;a++)
                {
                    for(int b=0;b<c2;b++)
                    {
                        for(int c=0;c<z;c++)
                        {
                            ans[a][b]+=arr1[a][c]*arr2[c][b];
                        }
                    }
                }
                cout<<"The Solution Matrix is:- "<<endl;
                for(int x=0;x<=r1-1;x++)
                {
                    for(int y=0;y<=c2-1;y++)
                    cout<<ans[x][y]<<" ";

                    cout<<endl;
                }
                cout<<endl;

                }
                break;

            case 5:
            {
                int r,c;
                cout<<"Enter order of Matrix: ";
                cin>>r>>c;
                int arr[r][c];
                for(int x=0;x<=r-1;x++)
                {
                    for(int y=0;y<=c-1;y++)
                    cin>>arr[x][y];

                }
                cout<<endl;
                
                /*int ans[c][r];
                for(int x=0;x<=c-1;x++)
                {
                    for(int y=0;y<=r-1;y++)
                    ans[c][r]=arr[r][c];
                }

                cout<<"The Transposed Matrix is:- "<<endl;
                for(int x=0;x<=c-1;x++)
                {
                    for(int y=0;y<=r-1;y++)
                    cout<<ans[x][y]<<" ";

                    cout<<endl;
                }
                cout<<endl;*/

                for(int x=0;x<r;x++) //swapping non diagonal elements.
                {
                    for(int y=x;y<c;y++)
                    {
                        int var=arr[x][y];
                        arr[x][y]=arr[y][x];
                        arr[y][x]=var;

                    }
                }

                cout<<"The Transposed Matrix is:- "<<endl;
                for(int x=0;x<=r-1;x++)
                {
                    for(int y=0;y<=c-1;y++)
                    cout<<arr[x][y]<<" ";

                    cout<<endl;
                }
                cout<<endl;

                }
                break;
            
            default:
            {
                cout<<"Invalid Input/Terminating the program...";
                exit(1);
            }
        }
    }
    return 0;
}