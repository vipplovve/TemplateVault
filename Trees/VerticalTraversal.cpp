#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

class Tnode
{
    public:

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

};

class Box
{
    public:
    
    Tnode *tree;
    int HD;

    Box(Tnode *t,int hd)
    {
        tree = t;
        HD = hd;
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

void VerticalTraversal(Tnode *Root) 
{
    map <int,vector<int>> nodes; //mapping to store positions and elements.
    queue<Box> q; //queue for traversal.
    Box b(Root,0);

    if(Root == NULL) //base case.
    return;

    else //LOTraversal similiar execution.
    {
        q.push(b);
        while(!q.empty())
        {
            Box T = q.front();
            q.pop();

            nodes[T.HD].push_back(T.tree->value); //pushing values into map vector.

            if(T.tree->leftson)
                {
                    Box c(T.tree->leftson,T.HD - 1);
                    q.push(c);
                }
            if(T.tree->rightson)
                {
                    Box c(T.tree->rightson,T.HD + 1);
                    q.push(c);
                }
        }

        for(auto i:nodes) //printing the required values.
            {for(auto j:i.second)
                cout<<j<<' ';
            cout<<endl;}
    }


}

int main()
{
    Tnode *Root = NULL;
    createTree(Root);

    cout<<"\n\nThe Vertical Traversal for the Given Binary Tree is: \n\n";
    VerticalTraversal(Root);
    cout<<endl;
    
    return 0;
}