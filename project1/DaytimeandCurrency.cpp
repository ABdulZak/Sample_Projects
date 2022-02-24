#include <iostream>
#include<string>
using namespace std;
class DayTime
{
private:
        int hour, minute,second;
public:
        DayTime(int h, int m, int s)
        {
                if (h>24)hour=0;
                else hour=h;
                while (m>60)
                {
                        hour +=(m/60);
                        m=m%60;
                }
                minute=m;
                while(s>60)
                {
                        minute +=(s/60);
                        s=s%60;
                }
                second=s;
                while (minute>60)
                {
                        hour +=(minute/60);
                        minute=minute%60;
                }
                minute=minute;
        }
        int getHours() const
        {
                return hour;
        }
        int getMinutes() const
        {
                return minute;
        }
        int getSecond() const
        {
                return second;
        }
        int asSeconds() const
        {
                return (hour*3600+minute*60+second);
        }
        void operator++(int)
        {
                second++;
        }
        void operator--(int)
        {
                minute--;
        }
};
class Dollar
{
private:
        float currency, soums, euro;
public:
        float getDollar()
        {
                return currency;
        }
        float getSoums()
        {
                return (currency*soums);
        }
        float getEuro()
        {
                return (currency*euro);
        }
        void setRates()
        {
                cout<<"1 Dollar in Soums:";
                cin>>soums;
                cout<<"1 Dollar in Euros:";
                cin>>euro;
                cout<<"Enter Dollars:";
                cin>>currency;
        }
        friend void operator<<(ostream &out, Dollar &d);
};
void operator<<(ostream &out, Dollar &d)
{
        out<<"<<<Dollar :=: "<< d.getDollar()<<">>>"<<endl;
                out<<"<<<Dollar in Soums :=: "<< d.getSoums()<<">>>"<<endl;
                out<<"<<<Dollar in Euros :=: "<<d.getEuro()<<">>>"<<endl;
}
void task1()
{
        int choice,hour,minute,second;
        cout<<"Enter Hours:";
        cin>>hour;
        cout<<"Enter Minutes:";
        cin>>minute;
        cout<<"Enter Seconds:";
        cin>>second;
        DayTime dt(hour,minute,second);
        while (true)
        {
                cout<<"What do you want to display?"<<endl;
                cout<<"\t 1. Display Time"<<endl;
                cout<<"\t 2. Display Time In Seconds"<<endl;
                cout<<"\t 3. Increment Seconds"<<endl;
                cout<<"\t 4. Decrement Minutes"<<endl;
                cout<<"\t 5. Exit"<<endl;
                cin>>choice;
                switch (choice)
                {
                case 1:
                        cout<<dt.getHours()<<":"<<dt.getMinutes()<<":"<<dt.getSecond()<<endl; 
                        break;
                case 2:
                        cout<<"Seconds:"<<dt.asSeconds()<<endl;
                        break;
                case 3:
                        dt++;
                        break;
                case 4:
                        dt--;
                        break;
                }
                if(choice==5) break;
        }
}
void task2()
{
        Dollar d;
        d.setRates();
        cout << d;
}
int main() {
        int task_choice;
        cout<<"MENU\n\nEnter the task"<<endl;
        cout<<"[1] Task 1"<<endl;
        cout<<"[2] Task 2"<<endl;
        cin>>task_choice;
        switch (task_choice)
        {
        case 1:
                task1();
        break; 
        case 2:
                task2();
        break;
        }
        cout<<"Good bye!\n"<<endl;
        system("pause");
        return 0;
}
