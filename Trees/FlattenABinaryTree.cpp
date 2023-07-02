#include <iostream>
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

void FlattenTheTree(Tnode *Root) //using morris traversal technique to form a preOrder Sequence.
{
    //creating a dummy pointer to Root Node.

    Tnode *pointer = Root;
    Tnode* predecessor;

    while (pointer) //while we are at a non-null node.
    {
        if(pointer->leftson) //if left son exists.
        {
            predecessor = pointer->leftson; //find it's inOrder predecessor.
            while(predecessor->rightson)
                predecessor = predecessor->rightson;

            predecessor->rightson = pointer->rightson; //create a link b/w predecessor and Root's right subtree.
            pointer->rightson = pointer->leftson; //direct the link b/w root and it's right subtree towards left subtree.
            pointer->leftson = NULL; //remove the link b/w root and it's left subtree.
        }

        else //left son is null.
            pointer = pointer->rightson; //change position of root.
    }
    
}

int main()
{
    Tnode *Tree = NULL;
    createTree(Tree);

    FlattenTheTree(Tree);

    cout<<"\nThe So-Formed Flattened Binary Tree is: -\n\n";
    
    // printing the flattened binary tree.
    
    while(Tree)
    {
        cout<<Tree->value<<" ~ ";
        Tree = Tree->rightson;
    }
    cout<<endl<<endl;

    return 0;
}