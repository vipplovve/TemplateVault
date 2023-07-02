#include <iostream>

using namespace std;

int BracketBalancing(string s)
{
    int ans = 0,l = 0, r = 0, imb = 0;

    for(auto i : s)
    {
        if(i=='[')
        {
            l++;

            if(imb>0)
            {
                ans+=imb;
                imb--;
            }
        }

        else
        {
            r++;
            imb = r - l;
        }
    }

    return ans;
}

int main()
{
    string s;
    cin>>s;

    int ans = BracketBalancing(s);

    cout<<"Minimum Swaps Required are : "<<ans<<endl;

    return 0;
}