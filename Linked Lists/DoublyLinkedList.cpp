#include <iostream>
using namespace std;

class node //defining a class.
{
    public:

    int data;
    node *next;
    node *prev;

    node(int value) //constructor to add value.
    {
        data = value;
        next = NULL;
        prev = NULL;
    }

    

};

void insertHead(node * &head, int value) //insertion at beginning.
{
    node *temp = new node(value);

    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertTail(node * &head, int value) //insertion at end.
{
    while(head->next!=NULL)
    head = head->next;

    node *temp = new node(value);
    
    head->next= temp;
    head = temp;
    temp->prev = head;
}

void printthem(node* &head) //printing the linked list.
{   
    node *temp = head;
    do
    {
        cout<<(temp)<<" : "<<temp->data<<" : "<<(temp->next)<<endl; 
        temp = temp->next;
    }
    while(temp != NULL);
}

void deleteit(node* &head, int value) //deleting a certain valued node.
{
    
    node *point = head;
    node *prevpoint = NULL;
    
    while(point->next != NULL)
    {
        prevpoint = point;
        point = point->next;
        if(point->data == value)
        {
            prevpoint->next=point->next;
            point->next=NULL;
        }
        
    }
}

void insertAnywhere(node * &head, int pos,int value) //inserting at any location.
{
    node *temp = new node(value);
    node *ins = head;
    int x = 1;
    
    if(pos == 1)
        {
            insertHead(head,value);
            return;
        }

    while( x<pos-1)
        {
            ins = ins->next;
            x++;
        }
    
    if(ins->next == NULL)
        {
            insertTail(head,value);
            return;
        }
    
    temp->next=ins->next;
    ins->next->prev=temp;
    temp->prev=ins;
    ins->next=temp;


}

int main()
{
    int val;
    string choice;

    cout<<"Enter the value of the 1st Node: ";
    cin>>val;

   node *head = new node(val); //creating an object.

   while(true)
   {
    cout<<"\nWhat would you like to perform? : -\n\n";
   cout<<"->Head Insertion\n->Tail Insertion\n->Positional Insertion\n->Deletion\n->Termination\n";
   fflush(stdin);
   cout<<"\nEnter Your Choice: ";
   getline(cin,choice);

    if(choice == "Head Insertion")
    {
        int len;
        cout<<"\nHow many elements do you wish to enter? ";
        cin>>len;

        cout<<"\nEnter Values: -\n";
        for(int x = 0 ; x<len ; x++)
        {
            
            cin>>val;
            insertHead(head,val);
        }

        cout<<"\nPrinting the So-Formed Doubly Linked List: -\n\n";
        printthem(head);

    }

    if(choice == "Positional Insertion")
    {

        int len,pos;
        cout<<"\nHow many elements do you wish to enter? ";
        cin>>len;

        cout<<"\nEnter Values + Position: -\n";
        for(int x = 0 ; x<len ; x++)
        {
            
            cin>>val;
            cin>>pos;
            insertAnywhere(head,pos,val);
        }

        cout<<"\nPrinting the So-Formed Doubly Linked List: -\n\n";
        printthem(head);

    }

    if(choice == "Tail Insertion")
    {
        node *point = head;
        int len;
        cout<<"\nHow many elements do you wish to enter? ";
        cin>>len;

        cout<<"\nEnter Values: -\n";
        for(int x = 0 ; x<len ; x++)
        {
            
            cin>>val;
            insertTail(head,val);
        }

        cout<<"\nPrinting the So-Formed Doubly Linked List: -\n\n";
        printthem(point);

    }

    if(choice == "Deletion")
    {
        cout<<"\nEnter the element you wish to delete: ";
        cin>>val;

        deleteit(head,val);

        cout<<"\nPrinting the So-Formed Doubly Linked List: -\n\n";
        printthem(head);
    }

    if(choice == "Termination") //terminating the program.
    {
        cout<<"\naight i'm terminating this. bbye."<<endl<<endl;
        delete head;
        return 0;
    }

   }

    return 0;
}