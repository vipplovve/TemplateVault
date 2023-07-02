#include <iostream>
using namespace std;

class node //declaring a node class.
{
    public:

    int data;
    node *next;

    node(int value) //creating a constructor.
    {
        data = value;
        next = NULL;
    }

    ~node()
    {
        delete next;
    }
   
};

void insertB(node * &head, int value) //a function to do insertion at beginning.
    {
        node *temp = new node(value);
        (*temp).next = head;
        head = temp;
    }
 
    void insertE(node * &head, int value) //a function to do insertion at end.
    {   
        node *temp = new node(value);
        head->next = temp;
        head=head->next;
    }

    void insertAnywhere(node * &head,int pos, int value) //general case of inserting at any position.
    {
        if(pos == 1)
        {
            insertB(head,value);
            return;
        }

        node *temp = new node(value);
        node *point = head;

        int count = 1;
        while(count<pos-1)
        {
            point = point->next;
            count++;
        }

        temp->next=point->next;
        point->next= temp;
        

    }   

    void delit(node * &head, int value) //deleting a certain element.
    {
        node *temp = head;
        node *prev = NULL;
        while(temp->next!=NULL)
        {
            prev = temp;
            temp = temp->next;
            if(temp->data==value)
            {
               prev->next=temp->next;
               return; 
            }
        }
    }

    void printthem(node * &head) //printing the elements of a linked list.
    {
        int x = 1;
        node *temp = head;
        while(temp != NULL)
        {
            cout<<"#"<<x<<" : "<<temp<<" : "<<temp->data<<" : "<<(temp->next)<<endl;
            temp = temp->next;
            x++;
        }
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
   cout<<"->insertion at head\n->insertion at tail\n->insertion anywhere\n->deletion\n->bnd krde bhai\n";
   fflush(stdin);
   cout<<"\nEnter Your Choice: ";
   getline(cin,choice);

    if(choice == "insertion at head")
    {
        int len;
        cout<<"\nHow many elements do you wish to enter? ";
        cin>>len;

        cout<<"\nEnter Values: -\n";
        for(int x = 0 ; x<len ; x++)
        {
            
            cin>>val;
            insertB(head,val);
        }

        cout<<"\nPrinting the So-Formed Linked List: -\n\n";
        printthem(head);

    }

    if(choice == "insertion anywhere")
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

        cout<<"\nPrinting the So-Formed Linked List: -\n\n";
        printthem(head);

    }

    if(choice == "insertion at tail")
    {
        node *point = head;
        int len;
        cout<<"\nHow many elements do you wish to enter? ";
        cin>>len;

        cout<<"\nEnter Values: -\n";
        for(int x = 0 ; x<len ; x++)
        {
            
            cin>>val;
            insertE(head,val);
        }

        cout<<"\nPrinting the So-Formed Linked List: -\n\n";
        printthem(point);

    }

    if(choice == "deletion")
    {
        cout<<"\nEnter the element you wish to delete: ";
        cin>>val;

        delit(head,val);

        cout<<"\nPrinting the So-Formed Linked List: -\n\n";
        printthem(head);
    }

    if(choice == "bnd krde bhai") //terminating the program.
    {
        cout<<"\naight i'm terminating this. bbye."<<endl<<endl;
        delete head;
        return 0;
    }
   }

}