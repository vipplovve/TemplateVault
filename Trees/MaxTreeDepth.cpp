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
    friend int findDepth(Tnode *Root);
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

int findDepth(Tnode *Tree) //finding max depth.
{
    if(Tree != NULL) 
    {
        return 1 + max(findDepth(Tree->leftson),findDepth(Tree->rightson));
    }

    else //leaf encountered.
        return 0;
}

int main()
{
    Tnode *Root = NULL;

    createTree(Root);
    int d =findDepth(Root);

    cout<<"\nThe Max. Tree Depth is: "<<d<<endl<<endl;

    return 0;
}
