#include <bits/stdc++.h>
using namespace std;

class Tnode
{
    public:

    float value;
    Tnode *leftson;
    Tnode *rightson;

    Tnode(int val) //constructor to initiate tree nodes.
    {
        value = val;
        leftson = NULL;
        rightson = NULL;
    }

    friend Tnode* KthAncestor( Tnode * Root,int &k, float val);
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

Tnode* KthAncestor(Tnode *Root, int &k, float val)
{
    if(Root == NULL) //base case.
        return NULL;

    if(Root->value == val) //value has been found.
        {
            return Root;
        }

    //check left and right sub-tree.

    Tnode *left = KthAncestor(Root->leftson,k,val);
    Tnode *right = KthAncestor(Root->rightson,k,val);

    //value has been found in a sub-tree.

    if(left!=NULL || right!=NULL)
    {
        k--;
        if(k==0) //we're at the Kth Ancestor now.
        {
            return Root; //return it.
            k=999999; //lock it.
        }
        if(left == NULL)
            return right;
        else
        return left;
    }
    return NULL;
}

int main()
{
    Tnode *Tree = NULL;
    createTree(Tree);

    cout<<"\nEnter The Node Value and K's Value:";
    float v;
    int k;
    cin>>v>>k;
    cout<<"\nThe Answer is: ";
    cout<<KthAncestor(Tree,k,v)->value;
    cout<<endl<<endl;

    return 0;
}