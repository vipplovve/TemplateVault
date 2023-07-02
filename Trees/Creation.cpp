#include <bits/stdc++.h>
using namespace std;

class Tnode
{

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

    friend void LOTraversal( Tnode * Root);
    friend Tnode* createTree (Tnode * &Root);
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

void LOTraversal (Tnode * Root) //traversing a B.T. via Level Order Traversal Technique.
{
    cout<<"\nPrinting the So-Formed Binary Tree: -\n\n";
    queue<Tnode*> q;
    q.push(Root);
    q.push(NULL);
    
    while(!q.empty())
    {
        Tnode *temp = q.front();
        q.pop();

        if(temp == NULL)
        {
            cout<<'\n';
            if(!q.empty())
                q.push(NULL);
        }
        
        else
        {
            cout<<temp->value<<' ';
        
            if(temp->leftson)
                q.push(temp->leftson);

            if(temp->rightson)
                q.push(temp->rightson);

        }
     
    }
    cout<<endl;
}
int main()
{
    Tnode *Root = NULL;

    createTree(Root);

    LOTraversal(Root);

    return 0;
}
