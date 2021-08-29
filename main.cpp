#include <iostream>
#include <cstring>
using namespace std;

struct date
{
    int dd,mm,yy;
};
// structure to hold employees information
struct employeeInfo
{
    int empId=100000,age;
    string empFullName, position,email,nationalId; // position of the employee in the organization i.e.driver,mechanic
    char sex;
    date empDate; // date of employment
    int phoneNumber,driverLicenseNo;

    //function to input and record employee information
void Record_Emp_Info(employeeInfo empData){
    cout<<"\t\t"<<"Employee Record Input Portal"<<endl;
    record:
        cout<<endl<<"empId: "<<empData.empId;
        cout<<endl<<"\t"<<"Employee Name: ";
        cin.ignore();
        getline(cin, empData.empFullName);
        cout<<"\t"<<"Employee's Age: ";
        cin>>empData.age;
        cout<<"\t"<<"Employee's Sex: ";
        cin>>empData.sex;
        cout<<"\t"<<"Employee's National ID: ";
        cin>>empData.nationalId;
        cout<<"\t"<<"Employee's Position: ";
        cin>>empData.position;
            if(empData.position=="driver")
            {
            cout<<"\t"<<"Employee's Driver License Number: ";
            cin>>empData.driverLicenseNo;
            }
        cout<<"\t"<<"Employee's Phone Number (0912345678): ";
        cin>>empData.phoneNumber;
        cout<<"\t"<<"Employee's Email: ";
        cin>>empData.email;
        cout<<"\t"<<"Date of employment (dd/mm/yy): ";
        cin>>empData.empDate.dd>>empData.empDate.mm>>empData.empDate.yy;
        empData.empId++;
        char button;
        cout<<endl<<"Would you like to record another employee information? (y/n) : ";
        cin>>button;
            if(button=='y'|| button=='Y')
                {
                    goto record;
                }
            else if(button=='n'||button=='N')
                {
                    exit;
                }
}
};
int main(){
employeeInfo empData;
empData.Record_Emp_Info(empData);

return 0;
}
