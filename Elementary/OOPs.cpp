#include <iostream>
#include <string.h>
using namespace std;

class human
{
    private: 

    int age;
    char gender;
    string name;
    int height;
    float weight;

    public: 

    human giveinfo()
    {
        cout<<age<<" "<<height<<" "<<weight<<" "<<gender<<" "<<name<<endl;
    }

    void putinfo(int age,int height, float weight, char gender, string name)
    {
        this->age=age;
        this->height=height;
        this->weight=weight;
        this->gender=gender;
        this->name=name;
    }
};

int main()
{
    int num;

    cout<<"\nWelcome to The Human Records Keeper."<<endl;
    cout<<"\nEnter The Number of Records you wish to enter: ";
    cin>>num;

    int age,height;
    float weight;
    char gender;
    string name;

    human *record=new human[num]; //dynamically declaring a class-object.

    for(int x=0;x<num;x++) //taking input for each entry
    {  
         cout<<"\nEnter Record #"<<x+1<<" : - ";
         cin>>age>>height>>weight>>gender>>name;
         record[x].putinfo(age,height,weight,gender,name);
    }

    cout<<"\nPrinting All the Records: -\n\n";

    for(int x=0;x<num;x++) //printing all the stored records.
    {
        record[x].giveinfo();
        cout<<endl;
    }

    return 0;

}