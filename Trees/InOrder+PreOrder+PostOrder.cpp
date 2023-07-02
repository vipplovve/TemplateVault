#include <iostream>
using namespace std;

class Tnode
{

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

    friend Tnode* createTree (Tnode * &Root);

    friend void preOrder( Tnode *Root);
    friend void postOrder( Tnode *Root);
    friend void inOrder( Tnode *Root);
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

//use sequence 1 2 3 -1 -1 4 -1 -1 5 6 -1 -1 7 -1 -1 to generate a B.T of the form: -
//1
//2 5
//3 4 6 7

void preOrder(Tnode *Tree) //Root - Left - Right.
{
    
    if(Tree != NULL)
    {
        cout<<Tree->value<<' ';
        preOrder(Tree->leftson);
        preOrder(Tree->rightson);
    }

    else
        return;
}

void inOrder(Tnode *Tree) //Left - Root - Right.
{
    
    if(Tree != NULL)
    {
        inOrder(Tree->leftson);
        cout<<Tree->value<<' ';
        inOrder(Tree->rightson);
    }

    else
        return;
}

void postOrder(Tnode *Tree) //Left - Right - Root.
{
    
    if(Tree != NULL)
    {
        postOrder(Tree->leftson);
        postOrder(Tree->rightson);
        cout<<Tree->value<<' ';
    }

    else
        return;
}

int main()
{
    Tnode *Root =NULL;

    createTree(Root);

    cout<<"\n\nPrinting the preOrder Traversal Sequence: -\n\n";
    preOrder(Root);

    cout<<"\n\nPrinting the inOrder Traversal Sequence: -\n\n";
    inOrder(Root);

    cout<<"\n\nPrinting the postOrder Traversal Sequence: -\n\n";
    postOrder(Root);
    cout<<endl<<endl;

    return 0;
}