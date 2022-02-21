#include <iostream>
#include <limits>
#include <string>
using namespace std;
class FullName
{
private:
    string FirstName, MiddleName, LastName;
public:
    FullName()
    {
        FirstName="Benzema"; MiddleName="Karim"; LastName="Aka";
    }
    FullName(string FN, string MN, string LN):LastName(LN)
    {
        FirstName=FN; MiddleName=MN; 
    }
    ~FullName()
    {}
    void setFirstName(string FN)
    {
        FirstName=FN;
    }
    string getFirstName()
    {
        return FirstName;
    }
    void setMiddleName(string MN)
    {
        MiddleName=MN;
    }
    string getMiddleName()
    {
        return MiddleName;
    }
    void setLastName(string LN)
    {
        LastName=LN;
    }
    string getLastName()
    {
        return LastName;
    }
};

class Player
{
private:
    string Player_ID;
    FullName Player_Name;
    int Matches_Played;
    static int Goals_Scored;
public:
    Player()
    {
        Player_ID="9";
        Matches_Played=900;
        Goals_Scored=0;
    }
    Player(string ID,int mp,FullName FN)
    {
        Player_ID=ID;
        Matches_Played=mp;
        Player_Name=FN;
    }
    ~Player()
    {
    }
    void setPlayer_ID(string ID)
    {
        Player_ID=ID;
    }
    string getPlayer_ID()
    {
        return Player_ID;
    }
    void setMatchesPlayed(int MP)
    {
        Matches_Played=MP;
    }
    int getMatchesPlayed()
    {
        return Matches_Played;
    }
    static void setGoalsScored(int GS)
    {
        Goals_Scored=GS;
    }
    static int getGoalsScored()
    {
        return Goals_Scored;
    }
    void setPlayer_Name()
    {
        string FN,MN,LN;
        cout<<"Enter First Name:";
        cin>>FN;
        Player_Name.setFirstName(FN);
        cout<<"Enter Middle Name:";
        cin>>MN;
        Player_Name.setMiddleName(MN);
        cout<<"Enter Last Name:";
        cin>>LN;
        Player_Name.setLastName(LN);
    }
    void getPlayer_Name()
    {
        cout<<Player_Name.getFirstName()<<" : "<<Player_Name.getMiddleName()<<" : "<<Player_Name.getLastName()<<endl;
    }
    friend void Increase_GoalsScored(Player &p);
};
int Player::Goals_Scored=0;
void Increase_GoalsScored(Player &p)
{
    p.Goals_Scored++;
}   
Player *p1=new Player;
int main()
{
    Player *p= new Player; FullName *f=new FullName;string fn,mn,ln,id;int mp;
    int n,second_choice;
    int Goals_Scored;
    while(true)
    {
        cout<<"Which option you want to choose?\n\t1. Add player Detail\n\t2. Display player Detail\n\t3. Goals Scored\n\t4. Delete player from memory\n\t5. Exit"<<endl;
        cin>>n;
        switch (n)
        {
        case 1:
            cout<<"What do you want to change?\n\t1. First Name\n\t2. Middle Name\n\t3. Last Name\n\t4. Matches Played\n\t5. Player ID\n\t6. Goals Scored\n\t7. All of them"<<endl;
            cin>>n;
            switch(n)
            {
                case 1:
                    cout<<"Enter First Name:";
                    cin>>fn;
                    f->setFirstName(fn);
                break; 
                case 2:
                    cout<<"Enter Middle Name:";
                    cin>>mn;
                    f->setMiddleName(mn);
                break;
                case 3:
                    cout<<"Enter Last Name:";
                    cin>>ln;
                    f->setLastName(ln);
                break;
                case 4:
                    cout<<"Enter Matches PLayed:";
                    cin>>mp;
                    p->setMatchesPlayed(mp);
                break;
                case 5:
                    cout<<"Enter Player ID:";
                    cin>>id;
                    p->setPlayer_ID(id);
                break;
                case 6:
                    cout<<"Enter Goals Scored:";
                    cin>>Goals_Scored;
                    p->setGoalsScored(Goals_Scored);
                break;
                case 7:
                    cout<<"Enter First Name:";
                    cin>>fn;
                    f->setFirstName(fn);
                    cout<<"Enter Middle Name:";
                    cin>>mn;
                    f->setMiddleName(mn);
                    cout<<"Enter Last Name:";
                    cin>>ln;
                    f->setLastName(ln);
                    cout<<"Enter Matches PLayed:";
                    cin>>mp;
                    p->setMatchesPlayed(mp);
                    cout<<"Enter Goals Scored:";
                    cin>>Goals_Scored;
                    p->setGoalsScored(Goals_Scored);
                    cout<<"Enter Player ID:";
                    cin>>id;
                    p->setPlayer_ID(id);
                break;
            }
        break;
        case 2:
            cout<<"Wnat do you want to display?\n\t1. First Name\n\t2. Middle Name\n\t3. Last Name\n\t4. Matches Played\n\t5. Player ID\n\t6. Goals Scored\n\t7. All of them"<<endl;
            cin>>second_choice;
            switch(second_choice)
            {
                case 1:
                    cout<<"First Name:"<<f->getFirstName()<<endl;
                break;
                case 2:
                    cout<<"Middle Name:"<<f->getMiddleName()<<endl;
                break;
                case 3:
                    cout<<"Last Name:"<<f->getLastName()<<endl;
                break;
                case 4:
                    cout<<"Matches Played:"<<p->getMatchesPlayed()<<endl;
                break;
                case 5:
                    cout<<"Player ID:"<<p->getPlayer_ID()<<endl;
                break;
                case 6:
                    cout<<"Goals Scored:"<<p->getGoalsScored()<<endl;
                break;
                case 7:
                    cout<<"First Name:"<<f->getFirstName()<<endl<<" Middle Name:"<<f->getMiddleName()<<endl<<" Last Name:"<<f->getLastName()<<endl<<" Matches Played:"<<p->getMatchesPlayed()<<endl<<" Goals Scored:"<<p->getGoalsScored()<<endl<<" Player ID:"<<p->getPlayer_ID()<<endl;
                break;
            }
        break;
        case 3:
            Increase_GoalsScored(*p1);
            cout<<"Goal increased by one"<<endl;
        break;
        case 4:
            delete p; delete f;
        break;
        }
        if(n==5)
        break;
    }
    return 0;
}
