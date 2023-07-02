#include <bits/stdc++.h>
using namespace std;

class node
{
    int value;
    node *next;

    public:

    node(int x)
    {
        cout<<"Node has been created..."<<endl;
        value = x;
        next = NULL;
    }

    ~node()
    {
        cout<<"Node Has Been Deleted..."<<endl;
        delete next;
    }  

    friend void insertafter(int, int);
    friend void printthem();
};

node *head = new node(0);

void insertafter(int val, int newval)
{
    node temp(newval);
    node *check = head;
    while(check->next != NULL)
    check=check->next;

    check->next = &temp;
    temp.next = head;
}



int main()
{
    insertafter(0,1);
    insertafter(1,2);
    insertafter(2,3);
    insertafter(3,4);

    //printthem();

    return 0;
    delete head;
}