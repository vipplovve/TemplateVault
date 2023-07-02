#include <iostream>
using namespace std;

class Tnode
{
    public:

    int value;
    Tnode *leftson;
    Tnode *rightson;

    public:

    Tnode(int val) //constructor to initiate tree nodes.
    {
        value = val;
        leftson = NULL;
        rightson = NULL;
    }

    friend void traverseLeft(Tnode *Root);
    friend void traverseRight(Tnode *Root,float r);
    friend void traverseLeaf(Tnode *Root);
    friend Tnode* createTree (Tnode * &Root);
};

Tnode* createTree(Tnode * &Root) //creation function.
{
    float val;
    cout<<"Enter Data: ";
    cin>>val;
    
    Root = new Tnode(val);

    if(val == -1) //base case for no node.
    return NULL;

    else //recursive call for left and right sub-tree creation.
    {
        cout<<"\nTo the Left of "<<val<<" : - ";
        Root->leftson = createTree(Root->leftson);
        cout<<"\nTo the Right of "<<val<<" : - ";
        Root->rightson = createTree(Root->rightson);

    }

    return Root;
}

void traverseLeft(Tnode *Root) //printing all the leftmost non leaf nodes.
{
    if(Root  == NULL || (Root->leftson == NULL && Root->rightson == NULL))
        return;

    else
    {
        cout<<Root->value<<' ';
        if(Root->leftson != NULL)x
            traverseLeft(Root->leftson);
        else
            traverseLeft(Root->rightson);
    }
}

void traverseLeaf(Tnode *Root) //printing leaf nodes.
{
    if(Root == NULL)
        return;

    else if(Root->leftson == NULL && Root->rightson ==NULL)
        {cout<<Root->value<<' ';
        return;}
    
    traverseLeaf(Root->leftson);
    traverseLeaf(Root->rightson);
}

void traverseRight(Tnode *Root, float r) //printing rightmost non leaf nodes in reverse and excluding root value.
{
    if(Root  == NULL || (Root->leftson == NULL && Root->rightson == NULL))
        return;
    
    else
    {
        if(Root->rightson)
            traverseRight(Root->rightson,r);
        else
            traverseRight(Root->leftson,r);
    }

    if(Root->value != r)
    cout<<Root->value<<' ';
}

int main()
{
    Tnode *Root = NULL;
    createTree(Root);

    cout<<"\nBoundary Traversal of the Following Tree: -\n\n";
    traverseLeft(Root);

    traverseLeaf(Root->leftson);
    traverseLeaf(Root->rightson);

    float r = Root->value;
    traverseRight(Root,r);

    return 0;
}