#include <bits/stdc++.h>
using namespace std;

//binary to decimal

int bintodec(int bin)
{
    int ans=0;
    int multiplier=1;
    while(bin>0)
    {
        int r =bin%10;
        ans= ans + (r*multiplier);
        bin/=10;
        multiplier*=2;
    }
    return ans;
}

//decimal to binary

int dectobin( int dec)
{
    int x=1;
    int ans=0;
    while(x<=dec)
    {
        x*=2;
    }
    x/=2;

    while(x>0)
    {
        int l=dec/x;
        dec-=l*x;
        x/=2;
        ans=ans*10+l;
    }
    return ans;
}

//decimal to octal

int dectooct( int dec)
{
    int x=1;
    int ans=0;
    while(x<=dec)
    {
        x*=8;
    }
    x/=8;

    while(x>0)
    {
        int l=dec/x;
        dec-=l*x;
        x/=8;
        ans=ans*10+l;
    }
    return ans;
}

//decimal to hexadecimal

string dectohex(int dec)
{
    int x=1;
    string ans="";
    while(x<=dec)
        x*=16;
    
    x/=16;
    
    while(x>0)
    {
        int l=dec/x;
        dec-=l*x;
        x/=16;

        if(l<=9)
        {
            ans+= to_string(l);
        }

        else
        {
            char c='A' + (l-10);
            ans.push_back(c);

        }
    }
    return ans;
}



// octal to decimal

int octtodec(int oct)
{
    int ans=0;
    int multiplier=1;
    while(oct>0)
    {
        int r =oct%10;
        ans= ans + (r*multiplier);
        oct/=10;
        multiplier*=8;
    }
    return ans;
}




// hexadecimal to decimal

int hextodec(string hex)
{
    int ans=0;
    int multiplier=1;
    int s=hex.size();
    for(int i=s-1;i>=0;i--)
    {
        if(hex[i]>='0' && hex[i]<='9')
        {
            ans+= multiplier*(hex[i]-'0');

        }

        else if(hex[i]>='A' && hex[i]<='F')
        {
            ans+= multiplier*(hex[i]-'A' + 10);
        }

        multiplier*=16;
    }
    return ans;
}

//hexadecimal to octal

int hextooct(string hex)
{
    int y=hextodec(hex);
    int x=dectooct(y);
    return x;
}

//hexadecimal to binary

int hextobin(string hex)
{
    int y=hextodec(hex);
    int x=dectobin(y);
    return x;    
}

//binary to octal

int bintooct(int bin)
{
    int y=bintodec(bin);
    int x=dectooct(y);
    return x;
}

//binary to hexadecimal

string bintohex(int bin)
{
    int y=bintodec(bin);
    string x=dectohex(y);
    return x;
}

//octal to binary

int octtobin(int oct)
{
    int y=octtodec(oct);
    int x=dectobin(y);
    return x;

}

//octal to hexadecimal

string octtohex( int oct)
{
    int y=octtodec(oct);
    string x=dectohex(y);
    return x;
}


int main()
{   
    int choice;
    cout<<endl<<"Greeting!\nWelcome To my Program!\n";
    cout<<"1.Binary to Decimal\n2.Binary to Octal\n3.Binary to Hexadecimal\n";
    cout<<"4.Decimal to Binary\n5.Decimal to Octal\n6.Decimal to Hexadecimal\n";
    cout<<"7.Octal to Binary\n8.Octal to Decimal\n9.Octal to Hexadecimal\n";
    cout<<"10.Hexadecimal to Binary\n11.Hexadecimal to Decimal\n12.Hexadecimal to Octal\n";
    while(1)
    {cout<<"Which Operation Do you want to Perform? ";
    cin>>choice;
    
    switch(choice)

    {

    //binary block

    case 1:

    {
    int num;
    cout<<"Enter a Binary Number: ";
    cin>>num;
    cout<<"It`s Decimal Equivalent is: "<<bintodec(num)<<endl;
    break;
    }

    case 2:

    {
    int num;
    cout<<"Enter a Binary Number: ";
    cin>>num;
    cout<<"It`s Octal Equivalent is: "<<bintooct(num)<<endl;
    break;
    }

    case 3:

    {
    int num;
    cout<<"Enter a Binary Number: ";
    cin>>num;
    cout<<"It`s Hexadecimal Equivalent is: "<<bintohex(num)<<endl;
    break;
    }

    //decimal block

    case 4:

    {
    int num;
    cout<<"Enter a Decimal Number: ";
    cin>>num;
    cout<<"It`s Binary Equivalent is: "<<dectobin(num)<<endl;
    break;
    }
    
    case 5:

    {
    int num;
    cout<<"Enter a Decimal Number: ";
    cin>>num;
    cout<<"It`s Octal Equivalent is: "<<dectooct(num)<<endl;
    break;
    }

    case 6:

    {
    int num;
    cout<<"Enter a Decimal Number: ";
    cin>>num;
    cout<<"It`s Hexadecimal Equivalent is: "<<dectohex(num)<<endl;
    break;
    }

    //octal block

    case 7:

    {
    int num;
    cout<<"Enter an Octal Number: ";
    cin>>num;
    cout<<"It`s Binary Equivalent is: "<<octtobin(num)<<endl;
    break;
    }

    case 8:

    {
    int num;
    cout<<"Enter an Octal Number: ";
    cin>>num;
    cout<<"It`s Decimal Equivalent is: "<<octtodec(num)<<endl;
    break;
    }

    case 9:

    {
    int num;
    cout<<"Enter an Octal Number: ";
    cin>>num;
    cout<<"It`s Hexadecimal Equivalent is: "<<octtohex(num)<<endl;
    break;
    }

    //hexadecimal block

    case 10:

    {
    string num;
    cout<<"Enter a Hexadecimal Number: ";
    cin>>num;
    cout<<"It`s Binary Equivalent is: "<<hextobin(num)<<endl;
    break;
    }

    case 11:

    {
    string num;
    cout<<"Enter a Hexadecimal Number: ";
    cin>>num;
    cout<<"It`s Decimal Equivalent is: "<<hextodec(num)<<endl;
    break;
    }

    case 12:

    {
    string num;
    cout<<"Enter a Hexadecimal Number: ";
    cin>>num;
    cout<<"It`s Octal Equivalent is: "<<hextooct(num)<<endl;
    break;
    }

    case 0:
    {
        cout<<"\nThanks for using the program!\n";
        exit(1);
    }
    }}
    
    return 0;
}