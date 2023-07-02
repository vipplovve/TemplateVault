#include <bits/stdc++.h>
using namespace std;

class Tnode
{
    public:

    int value;
    Tnode *leftson;
    Tnode *rightson;

    Tnode(int val) //constructor to initiate tree nodes.
    {
        value = val;
        leftson = NULL;
        rightson = NULL;
    }

};

Tnode* createTree(Tnode * &Root)
{
    int val; //taking input.
    cout<<"Enter Data: ";
    cin>>val;

    if(val == -1) //base case to stop.
    return NULL;

    else
    {
        Root = new Tnode(val); //creating a node.

        //creating left and right sub-trees.

        cout<<"\nTo the Left of "<<val<<" : - ";
        Root->leftson = createTree(Root->leftson);
        cout<<"\nTo the Right of "<<val<<" : - ";
        Root->rightson = createTree(Root->rightson);   
    }

    return Root;

}

pair<int,int> MaxNonAdjSum(Tnode *Tree)
{
    if(!Tree) //checking for empty node.
    {
        pair<int,int> ans = {0,0};
        return ans;
    }

    //traversing left and right subtrees.

    pair<int,int> left = MaxNonAdjSum(Tree->leftson);
    pair<int,int> right = MaxNonAdjSum(Tree->rightson);

    pair <int,int> res;

    res.first = Tree->value + left.second + right.second; //including node value.

    res.second = max(left.first,left.second) + max(right.first,right.second); //excluding node value.

    return res;    
}

int main()
{
    Tnode *Tree = NULL;
    createTree(Tree);

    pair<int,int> p = MaxNonAdjSum(Tree); 

    //finding max. of inclusion and exclusion value and printing it.

    cout<<"\n\nMax. Sum of Non-Adjacent Nodes is: "<<max(p.first,p.second)<<endl<<endl;

    return 0;
}

