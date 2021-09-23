#include <iostream>
#include <cstring>
#include <fstream>
#include <windows.h>
#include<iomanip>
#include<vector>
#include<string.h>
#include<bits/stdc++.h>


using namespace std;

void insertRecordMenu();//prototyping
void adminMenu();//prototyping
void displayRecord();//prototyping
void deleteRecordMenu();//prototyping
void rechargeBal();
void book();
bool ser(string& h, string& term){
    if(h.find(term) != string::npos){
       return true;
       }
    else{
        return false;
    }
}

bool check(const char *file){//is a function to check if file exists
   ifstream infile(file);
   if(!infile.good()){
   	return false;
   }
   else{
   	return true;
   }
}
string tostr(char* a){
    string s = a;
    return s;
}
string tostr1(int val){
    stringstream ss;
    ss << val;
    string str = ss.str();
    return str;
    }
struct date
{
    int dd,mm,yy;
};
// structure to hold employees information
struct employeeInfo{
    int EID=1;//EMPLOYEE ID
    int age;// EMPLOYEE'S AGE
    string empFullName,email;
    string position;// POSITION OF THE EMPLOYEE IN THE ORGANIZATION i.e.driver,mechanic
    string NID; // NATIONAL ID
    char sex;
    date empDate; // date of employment
    int phoneNumber,driverLicenseNo;
    //function to input and record employee information
void Record_Emp_Info(){
    ifstream setId("employee.txt",ios::app);
        char pos,line[100];
        while(setId.getline(line,100)!= NULL) EID++;
        setId.close();
        system("cls");
        cout<<endl<<"\t"<<"Employee Name: ";
        //cin.ignore();
        getline(cin>>ws, empFullName);//TAKE FULL NAME FROM THE USER
        cout<<"\t"<<"Employee's Age: ";
        cin>>age;
        cout<<"\t"<<"Employee's Sex: ";
        cin>>sex;
        cout<<"\t"<<"Employee's National ID: ";
        cin>>NID;
position:
        cout<<"\t"<<"Employee's Position: ";
        cin>>position;
        if(position=="driver" || position=="Driver")  //CHECK IF EMPLOYEE IS DRIVER
        {
            cout<<"\t"<<"Employee's Driver License Number: ";
            cin>>driverLicenseNo;
            pos='D';
        }
        else if (position=="Teller" || position=="teller")
        {
            pos='T';
        }
        else if (position=="Mechanic" || position=="mechanic")
        {
            pos='M';
        }
        else
        {
            cout<<"\n\t\t"<<"Sorry, there is no employee with that position!! \n\n ";
            goto position;//ONLY HIRE FOR THOSE POSITION ONLY
        }
        cout<<"\t"<<"Employee's Phone Number (0912345678): ";
        cin>>phoneNumber;
        cout<<"\t"<<"Employee's Email: ";
        cin>>email;
        cout<<"\t"<<"Date of employment (dd/mm/yy): ";
        cin>>empDate.dd>>empDate.mm>>empDate.yy;
        ofstream empinfo( "employee.txt", ios::app);
        if(!empinfo.is_open()) {
            cout<<"[-] Unable to open log file.";
        }
        empinfo<<"E"<<pos<<EID<<","<<empFullName<<","<<age<<","<<sex<<","<<NID<<","<<position<<","<<phoneNumber<<","<<email<<","<<empDate.dd<<","<<empDate.mm<<","<<empDate.yy<<"\n";
        empinfo.close();
        cout<<"\t\t\t[+] Successfully added employee\n";
        EID=1;
    }
};
