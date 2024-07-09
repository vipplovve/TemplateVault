#include <bits/stdc++.h>
using namespace std;

void multiply(long long int *aa, long long int *bb, long long int m)
{
	long long int ans[m][m];
	
    for(long long int x = 0 ; x < m ; x++)
    	for(long long int y = 0 ; y < m ; y++)
    		ans[x][y]=0;

    for(long long int a=0;a<m;a++)
                {
                    for(long long int b=0;b<m;b++)
                    {
                        for(long long int c=0;c<m;c++)
                        {
                            ans[a][b]+=*(aa+(m*a)+c) * *(bb+(m*c)+b);
                        }
                    }
                }
    
    for(long long int x = 0 ; x < m ; x++)
            for(long long int y = 0 ; y < m ; y++)
                *(aa+(m*x)+y) = ans[x][y];
     

}

void exponentiate(long long int *a, long long int *b, long long int m, long long int index)
{
	while(index)
	{
		if(index%2)
		{
			multiply(b,a,m);
			index--;
		}
		else
		{
			multiply(a,a,m);
			index=index/2;
		}
	}

     for(long long int x = 0 ; x < m ; x++)
            for(long long int y = 0 ; y < m ; y++)
                *(a+(m*x)+y) =*(b+(m*x)+y);
}

int main()
{	
	long long int index;
	cin>>index;

	long long int *a = new long long int[2*2];

	*(a)=0;
	*(a+1)=1;
	*(a+2)=1;
	*(a+3)=1;

	long long int *i = new long long int[2*2];

	for(long long int x= 0 ; x< 2; x++)
		for(long long int y= 0; y<2; y++)
		{
			if(x==y)
				*(i+(2*x)+y)=1;
			else
				*(i+(2*x)+y)=0;
		}

	exponentiate(a,i,2,index-1);

	cout<<"Answer is : "<<*a + *(a + 2)<<endl;
	
	return 0;
}