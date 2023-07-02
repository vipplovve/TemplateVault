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

    friend Tnode* lowestCommonAncestor( Tnode * Root,float v1, float v2);
    friend Tnode* createTree (Tnode * &Root);
    friend int main();
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

Tnode* lowestCommonAncestor(Tnode *Root, float v1, float v2)
{
    if(Root == NULL) //base case when we find leaf.
        return NULL;

    else if(Root->value == v1 || Root->value == v2) // finding one of the two.
        return Root;

    Tnode *left = lowestCommonAncestor(Root->leftson,v1,v2);
    Tnode *right = lowestCommonAncestor(Root->rightson,v1,v2);

    if((left == NULL )== !(right == NULL)) 
    {
        if(left)
            return left;
        else
            return right;
    }

    else if(left != NULL && right != NULL) //got the answer.
        return Root;
    
    else //nothing found.
        return NULL;
    
}
int main()
{
    Tnode *Tree = NULL;
    createTree(Tree);

    cout<<"\nEnter The Two Values who's Lowest Common Ancestor you wish to find: ";
    float a,b;
    cin>>a>>b;

    Tnode *ans = lowestCommonAncestor(Tree,a,b);
    cout<<"\nThe Lowest Common Ancestor of "<<a<<" & "<<b<<" is: "; 
    ans?cout<<ans->value:cout<<"Not Found..."; //checking if the nodes are even present or not.
    cout<<endl<<endl;

    return 0;
}