#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class memberType
{
private:
    string name;
    int ID;
    int num_of_book;
    float amount_spent;
public:
    memberType(string name="John", int ID=0,int num_book=0, float amount_spent=0)
    {
        setName(name); setID(ID); setNum_Book(num_book); setAmount_Spent(amount_spent);
    }
    ~memberType(){}
    void setName(string name){this->name=name;}
    void setID(int ID){this->ID=ID;}
    void setNum_Book(int num_book){this->num_of_book=num_book;}
    void setAmount_Spent(float amount_spent){this->amount_spent=amount_spent;}
    string getName(){return name;}
    int getID(){return ID;}
    int getNum_Book(){return num_of_book;}
    float getAmount_spent(){amount_spent=50*num_of_book;return amount_spent;}
    friend void operator>>(istream &in, memberType&t);
    friend void operator<<(ostream &out, memberType&s);
    void operator++(int)
    {
        num_of_book++;
    }
};
void operator>>(istream &in, memberType&t)
{
    cout<<"Enter the name:";
    cin>>t.name;
    cout<<"Enter the Amount of Books:";
    cin>>t.num_of_book;
    t.ID++;
}
void operator<<(ostream &out, memberType&s)
{
    cout<<"The Name:"<<s.getName()<<endl;
    cout<<"The ID:"<<s.getID()<<endl;
    cout<<"The Number of Books:"<<s.getNum_Book()<<endl;
    cout<<"The Total Amount:"<<s.getAmount_spent()<<endl;
}
int main()
{
    memberType mt;
    char *choice;
    string name;
    int ID,book;
    long int x;
    while(true)
    {
    cout<<"\tMenu"<<endl;
    cout<<"Which option do you want to choose?"<<endl;
    cout<<"\t[1] ADD Member"<<endl;
    cout<<"\t[2] Dislpay Details"<<endl;
    cout<<"\t[3] ADD a book"<<endl;
    cout<<"\t[4] Exit"<<endl;
    cin>>choice;
    x=strtol(choice,NULL,10);
    switch(x)
    {
        case 1: 
            cin>>mt;
        break;
        case 2:
            cout<<mt;
        break;
        case 3:
            mt++;
        break;
    }
        if(x==4) break;
    }
    cout<<"Good Bye!\nSee you Later"<<endl;
    return EXIT_SUCCESS;
}
