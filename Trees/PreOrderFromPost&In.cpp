#include <iostream>
#include <map>
using namespace std;

class Tnode //a tree node object.
{
    public:

    float value;
    Tnode *leftson;
    Tnode *rightson;

    Tnode(float value) //parameterised constructor.
    {
        this->value = value;
        leftson = NULL;
        rightson = NULL;
    }

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

void createmapping(float inorder[], map<float,int>&m,int length) //mapping all the node values with their indices in inOrder sequence.
{
    for(int i =0 ; i<length ; i++)
        m[inorder[i]] = i;
}

Tnode* solveit(float inorder[],float postorder[],int &baseindex, int start, int end, int size, map<float,int> &m)
{
    if(baseindex >= size || start > end) //base condition.
        return NULL;
    
    //dividing the sequence and creating nodes accordingly.

    int element = postorder[baseindex--];
    Tnode *Root = new Tnode(element);
    int position = m[element];

    //making recursive calls for left and right subtree.

    Root->rightson = solveit(inorder,postorder,baseindex,position+1,end,size,m);
    Root->leftson = solveit(inorder,postorder,baseindex,start,position-1,size,m);

    return Root;
}
Tnode* TreeGenerator(float inorder[],float postorder[],int length) //creating a tree from the given sequences.
{
    int baseindex = length - 1;
    map<float,int>m;
    createmapping(inorder,m,length);
    Tnode* solution = solveit(inorder,postorder,baseindex,0,length-1,length,m);   
    return solution;
}

void PreOrder(Tnode *Tree) //printing the pre order traversal of the tree.
{
    
    if(Tree != NULL)
    {
        cout<<Tree->value<<' ';
        PreOrder(Tree->leftson);
        PreOrder(Tree->rightson);
    }

    else
        return;
}

int main()
{
    int length;
    cout<<"Enter Number of Terms: ";
    cin>>length;

    float inorder[length],postorder[length];
    
    cout<<"\nEnter The InOrder Sequence: ";
    
    for(int i = 0; i<length ; i++)
        cin>>inorder[i];
    
    cout<<"\nEnter the PostOrder Sequence: ";
    for(int i =0 ; i<length; i++)
        cin>>postorder[i];
    
    cout<<"\nThe Pre Order Sequence Generated would be: -\n\n";
    Tnode*Tree = TreeGenerator(inorder,postorder,length);
    PreOrder(Tree);
    cout<<endl<<endl;

    return 0;

}