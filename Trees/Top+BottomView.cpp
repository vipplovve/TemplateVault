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
    int HD;

    Box(Tnode *t,int hd)
    {
        tree = t;
        HD = hd;
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

void TopView(Tnode *Root) //printing the Top-View.
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
        int hd = T.HD;

        if(nodes.find(hd) == nodes.end()) //condition to check whether a HD is pre-occupied with value or not.
        nodes[hd] = tree->value;

        if(tree->leftson)
        {
            Box c(tree->leftson,hd -1);
            q.push(c);
        }

        if(tree->rightson)
        {
            Box c(tree->rightson,hd +1);
            q.push(c);
        }
    }

    for(auto a:nodes) //printing the values.
        cout<<a.second<<' ';}
}

void BottomView(Tnode *Root) //similar to Top-View w/o occupance check condition.
{
    map<int,int> nodes;
    queue<Box> q;
    Box b(Root,0);
    if(Root == NULL)    
        return;
    else
    {q.push(b);

    while(!q.empty())
    {
        Box T = q.front();
        q.pop();

        Tnode *tree = T.tree;
        int hd = T.HD;

        nodes[hd] = tree->value;

        if(tree->leftson)
        {
            Box c(tree->leftson,hd -1);
            q.push(c);
        }

        if(tree->rightson)
        {
            Box c(tree->rightson,hd +1);
            q.push(c);
        }
    }

    for(auto a:nodes)
        cout<<a.second<<' ';}
}

int main()
{
    Tnode *Root = NULL;
    CreateTree(Root);

    cout<<"\n\nTop View of the Given Binary Tree is: -\n\n";
    TopView(Root);

    cout<<"\n\nBottom View of the Given Binary Tree is: -\n\n";
    BottomView(Root);

    cout<<endl<<endl;

    return 0;
}