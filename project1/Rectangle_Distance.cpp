#include<iostream>
#include<string>
#include<cstring>
using namespace std;
class Rectangle
{
double length,breadth;
public:
    Rectangle(double length=0,double breadth=0)
    {
        setLength(length);
        setBreadth(breadth);
    }
    ~Rectangle(){}
    double getArea()
    {
        return length*breadth;
    }
    void setLength(double length)
    {
        this->length=length;
    }
    void setBreadth(double breadth)
    {
        this->breadth=breadth;
    }
    friend Rectangle operator+(Rectangle& r1, Rectangle& r2);
};
    Rectangle operator+(Rectangle& r1, Rectangle& r2)
    {
        r1.length=r1.length+r2.length;
        r1.breadth=r1.breadth+r2.breadth;
        return r1;
    }
class Distance
{
    float kilometer, meter;
public:
    Distance(float kilometer=0,float meter=0)
    {
        setKilometer(kilometer);
        setMeter(meter);
    }
    void setKilometer(int kilometer)
    {
        this->kilometer=kilometer;
    }
    void setMeter(float meter)
    {
        this->meter=meter;
    }
    void showData()
    {
        cout<<"The Distance is:"<<kilometer*1000+meter<<"m"<<endl;
        cout<<"The distance is:"<<kilometer+meter/1000<<"km"<<endl;
    }
    friend void operator==(Distance& d1, Distance& d2);
};
void operator==(Distance& d1, Distance& d2)
{
    if((d1.kilometer==d2.kilometer)&&(d1.meter==d2.meter))cout<<"Distance of two objects are the same"<<endl;
    else
    {
        cout<<"Distance of two objects are not equal"<<endl;
        cout<<"The difference is:"<<endl;
        float object;
        object=d1.kilometer-d2.kilometer;
        if(object<0) cout<<(-1)*object<<"km"<<endl;
        else cout<<object<<"km"<<endl;
        object=d1.meter-d2.meter;
        if(object<0) cout<<(-1)*object<<"m"<<endl;
        else cout<<object<<"m"<<endl;
    }

}
void Task1()
{
    cout<<"Task 1"<<endl;
    double length, breath,length2,breath2;
    cout<<"Enter Length:"<<endl;
    cin>>length;
    cout<<"Enter Breadth:"<<endl;
    cin>>breath;
    cout<<"Enter Length for 2nd object:"<<endl;
    cin>>length;
    cout<<"Enter Breadth for 2nd object:"<<endl;
    cin>>breath;
    Rectangle r1(length,breath),r2(length2,breath2),r3;
    cout<<"Area of 1st Rectangle is:"<<r1.getArea()<<endl;
    cout<<"Area of 2nd Rectangle is:"<<r2.getArea()<<endl;
    r3=r1+r2;
    cout<<"Area of 1st+2nd Rectangle is:"<<r3.getArea()<<endl;
    cout<<"End of Task 1"<<endl;
}
void Task2()
{
    cout<<"Task 2"<<endl;
    float km1,m1,km2,m2;
    cout<<"Enter km for 1st object"<<endl;
    cin>>km1;
    cout<<"Enter m for 1st object"<<endl;
    cin>>m1;
    cout<<"Enter km for 2nd object"<<endl;
    cin>>km2;
    cout<<"Enter m for 2nd object"<<endl;
    cin>>m2;
    Distance d1(km1,m1),d2(km2,m2);
    d1.showData();
    d2.showData();
    d2==d1;
}
int main()
{ 
    char *choice;
    long int x;
    while(true)
    {
        cout<<"Choose Task:"<<endl;
        cout<<"[1] Task 1"<<endl;
        cout<<"[2] Task 2"<<endl;
        cout<<"[3] Exit"<<endl;
        cin>>choice;
        x=strtol(choice,NULL,10);
        switch (x)
        {
        case 1:
            Task1();
            break;
        case 2:
            Task2();
        break;
        }
        if(x==3) break;
    }
    cout<<"Good Bye!!!"<<endl;
    return EXIT_SUCCESS;
}
