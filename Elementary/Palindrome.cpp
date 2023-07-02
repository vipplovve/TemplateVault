#include <bits/stdc++.h>
using namespace std;

int main()
{
    int len;
    cout<<"Enter length of the word to be inputted: ";
    cin>>len;
    char word[len+1];
    cin>>word;
    bool lol=1;
    for(int x=0;x<len;x++)
    {
        if(word[x] != word[len-1-x])
        {
            lol=0;
            break;
        }
    }

    if(lol == 1)
    cout<<"Entered Word is a Palindrome."<<endl;
    else
    cout<<"Entered Word is not a Palindrome."<<endl;

    return 0;
}