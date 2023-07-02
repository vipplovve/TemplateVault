#include <iostream>
using namespace std;

int factorial(int num)
            {
                int ans=1;
                for(int i=2;i<=num;i++)
                {
                    ans*=i;
                }
                return ans;
            }


int main()
{
    while(true)
    {
        int x,c;
        int co=1; //Creating a variable to take input for generating a specific pattern
        cout<<"Tell Which Pattern you wish to generate: ";
        cin>>x;
    
        switch(x)//applying switch clause on x to define various conditions
        {
            case 1://printing a basic traingle pattern

                cout<<"Enter the no. of layers you wish to add: ";
                cin>>c;
                cout<<endl;
                for(int i=1;i<=c;i++)
                {
                    for(int j=1;j<=i;j++)
                    {
                        cout<<" *";
                    }
                    cout<<'\n';

                }
                cout<<endl;
                break;
            
            case 2://printing a rectangle

                cout<<"Enter the no. of layers you wish to add: ";
                cin>>c;
                cout<<endl;
                for(int i=1;i<=c;i++)
                {
                    for(int j=1;j<=c;j++)
                    {
                        cout<<" *";
                    }
                    cout<<'\n';

                }
                cout<<endl;
                break;

            case 3://printing a hollow rectangle

                cout<<"Enter the no. of layers you wish to add: ";
                cin>>c;
                cout<<endl;
                for(int i=1;i<=c;i++)
                {
                    for(int j=1;j<=c;j++)
                    {
                        if(i==1 || i==c || j==1 || j==c)
                        {
                            cout<<'*';
                        }
                        else{cout<<" ";}
                    }
                    cout<<'\n';

                }
                cout<<endl;
                break;
            
            case 4://reverse triangle

                cout<<"Enter the no. of layers you wish to add: ";
                cin>>c;
                cout<<endl;
                for(int i=c;i>=1;i--)
                {
                    for(int j=1;j<=i;j++)
                    {
                        cout<<" *";
                    }
                    cout<<'\n';

                }
                cout<<endl;
                break;
            
            case 5://shifted triangle

                cout<<"Enter the no. of layers you wish to add: ";
                cin>>c;
                cout<<endl;
                for(int i=1;i<=c;i++)
                {
                    for(int j=1;j<=c;j++)
                    {
                        if(j<=c-i)
                        {cout<<" ";}
                        else{cout<<'*';}
                    }
                    cout<<'\n';

                }
                cout<<endl;
                break;
            
            case 6://floyd

                cout<<"Enter the no. of layers you wish to add: ";
                cin>>c;
                cout<<endl;
                for(int i=1;i<=c;i++)
                {
                    for(int j=1;j<=i;j++)
                    {
                        cout<<" "<<co<<" ";
                        co++;
                    }
                    cout<<'\n';

                }
                cout<<endl;
                break;

                
            case 7://butterfly 

                cout<<"Enter the no. of layers you wish to add: ";
                cin>>c;
                for(int i=1;i<=c;i++)
                {
                    for(int j=1;j<=i;j++)
                    {
                        cout<<'*';
                    }
                    int sp=(2*c) -(2*i);
                    for(int p=1;p<=sp;p++)
                        {cout<<" ";}
                    for(int j=1;j<=i;j++)
                    {
                        cout<<'*';}

                    cout<<endl;
                    
                }
                for(int i=c;i>=1;i--)
                {
                    for(int j=1;j<=i;j++)
                    {
                        cout<<'*';
                    }
                    int sp=(2*c) -(2*i);
                    for(int p=1;p<=sp;p++)
                        {cout<<" ";}
                    for(int j=1;j<=i;j++)
                    {
                        cout<<'*';}

                    cout<<endl;
                    
                }
                cout<<endl;
                break;
                
            case 8://1-0 triangle

                cout<<"Enter the no. of layers you wish to add: ";
                cin>>c;
                for(int i=1;i<=c;i++)
                {
                    for(int j=1;j<=i;j++)
                    {
                        if((i+j)%2==0)
                        {
                            cout<<" 1 ";
                        }
                        else
                            cout<<" 0 ";

                    }
                    cout<<endl;
                }
                cout<<endl;
                break;

            case 9://rhombus

                cout<<"Enter the no. of layers you wish to add: ";
                cin>>c;
                for(int i=1;i<=c;i++)
                {
                    for(int j=1;j<=c-i;j++)
                    {
                        cout<<" ";

                    }
                    for(int p =1;p<=c;p++)
                        cout<<" *";
                    cout<<endl;
                }
                cout<<endl;
                break;

            case 10://number pyramid

                cout<<"Enter the no. of layers you wish to add: ";
                cin>>c;

                for(int i=1;i<=c;i++)
                {
                    for(int j=1;j<=c-i;j++)
                    {
                        cout<<"  ";

                    }
                    for(int p=1;p<=i;p++)
                    {
                        cout<<p<<"   ";
                    }
                    cout<<endl;
                }
                cout<<endl;
                break;

            case 11://star

                cout<<"Enter the no. of layers you wish to add: ";
                cin>>c;

                for(int i=1;i<=c;i++)
                {
                    for(int j=1;j<=c-i;j++)
                    {
                        cout<<"  ";

                    }
                    for(int p=1;p<=i;p++)
                    {
                        cout<<"*"<<"   ";
                    }
                    cout<<endl;
                }
                

                for(int i=c;i>=1;i--)
                {
                    for(int j=1;j<=c-i;j++)
                    {
                        cout<<"  ";

                    }
                    for(int p=1;p<=i;p++)
                    {
                        cout<<"*"<<"   ";
                    }
                    cout<<endl;
                }
                cout<<endl;
                break;

            case 12://zig-zag

                cout<<"Enter no. of elements you wish to have: ";
                cin>>c;

                for(int i=1;i<=3;i++)
                {
                    for(int j=1;j<=c;j++)
                    {
                        if((i+j)%4==0 || (i==2 && j%4==0))
                            cout<<" *";
                        else
                            cout<<"  ";
                    }
                    cout<<endl;
                }  
                cout<<endl;
                break;  

            case 13: //diamond of nothingness 

                cout<<endl;
                cout<<"Enter the no. of layers you wish to add: ";
                cin>>c;
                for(int i=c;i>=1;i--)
                {
                    for(int j=1;j<=i;j++)
                    {
                        cout<<'*';
                    }
                    int sp=(2*c) -(2*i);
                    for(int p=1;p<=sp;p++)
                        {cout<<" ";}
                    for(int j=1;j<=i;j++)
                    {
                        cout<<'*';}

                    cout<<endl;
                    
                }

                
                for(int i=1;i<=c;i++)
                {
                    for(int j=1;j<=i;j++)
                    {
                        cout<<'*';
                    }
                    int sp=(2*c) -(2*i);
                    for(int p=1;p<=sp;p++)
                        {cout<<" ";}
                    for(int j=1;j<=i;j++)
                    {
                        cout<<'*';}

                    cout<<endl;
                    
                }
                break;
                
            case 14: //Pascal`s triangle

                int ll;
                cout<<"Enter No. of Layers you wish to have: ";
                cin>>ll;
                cout<<endl;
                for(int j=0;j<ll;j++)
                {
            
                    for(int b=0;b<=j;b++)
                    {
                        int val=factorial(j)/(factorial(b)*factorial(j-b));
                        cout<<" "<<val;
                    }
                    cout<<endl;
                }
                cout<<endl;
                break;

            case 15: //Palindromic pyramid

                int i, j, rows, k, m;  
                cout<<" Enter a number to define the rows: ";  
                cin>>rows;   
                cout<<endl;  

                for ( i = 1; i <= rows; i++)  
                {  

                    for ( j = 1; j <= rows-i; j++)  
                    {     
                        cout<<" ";   
                    }  

                    for (m = i; m >1; m--)  
                    {  
                        cout<<m;   
                    } 

                    for ( k = 1; k <= i; k++)  
                    {  
                        cout<<k;
                    }  
                     
                    cout<<endl;  
                }  
                break;

            case 16: //kite

                int num;
                cout<<"Enter an odd number: ";
                cin>>num;
                if(num%2==0)
                cout<<"Invalid Input.";
                else
                {
                    for(int i=1;i<(num+1)/2;i++)
                    {
                        for(int y=(num+1)/2;y>i;y--)
                            cout<<"  ";
            
                        for(int z=1;z<=2*i-1;z++)
                        {
                        if(((z==1)||(z==i))||(z==(2*i)-1))
                        cout<<"* ";
                        else
                            cout<<"  ";
                        }
                        cout<<endl;
                    
                    }
                    for(int x=0;x<num;x++)
                    cout<<"* ";
                    cout<<endl;
                    for(int i=(num-1)/2;i>0;i--)
                    {
                        for(int y=(num+1)/2;y>i;y--)
                            cout<<"  ";
                        for(int z=1;z<=2*i-1;z++)
                        {
                        if(((z==1)||(z==i))||(z==(2*i)-1))
                        cout<<"* ";
                        else
                            cout<<"  ";
                        }
                        cout<<endl;
                    }
                }
                break;

            default:
                {
                    cout<<endl;
                    cout<<"Thanks For Using :)";
                    exit(0);
                }
        }

    }
    return 0;}