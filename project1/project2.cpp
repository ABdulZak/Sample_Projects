#include <iostream>
#include <string>
using namespace std;
class Student
{
private:
    string Student_ID;
    string Student_Name;
    double OOP2_Score;
    double Maths_Score;
    double English_Score;
    double Total_Score;
    double ctotal()
    {
        double sum;
        sum= OOP2_Score+Maths_Score+English_Score;
        return sum;
    }    
public:
    void Takedata()
    {
        cout<<"Enter the ID of the student:"<<endl;
        cin>>Student_ID;
        cout<<"Enter student name:"<<endl;
        cin>>Student_Name;
        cout<<"Score of OOP:"<<endl;
        cin>> OOP2_Score;
        cout<<"Score of Maths:"<<endl;
        cin>>Maths_Score;
        cout<<"Score of English:"<<endl;
        cin>>English_Score;
        Total_Score=ctotal();
    }
    void Showdata()
    {
        cout<<"ID:"<<Student_ID<<endl;
        cout<<"Name:"<<Student_Name<<endl;
        cout<<"OOP:"<<OOP2_Score<<endl;
        cout<<"Maths:"<<Maths_Score<<endl;
        cout<<"English:"<<English_Score<<endl;
        cout<<"Total:"<<Total_Score<<endl;
    }
};
int main()
{
    Student s1;
    s1.Takedata();
    s1.Showdata();
    return 0;
}    
