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

struct bus{
    int BID=1; //BUS ID
    string model; //BUS MODEL
    string color; //BUS COLOR
    string license;//BUS LICENSE
    int distanceTraveled;//DISTANCE THE BUS TRAVELED
    int MID;// MAINTAINANCE ID
    int seats;//SEATS ON THE BUS
    bool assignedDriver=false, driverAva=true;
    void inputBus(){
        int counter=1,lineCounter=1;
        string temp,temp2;
        ifstream setId("bus.txt",ios::app);
        char line[100],line2[100];
        while(setId.getline(line,100)!= NULL) BID++;
        setId.close();
        ifstream empId("employee.txt",ios::app);
        while(empId.getline(line, 100)) {
        char *ptr = strtok(line,",");
        if (ptr[1] == 'D') {
            ofstream registr("temp.txt",ios::app);
            registr<<ptr<<"\n";
            }
        ptr = strtok(NULL,",");
        }
        empId.close();
        cout<<"\n[+] Enter the bus model: ";
        cin>>model;
        cout<<"[+] Enter the bus color: ";
        cin>>color;
        cout<<"[+] Enter the distance traveled by bus: ";
        cin>>distanceTraveled;
        cout<<"[+] Enter the number of people that the bus can support: ";
        cin>>seats;
        ofstream busInfo( "bus.txt", ios::app);
        if(!busInfo.is_open()) {
            cout<<"[-] Unable to open log file.";
        }
        driverAva=true;
        ifstream driverId("temp.txt",ios::app);
        while(driverId.getline(line2, 100)){
                driverAva=true;
                ifstream assignedEmpId("bus.txt",ios::app);
                while(assignedEmpId.getline(line, 100)) {
                    char *ptr = strtok(line,",");
                    while(ptr != NULL){
                       if (counter == 2) {
                           temp=ptr;
                           temp2=line2;
                           if(temp==temp2) driverAva=false;
                          }
                       ptr = strtok(NULL,",");
                       counter++;
                       }
                       counter=1;
                     }
                    if (driverAva==true) {
                       busInfo<<"B"<<BID<<","<<line2<<","<<model<<","<<color<<","<<distanceTraveled<<","<<seats<<"\n";
                       cout<<"\t\t\t[+] Successfully added bus information and assigned driver";
                       assignedDriver=true;
                       break;
                        }
                    }
        driverId.close();
        if (assignedDriver==false) {
            busInfo<<"B"<<BID<<","<<"N/A"<<","<<model<<","<<color<<","<<distanceTraveled<<","<<seats<<"\n";
            busInfo.close();
            cout<<"\t\t\t[+] Successfully added bus information and could not assign driver";
           }
        BID=1;
        ofstream clearRegister("temp.txt",ios::trunc);
        clearRegister.close();
        assignedDriver=false;
    }
};

struct customer{
    int CID=1; //CUSTOMER ID
    string name;// CUSTOMER NAME
    int age; //AGE OF THE CUSTOMER
    string identificationCard; //ID NUMBER OF THE CUSTOMER
    int balance=0; //THE BALANCE OF THE CUSTOMER
    char sex;//THE GENDER OF THE CUSTOintMER
    int travelDistance; //THE DISTANCE THAT THE CUSTOMER COVERED BY THE COMPANY SERVICE
    //FUNCTION TO INPUT AND RECORD EMPLOYEE INFORMATION
    void inputCustomer(){
        ifstream setId("customer.txt",ios::app);
        char pos,line[100];
        while(setId.getline(line,100)!= NULL) CID++;
        setId.close();
        system("cls");
        cout<<"\n\t Enter the customer name: ";
        cin.ignore();
        getline(cin, name);//INPUT FULL NAME OF THE CUSTOMER
        cout<<"\t Enter the customer age: ";
        cin>>age;
        balance=0;
        cout<<"\t Enter the customer's sex: ";
        cin>>sex;
        cout<<"\t Enter the customer traveled Distance: ";
        cin>>travelDistance;
        ofstream cusinfo( "customer.txt", ios::app);
        if(!cusinfo.is_open()) {
            cout<<"[-] Unable to open log file.";
        }
        cusinfo<<"C"<<CID<<","<<name<<","<<age<<","<<balance<<","<<sex<<","<<travelDistance<<"\n";
        cusinfo.close();
        cout<<"\t\t\t[+] Successfully added customer\n";
        CID=1;
    }
};

struct Route{
   int BID; //BUS ID
   int RID=1; // ROUTE ID
   string start; //STARTING POINT OR DEPARTURE
   string End=" ";  // END POINT OR DESTINATION
   float distance; // DISTANCE OF TRAVEL
   float price; //PRICE OF TRAVEL
   bool assignedBus=false, driverAva=true;
   void inputroute () {
        int counter=1,cou=0;
        string temp,temp2,temp3;
        ifstream setId("route.txt",ios::app);
        char pos,line[100],line2[100];
        while(setId.getline(line,100)!= NULL) RID++;
        setId.close();
        ifstream busID("bus.txt",ios::app);
        while(busID.getline(line, 100)) {
        char *ptr = strtok(line,",");
        while (ptr!=NULL) {
            if (cou==2) break;
            ofstream registr("temp.txt",ios::app);
            registr<<ptr;
            if (cou==0) registr<<",";
            else registr<<"\n";
            ptr = strtok(NULL,",");
            cou++;
            }
        cou=0;
        }
        busID.close();
        cout<<"\n Enter departure or the Starting point: ";
        cin.ignore();
        getline(cin>>ws,start);   //INPUT FOR DEPARTURE
        cout<<"Enter destination or the  End point: ";
        cin.ignore();
        getline(cin>>ws,End);   //INPUT FOR DESTINATION
        cout<<"Enter distance in kilometers: ";
        cin>>distance;
        cout<<"Enter price: ";
        cin>>price;
        ofstream routeInfo( "routeRec.txt", ios::app);
        if(!routeInfo.is_open()) {
            cout<<"[-] Unable to open log file.";
        }
        driverAva=true;
        ifstream registr("temp.txt",ios::app);
        while(registr.getline(line2, 100)){
                cout<<"##"<<line2<<"##\n";
                temp3=line2;
                driverAva=true;
                char *ptr1 = strtok(line2,",");
                ifstream assignedBusId("route.txt",ios::app);
                while(assignedBusId.getline(line, 100)) {
                    char *ptr = strtok(line,",");
                    while(ptr != NULL){
                       if (counter == 2) {
                           temp=ptr;
                           temp2=ptr1;
                           if(temp==temp2) driverAva=false;
                          }
                       ptr = strtok(NULL,",");
                       counter++;
                       }
                       counter=1;
                     }
                    if (driverAva==true) {
                        ptr1=line2;
                       routeInfo<<"R"<<RID<<","<<temp3<<","<<start<<","<<End<<","<<distance<<","<<price<<"\n";
                       cout<<"\t\t\t[+] Successfully added route information and assigned bus";
                       assignedBus=true;
                       break;
                        }
                        ptr1 = strtok(NULL,",");
                    }
        registr.close();
        if (assignedBus==false) {
            routeInfo<<"R"<<RID<<","<<"N/A"<<","<<"N/A"<<","<<start<<","<<End<<","<<distance<<","<<price<<"\n";
            routeInfo.close();
            cout<<"\t\t\t[+] Successfully added route information and could not assign bus";
           }
        RID=1;
        ofstream clearRegister("temp.txt",ios::trunc);
        clearRegister.close();
        assignedBus=false;
   }
};
