#include <iostream>
#include <string>
using namespace std;
class Employee
{
private:
    string Employee_ID="No_ID_yet";
    string Employee_Name="No_Name_Yet";
    int No_of_Hours_Work=0;
    int Rate_per_Hour=0;
public:
    void SetEmployee_ID()
    {
        cout<<" Employee ID:"<<endl;
        cin>>Employee_ID;
    }
    string GetEmployee_ID()
    {
        return Employee_ID;
    }
    void SetEployee_Name()
    {
        cout<<"Employee Name:"<<endl;
        cin>>Employee_Name;
    }
    string GetEmployee_Name()
    {
        return Employee_Name;
    }
    void set_No_of_Hours_Work()
    {
        cout<<"Number of hours:"<<endl;
        cin>>No_of_Hours_Work;
    }
    int get_No_of_Hours_Work()
    {
        return No_of_Hours_Work;
    }
    void set_Rate_per_Hour()
    {
        cout<<"Rate per hour:"<<endl;
        cin>>Rate_per_Hour;
    }
    int get_Rate_per_Hour()
    {
        return Rate_per_Hour;
    }
    double getTotal_Monthy_Salary()
    {
        return Rate_per_Hour*No_of_Hours_Work*30;
    }
};
int main()
{
    Employee e1;
    cout<<"\t\tMenu"<<endl;
    int choice,n;
while(true)
{
    cout<<"What do you want to do:\n1:\tset data\n2:\tget data"<<endl;
    cin>>choice;
    switch (choice)
    {
        case 1:
            {
                 e1.SetEmployee_ID();
                 e1.SetEployee_Name();
                 e1.set_No_of_Hours_Work();
                 e1.set_Rate_per_Hour();
                 break;
            }
    
        case 2:
            {
                 cout<<"\tThe Employee's ID:"<<e1.GetEmployee_ID()<<endl;
                 cout<<"\tThe Employee's name:"<<e1.GetEmployee_Name()<<endl;
                 cout<<"\tThe Number of hours per day:"<<e1.get_No_of_Hours_Work()<<endl;
                 cout<<"\tThe Rate Per hour:"<<e1.get_Rate_per_Hour()<<endl;
                 cout<<"\tThe Total Monthy Salary:"<<e1.getTotal_Monthy_Salary()<<endl;
                 break;
            }
        
    }
    cout<<"\tDo you want to stop?\n 1 = no"<<endl;
    cin>>n;
    if(n==1) break;
}
    return 0;
}

