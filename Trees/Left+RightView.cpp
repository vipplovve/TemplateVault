#include <bits/stdc++.h>
using namespace std;

class Tnode //creating a tree node class.
{
    public: 

    float value;
    Tnode *leftson;
    Tnode *rightson;

    Tnode(float val) //parameterised constructor.
    {
        value = val;
        leftson = NULL;
        rightson = NULL;
    }

};

class Box //a class to ease the task of returning values in successive functions.
{
    public:
    
    Tnode *tree;
    int lvl;

    Box(Tnode *t,int l)
    {
        tree = t;
        lvl = l;
    }
};

Tnode* CreateTree(Tnode * &Root) //creating a binary tree.
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
        Root->leftson = CreateTree(Root->leftson);
        cout<<"\nTo the Right of "<<val<<" : - ";
        Root->rightson = CreateTree(Root->rightson);   
    }

    return Root;

}

void LeftView(Tnode *Root) //printing the Left-View.
{
    map<int,int> nodes;
    queue<Box> q;
    Box b(Root,0);

    if(Root == NULL)  //base case.  
        return;
    
    else
    {
    //LO-like traversal.

    q.push(b);
    while(!q.empty())
    {
        Box T = q.front();
        q.pop();

        Tnode *tree = T.tree;
        int lvl = T.lvl;

        if(nodes.find(lvl) == nodes.end()) //condition to check whether a level is pre-occupied with value or not.
        nodes[lvl] = tree->value;

        if(tree->leftson)
        {
            Box c(tree->leftson,lvl + 1);
            q.push(c);
        }

        if(tree->rightson)
        {
            Box c(tree->rightson,lvl +1);
            q.push(c);
        }
    }

    for(auto a:nodes) //printing the values.
        cout<<a.second<<' ';}
}

void RightView(Tnode *Root) //similar to Left-View w/o occupance check condition.
{
    map<int,int> nodes;
    queue<Box> q;
    Box b(Root,0);

    if(Root == NULL)  //base case.  
        return;
    
    else
    {
    //LO-like traversal.

    q.push(b);
    while(!q.empty())
    {
        Box T = q.front();
        q.pop();

        Tnode *tree = T.tree;
        int lvl = T.lvl;

        nodes[lvl] = tree->value;

        if(tree->leftson)
        {
            Box c(tree->leftson,lvl + 1);
            q.push(c);
        }

        if(tree->rightson)
        {
            Box c(tree->rightson,lvl +1);
            q.push(c);
        }
    }

    for(auto a:nodes) //printing the values.
        cout<<a.second<<' ';}
}

int main()
{
    Tnode *Root = NULL;
    CreateTree(Root);

    cout<<"\n\nLeft View View of the Given Binary Tree is: -\n\n";
    LeftView(Root);

    cout<<"\n\nRight View View of the Given Binary Tree is: -\n\n";
    RightView(Root);

    cout<<endl<<endl;

    return 0;
}

