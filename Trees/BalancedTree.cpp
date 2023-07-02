#include <iostream>
using namespace std;

class answer
{
    public:

    bool balanced;
    int height;

}ans;

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
    friend answer BalancedTree(Tnode *Root);
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

answer BalancedTree(Tnode *Root)
{
    if(Root == NULL) //base case.
    {
        answer a;
        a.balanced = true;
        a.height = 0;
        return a;
    }

    else 
    {
        //checking balancing in left and right sub-trees.

        answer C1 = BalancedTree(Root->leftson);
        answer C2 = BalancedTree(Root->rightson);

        bool c1 = C1.balanced;
        bool c2 = C2.balanced;
        bool c3 = (abs(C1.height - C2.height) <= 1);

        ans.height = max(C1.height,C2.height) + 1;

        //evaluating the three conditions.

        if(c1 && c2 && c3)
        {
            ans.balanced = true;
        }
        else
            ans.balanced = false;
    }
    return ans;
}

int main()
{
    Tnode *Root = NULL;
    createTree(Root);

    BalancedTree(Root).balanced?cout<<"\nThis Binary Tree is Balanced..\n\n":cout<<"\nThis Binary Tree isn't Balanced..\n\n";

    return 0;
}