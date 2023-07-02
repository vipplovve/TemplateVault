#include <bits/stdc++.h>
using namespace std;

class Tnode
{

    float value;
    Tnode *leftson;
    Tnode *rightson;

    public:

    Tnode(int val) //constructor to initiate tree nodes.
    {
        value = val;
        leftson = NULL;
        rightson = NULL;
    }

    friend float longestBloodlineSum( Tnode * Root,float sum,float &a,int &maxlen, int length);
    friend Tnode* createTree (Tnode * &Root);
};

Tnode* createTree(Tnode * &Root)
{
    // taking input.

    float val;
    cout<<"Enter Data: ";
    cin>>val;

    if(val == -1)   //base case to stop.
    return NULL;

    else //creating left and right subtrees.
    {
        Root = new Tnode(val);
        cout<<"\nTo the Left of "<<val<<" : - ";
        Root->leftson = createTree(Root->leftson);
        cout<<"\nTo the Right of "<<val<<" : - ";
        Root->rightson = createTree(Root->rightson);   
    }

    return Root;

}

float longestBloodlineSum(Tnode *Root,float sum, float &ans,int &maxlen, int length)
{
    if(Root == NULL) //base case when we have reached a leaf.
    {
        if(length==maxlen)
        {
            ans=max(ans,sum);
        }

        else if(length>maxlen)
        {
            ans = sum;
            maxlen = length;
        }
    }

    else
    {
        sum+= Root->value; //updating sum.

        longestBloodlineSum(Root->leftson,sum,ans,maxlen,length+1);
        longestBloodlineSum(Root->rightson,sum,ans,maxlen,length+1);
    }

    return 0;
}

int main()
{
    Tnode *Tree = NULL;
    createTree(Tree);

    float ans = 0;
    int maxlen = 0;
    longestBloodlineSum(Tree,0,ans,maxlen,0);
    cout<<"\n\nThe Longest Bloodline of the Given Binary Tree Sums up to: "<<ans<<endl<<endl;
    
    return 0;
}