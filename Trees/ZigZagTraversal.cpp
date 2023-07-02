#include <iostream>
#include <queue>
#include <vector>
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

    friend void ZigZagTraversal(Tnode *Root);
    friend Tnode* createTree (Tnode * &Root);
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

void ZigZagTraversal(Tnode *Root)
{
    queue<Tnode*> q;
    q.push(Root);
    bool direction = true; //check the level and traverse accordingly.

    while(!q.empty())
        {
            int size = q.size();
            vector <float> ans(size);

            for(int i = 0; i<size; i++)
            {
                Tnode *T = q.front();
                q.pop();

                int z = direction?i:size-1-i;

                ans[z]=T->value;
                if(T->leftson) 
                    q.push(T->leftson);
                if(T->rightson)
                    q.push(T->rightson);
            }

            direction = !direction;

            for(int i:ans)
                cout<<i<<" ";

        }
}

int main()
{
    Tnode *Tree = NULL;
    createTree(Tree);

    cout<<"\nZig-Zag Traversal is: -\n\n";
    ZigZagTraversal(Tree);
    
    return 0;
}