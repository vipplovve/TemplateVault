#include <iostream>
using namespace std;

class Tnode //a tree node object.
{
    float value;
    Tnode *leftson;
    Tnode *rightson;

    public:

    Tnode(float value) //parameterised constructor.
    {
        this->value = value;
        leftson = NULL;
        rightson = NULL;
    }

    friend Tnode* createTree(Tnode * &Root);
    friend bool IdenticalTrees(Tnode *Root,Tnode *root);
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

bool IdenticalTrees(Tnode *Root1,Tnode *Root2)
{
    if(Root1 == NULL && Root2 == NULL) //base case when both null.
    return true;

    else if((Root1 == NULL) == !(Root2 == NULL)) //base case when both have opposite nature.
    return false;

    else //case when both are non null nodes.
    {
        bool left = IdenticalTrees(Root1->leftson,Root2->leftson);
        bool right = IdenticalTrees(Root1->rightson,Root2->rightson);
        bool valcheck = (Root1->value == Root2->value);

        if(left && right && valcheck)
            return true;

        else    
            return false;
    }
}

int main()
{
    Tnode *Root1 = NULL;
    Tnode *Root2 = NULL;

    cout<<"Enter Tree #1: -\n\n";
    createTree(Root1);
    cout<<"\nEnter Tree #2: -\n\n";
    createTree(Root2);

    IdenticalTrees(Root1,Root2)?cout<<"\nThe Given Binary Trees are Identical..\n\n":cout<<"\nThe Given Binary Trees aren't Identical..\n\n";

    return 0;
}