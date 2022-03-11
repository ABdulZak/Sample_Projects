#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class Clock
{
private:
    int hour, minutes, seconds;
public:
    Clock(int hour=0,int minutes=0,int seconds=0)
    {
        settime(hour,minutes,seconds);
    }
    void settime(int hour,int minutes,int seconds)
    {
        this->hour=hour;
        this->minutes=minutes;
        this->seconds=seconds;
    }
    void gettime()
    {
        cout<<hour<<":"<<minutes<<":"<<seconds<<endl;
    }
    friend void operator==(Clock &c1, Clock &c2);
    friend Clock operator<<(ostream &out,Clock &c);
    friend Clock operator>>(istream &in,Clock &c);
    void operator++(int)
    {
         hour++;
    }
    void increment_minutes()
    {
        minutes++;
    }
    void increment_seconds()
    {
        seconds++;
    }
};

Clock operator>>(istream &in, Clock &c)
{
    cout<<"Enter hours:"; cin>>c.hour;
    if(c.hour>24) c.hour=0;
    cout<<"Enter minutes:"; cin>>c.minutes;
    while(c.minutes>60)
    {
        c.minutes-=60;
        c.hour++;
    }
    if(c.hour>24) c.hour=0;
    cout<<"Enter seconds:"; cin>>c.seconds;
    while (c.seconds>60)
    {
        c.seconds-=60;
        c.minutes++;
    }
    while(c.minutes>60)
    {
        c.minutes-=60;
        c.hour++;
    }
    c.settime(c.hour,c.minutes,c.seconds);
    return c;
}
Clock operator<<(ostream &out, Clock &c)
{
    c.gettime();
    return c;
}
void operator==(Clock &c1,Clock &c2)
{
    if((c1.hour==c2.hour)&&(c1.minutes==c2.minutes)&&(c1.seconds==c2.seconds)) cout<<"Hours are equal"<<endl;
    else 
    {
        cout<<"The difference"<<endl;
        cout<<abs(c1.hour-c2.hour)<<" hours"<<endl;
        cout<<abs(c1.minutes-c2.minutes)<<" minutes"<<endl;
        cout<<abs(c1.seconds-c2.seconds)<<" seconds"<<endl;
    }
}
int main()
{
    int choice,choice1;
    Clock cl1,cl2;
    while(true)
    {
        cout<<"Choose option"<<endl;
        cout<<"[1] Enter Data"<<endl;
        cout<<"[2] Get Data"<<endl;
        cout<<"[3] Compare Data"<<endl;
        cout<<"[4] Increment"<<endl;
        cout<<"[5] Exit"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Which object you want to choose"<<endl;
                cout<<"[1] First object"<<endl;
                cout<<"[2] Second object"<<endl;
                cout<<"[3] Both objects"<<endl;
                cin>>choice1;
                if(choice1==1) cin>>cl1;
                if(choice1==2) cin>>cl2;
                if(choice1==3) 
                {
                    cin>>cl1;
                    cin>>cl2;
                }
            break;
            case 2:
                cout<<"Which object you want to choose"<<endl;
                cout<<"[1] First object"<<endl;
                cout<<"[2] Second object"<<endl;
                cout<<"[3] Both objects"<<endl;
                cin>>choice1;
                if(choice1==1) cout<<cl1;
                if(choice1==2) cout<<cl2;
                if(choice1==3)
                {
                    cout<<cl1;
                    cout<<cl2;
                }
            break;
            case 3:
                cl1==cl2;
            break;
            case 4:
                cout<<"Which object you want to increment"<<endl;
                cout<<"[1] First object"<<endl;
                cout<<"[2] Second object"<<endl;
                cin>>choice1;
                if (choice1==1)
                {
                    cout<<"What do you want to increment"<<endl;
                    cout<<"[1] hours"<<endl;
                    cout<<"[2] minutes"<<endl;
                    cout<<"[3] seconds"<<endl;
                    cin>>choice1;
                    if(choice1==1) cl1++;
                    if(choice1==2) cl1.increment_minutes();
                    if(choice1==3) cl1.increment_seconds();
                }
                if (choice1==2)
                {
                    cout<<"What do you want to increment"<<endl;
                    cout<<"[1] hours"<<endl;
                    cout<<"[2] minutes"<<endl;
                    cout<<"[3] seconds"<<endl;
                    cin>>choice1;
                    if(choice1==1) cl2++;
                    if(choice1==2) cl2.increment_minutes();
                    if(choice1==3) cl2.increment_seconds();
                }
            break;
            case 5:
                return EXIT_SUCCESS;
        }
    }
    return EXIT_SUCCESS;
}
