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

    friend void KSumPath( Tnode * Root,int &count, float k, vector<float> &path);
    friend Tnode* createTree (Tnode * &Root);
};

Tnode* createTree(Tnode * &Root)
{
    // taking input.

    float val;
    cout<<"Enter Data: ";
    cin>>val;

    if(val == -1)   //base case to stop.
    return NULL;

    else //creating left and right subtrees.
    {
        Root = new Tnode(val);
        cout<<"\nTo the Left of "<<val<<" : - ";
        Root->leftson = createTree(Root->leftson);
        cout<<"\nTo the Right of "<<val<<" : - ";
        Root->rightson = createTree(Root->rightson);   
    }

    return Root;

}

void KSumPath(Tnode *Tree, int &count, float k, vector<float> &path)
{
    if(Tree == NULL) //base leaf case.
        return;

    else
    {
        path.push_back(Tree->value); //pushing the value to vector.

        //evaluating the subtrees.

        KSumPath(Tree->leftson,count,k,path); 
        KSumPath(Tree->rightson,count,k,path);

        int s = path.size(),sum=0;

        for(int i = s -1; i > -1 ; i--)
        {
            sum+=path[i]; //finding sum and comparing it with required value.
            if(sum == k)
                {
                    count++; //incrementing the counter

                    for(int x = i;x<s;x++) //printing the path too.
                        cout<<path[x]<<' ';
                    cout<<endl;   
                }
        }
    path.pop_back();
    }
}

int main()
{
    Tnode *Root = NULL;
    createTree(Root);

    float k;
    cout<<"\nEnter The Sum: ";
    cin>>k;

    cout<<"\nPossible Path Are: -\n\n";
    vector<float> ans;
    int count = 0;
    KSumPath(Root,count,k,ans);
    cout<<"\nThe Total No. of Paths Whose Sum is Equal to "<<k<<" are: "<<count<<endl<<endl;

    return 0;
}