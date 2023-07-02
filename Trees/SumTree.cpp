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
    friend bool SumTree(Tnode *Root);
    friend float sum(Tnode *Root);
};

Tnode* createTree(Tnode * &Root)
{
    float val;
    cout<<"Enter Data: ";
    cin>>val;

    if(val == -1)
    return NULL;

    else
    {
        Root = new Tnode(val);
        cout<<"\nTo the Left of "<<val<<" : - ";
        Root->leftson = createTree(Root->leftson);
        cout<<"\nTo the Right of "<<val<<" : - ";
        Root->rightson = createTree(Root->rightson);   
    }

    return Root;

}

float sum(Tnode *Tree) // a function to calculate sum of all nodes.
{
    if(Tree == NULL)
    return 0;

    else
    return Tree->value + sum(Tree->leftson) + sum(Tree->rightson);
}

bool SumTree(Tnode *Root) //to check for sum tree.
{
    if(Root == NULL) // base case for null node.
    return true;

    else
    return (Root->value == sum(Root->leftson) + sum(Root->rightson));
}

int main()
{
    Tnode *Root = NULL;
    createTree(Root);

    cout<<"Sum of All the Nodes is: "<<sum(Root)<<endl;
    SumTree(Root)?cout<<"\nIt's a Sum Tree.\n\n":cout<<"\nIt's not a Sum Tree.\n\n";
    
    return 0;
}

//non-optimised approach.