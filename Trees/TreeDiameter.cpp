#include <iostream>
using namespace std;

class answer
{
    public:

    int diameter;
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
    friend answer TreeDiameter(Tnode *Root);
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

answer TreeDiameter(Tnode *Root)
{
    if(Root == NULL) //base case.
    {
        answer a;
        a.diameter = 0;
        a.height = 0;
        return a;
    }

    else
    {
        answer D1 = TreeDiameter(Root->leftson); //storing left and right diameters.
        answer D2 = TreeDiameter(Root->rightson);

        int d1 = TreeDiameter(Root->leftson).diameter;
        int d2 = TreeDiameter(Root->rightson).diameter;
        int d3 = 1 + TreeDiameter(Root->leftson).height + TreeDiameter(Root->rightson).height;

        ans.diameter = max(d1,max(d2,d3)); //finding the diameter.
        ans.height = D1.height + D2.height + 1;

        return ans;
    }
    
}

int main()
{
    Tnode *Root = NULL;
    createTree(Root);

    cout<<"\nThe Tree Diameter is: "<<TreeDiameter(Root).diameter<<endl<<endl;

    return 0;
}