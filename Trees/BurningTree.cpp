#include <iostream>
#include <queue>
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

//creating a mapping b/w every node and it's parents + returning the node which we seek to burn.

Tnode* SonFatherValue(Tnode *Root, float Target, map<Tnode*,Tnode*> &SonFather)
{
    Tnode* result = NULL;
    queue<Tnode*> q;
    q.push(Root);

    while(!q.empty())
    {
        Tnode* front = q.front();
        q.pop();

        if(front->value == Target) //if target has been found.
            result = front;

        if(front->leftson) //traversing left sub-tree.
        {
            SonFather[front->leftson] = front;
            q.push(front->leftson);
        }

        if(front->rightson) //traversing right sub-tree.
        {
            SonFather[front->rightson] = front;
            q.push(front->rightson);
        }
    }

    return result;
}

void BurningTree(Tnode * target, int &ans, map<Tnode*,Tnode*>sonfather)
{
    map<Tnode*,bool> visited;
    queue<Tnode*> q;
    q.push(target);
    visited[target] = true; //storing the target in the visited map.

    while(!q.empty())
    {
        bool check = false;
        int size = q.size();

        for(int i = 0 ; i< size; i++)
        {
            Tnode* front = q.front(); //traversing the queue.
            q.pop();

            if(front->leftson && !visited[front->leftson]) //checking if a left son exists and burning it.
            {
                check = true;
                q.push(front->leftson);
                visited[front->leftson] = true;
            }
        
            if(front->rightson && !visited[front->rightson]) //checking if a right son exists and burning it.
            {
                check = true;
                q.push(front->rightson);
                visited[front->rightson] = true;
            }

            if(sonfather[front] && !visited[sonfather[front]]) //checking if a father exists and burning it.
            {
                check = true;
                q.push(sonfather[front]);
                visited[sonfather[front]] = true;
            }

        }

        if(check)
            ans++;
    }
}

int main()
{
    Tnode* Root = NULL;
    createTree(Root);

    cout<<"\nEnter Time Taken to Burn a Node: "; //self explanatory.
    float time;
    cin>>time;

    cout<<"\nEnter The Node You wish to Burn: "; //taking input of target node.
    float val;
    cin>>val;
    map<Tnode*,Tnode*> fathersonmap;
    Tnode* target = SonFatherValue(Root,val,fathersonmap); //creating the mapping and findind the target node.

    int ans = 0;
    BurningTree(target,ans,fathersonmap); //finding how many turns are required to burn the tree.

    cout<<"\nTotal Time Taken to Burn this Tree is: "<<ans*time<<" seconds."<<endl<<endl; //printing final time required by multiplying time with ans.

    return 0;
}