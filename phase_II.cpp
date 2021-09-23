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

struct Booking {//TICKET BOOKING STRUCTURE
    int TID=1;//TICKET ID
    string BID;//BUS ID
    string RID;//ROUTE ID
    int seatNum=0;//seat number
    string price;//PRICE OF TRAVEL
    string CID;//CUSTOMER ID
    string EID;//EMPLOYEE (TELLER) ID
    string from, to,distance, name;
    date depdate;//DATE OF DEPARTURE
    void setBooking(string custId){
        CID=custId;
        string id, temp;
        int spaces[]={20,5,23,13,10,12,10}, cou=0,counter=0,place=0;
        fstream information;
        information.open("route.txt", ios::in);
        if (!information.is_open()) {
            system("cls");
            cout<<"       [-] Log file is not found";
            system("pause");
        }
        ifstream setId("booking.txt",ios::app);
        char pos,line[100],line2[100];
        while(setId.getline(line,100)!= NULL) TID++;
        setId.close();
        cout<<setfill(' ');//FILL THE TABLES EMPTY SPACE WITH THE SPECIFIED CHARACTER
        cout<<"\t|"<<setw(13)<<"Route ID |"<<setw(13)<<"Bus ID     |"<<setw(15)<<" Start |"<<setw(13)<<" End |"<<setw(5)<<" Distance |"<<setw(12)<<" Price|"<<setw(17)<<" Available Seats|\n";
        fstream myFile;
        myFile.open("route.txt", ios::in);

        while(information.getline(line, 100))
        {
            char *ptr = strtok(line,",");
            while(ptr != NULL){
                cout<<setw(spaces[cou])<<ptr;
                ptr = strtok(NULL,",");
                cou++;
            }
            cou=0;
            cout<<endl;
        }
        information.close();
        cout<<endl<<"\t enter the route id to buy a ticket for that route: ";
        cin>>id;
        ifstream takedata("route.txt");
        cou=0;
        while(takedata.getline(line2, 100)) {
                char *ptr1=strtok(line2,",");
                temp=ptr1;
                if (temp==id) break;
                cou++;
        }
        while(takedata.getline(line2, 100)) {
                if (counter==cou) {
                char *ptr=strtok(line2,",");
                while(ptr != NULL){
                        cout<<ptr;
                        if (place==0) RID=ptr;
                        if (place==1) BID=ptr;
                        if (place==2) EID=ptr;
                        if (place==3) from=ptr;
                        if (place==4) to=ptr;
                        if (place==5) distance=ptr;
                        if (place==6) price=ptr;
                place++;
                ptr=strtok(NULL,",");
                }
                counter++;
        }
        place=0;
        cou=0;
        counter=0;
        ifstream custName("customer.txt");
        while(custName.getline(line2, 100)) {
                char *ptr1=strtok(line2,",");
                temp=ptr1;
                if (temp==custId) break;
                cou++;
        }
        while(custName.getline(line2, 100)) {
                if (counter==cou) {
                char *ptr=strtok(line2,",");
                while(ptr != NULL){
                        if (place==1) name=ptr;
                place++;
                ptr=strtok(NULL,",");
                }
                counter++;
        }
        }
        cout<<" \n\t________________________________________________________\n";
        cout<<"\t|                     BUS TICKET                        |\n";
        cout<<"\t|-------------------------------------------------------|\n";
        cout<<"\t|"<<setw(14)<<"Ticket ID: T"<<setw(7)<<TID<<setw(36)<<" |\n";
        cout<<"\t|"<<setw(9)<<"Bus ID:"<<setw(7)<<BID<<setw(17)<<"No of Seat:"<<seatNum<<setw(21)<<" |\n";
        cout<<"\t|"<<setw(8)<<"name: "<<setw(17)<<name<<setw(32)<<"|\n";
        cout<<"\t|"<<setw(14)<<"Customer ID:"<<setw(7)<<CID<<setw(36)<<" |\n";
        cout<<"\t|"<<setw(9)<<"From:"<<setw(15)<<from<<"    To:"<<setw(15)<<to<<setw(11)<<" |\n";
        cout<<"\t|"<<setw(11)<<"Route ID:"<<setw(7)<<RID<<setw(39)<<" |\n";
        cout<<"\t|"<<setw(9)<<"Price: "<<setw(12)<<price<<setw(36)<<"|\n";


cout<<"\t|"<<setw(8)<<"Date: "<<setw(8)<<depdate.dd<<"/"<<depdate.mm<<"/"<<depdate.yy<<setw(33)<<"|\n";
        cout<<"\t|_______________________________________________________|\n";
        ofstream binfo( "customer.txt", ios::app);
        if(!binfo.is_open()) {
            cout<<"[-] Unable to open log file.";
        }
        binfo<<"T"<<TID<<"\n";
        binfo.close();
        TID=1;
    }
    }
};

void customerVerify () {
    Booking book;
    char line[100];
    string id, temp;
    bool custId=false;
    ifstream cusId("customer.txt",ios::app);
        while(cusId.getline(line, 100)) {
                char *ptr=strtok(line,",");
            ofstream registr("temp.txt",ios::app);
            registr<<ptr<<"\n";
        ptr = strtok(NULL,",");
        }
        cusId.close();
        cout<<endl<<"\t enter your customer id to book a ticket: ";
        cin>>id;
        ifstream registr("temp.txt");
        while (registr.getline(line,100)) {
            temp=line;
            if(id==temp) custId=true;
        }
        registr.close();
        if (custId==true) {
            book.setBooking(id);
        }
        else {
            cout<<"\t\t\n[!] your id is not registered, please register at our office [!]";
        }
        ofstream clrregistr("temp.txt",ios::trunc);
        clrregistr.close();
}

void displayEmp()  //Will display employee
{
    char line[300];
    fstream information;
    information.open("employee.txt", ios::in);
    if (!information.is_open()) {
        system("cls");
        cout<<"       [-] Log file is not found";
        system("pause");
        goto empMenu;
    }

    char command;
empMenu://SMALL MENU FOR DISPLAYING BUS INFORMATION
    cout<<"\tHow would you like to display bus record"<<endl;
    cout<<"       ________________________________________________________\n";
    cout<<"       | 1. Display all employee record                        |\n";
    cout<<"       | 2. Search employee                                    |\n";
    cout<<"       | 3. exit                                               |\n";
    cout<<"       |-------------------------------------------------------|\n";
    cin>>command;//INPUT THE COMMAND FROM USER
    int spaces[]={11,10,10,25,10,12,10,10,3,3,20,15}, cou=0;
   if(command=='1'){
        //TABLE THAT DISPLAY EVERY BUS RECORD
        cout<<setfill(' ');//FILL THE TABLES EMPTY SPACE WITH THE SPECIFIED CHARACTER
        cout<<setw(12)<<"Employee ID |"<<setw(10)<<"Age"<<setw(10)<<"| Full name |"<<setw(20)<<" Email |"<<setw(5)<<" Position |"<<setw(12)<<" National ID|"<<setw(12)<<" sex|"<<setw(16)<<" date|"<<setw(16)<<" Phone|"<<setw(16)<<" License|\n";
        char line[300];
        fstream myFile;
        myFile.open("employee.txt", ios::in);

        while(information.getline(line, 300))
        {
            char *ptr = strtok(line,",");
            while(ptr != NULL){
                cout<<setw(spaces[cou])<<ptr;
                ptr = strtok(NULL,",");
                cou++;
            }
            cou=0;
            cout<<endl;
        }
        system("pause");
   }
    else if(command=='2'){
        string ser;
        cout<<"[+] Enter the search term, it can be name,ID, email or any other attribute: ";
        cin>>ser;
        char line[300];
        fstream myFile;
        myFile.open("employee.txt", ios::in);
        cout<<setfill(' ');

        cout<<setw(12)<<"Employee ID |"<<setw(10)<<"Age"<<setw(10)<<"| Full name |"<<setw(20)<<" Email |"<<setw(5)<<" Position |"<<setw(12)<<" National ID|"<<setw(12)<<" sex|"<<setw(16)<<" date|"<<setw(16)<<" Phone|"<<setw(16)<<" License|\n";
        while(myFile.getline(line, 300))
        {
            string hol= tostr(line);
            if(hol.find(ser) != string::npos){

                char *ptr = strtok(line,",");
                while(ptr != NULL){
                   cout<<setw(spaces[cou])<<ptr;
                    ptr = strtok(NULL,",");
                    cou++;
                }
                cou=0;
                cout<<endl;
            }

        }
        system("pause");
    }

}
void displayBus()  //TAKE BUS STUCTURE ARRAY AND ITS SIZE AS PARAMETER
{
    char line[200];
    fstream information;
    information.open("bus.txt", ios::in);
    if (!information.is_open()) {
        system("cls");
        cout<<"       [-] Log file is not found";
        system("pause");
        goto empMenu;
    }

    char command;
empMenu://SMALL MENU FOR DISPLAYING BUS INFORMATION
    cout<<"\tHow would you like to display bus record"<<endl;
    cout<<"       ________________________________________________________\n";
    cout<<"       | 1. Display all bus record                             |\n";
    cout<<"       | 2. Search using bus ID                                |\n";
    cout<<"       | 3. exit                                               |\n";
    cout<<"       |-------------------------------------------------------|\n";
    cin>>command;//INPUT THE COMMAND FROM USER
    int spaces[6]={11,15,20,13,10,12,}, cou=0;
   if(command=='1'){
        //TABLE THAT DISPLAY EVERY BUS RECORD
        cout<<setfill(' ');//FILL THE TABLES EMPTY SPACE WITH THE SPECIFIED CHARACTER
        cout<<"\t|"<<setw(12)<<"Employee ID |"<<setw(12)<<"Bus ID     |"<<setw(15)<<" Model |"<<setw(13)<<" Color |"<<setw(5)<<" Odometer |"<<setw(12)<<" Seats|\n";
        char line[100];
        fstream myFile;
        myFile.open("bus.txt", ios::in);

        while(information.getline(line, 100))
        {
            char *ptr = strtok(line,",");
            while(ptr != NULL){
                cout<<setw(spaces[cou])<<ptr;
                ptr = strtok(NULL,",");
                cou++;
            }
            cou=0;
            cout<<endl;
        }
        system("pause");
   }
    else if(command=='2'){
        string ser;
        cout<<"[+] Enter the search term, it can be name,ID, color or any other attribute: ";
        cin>>ser;
        char line[100];
        fstream myFile;
        myFile.open("bus.txt", ios::in);
        cout<<setfill(' ');

        cout<<"\t|"<<setw(12)<<"Employee ID |"<<setw(12)<<"Bus ID     |"<<setw(15)<<" Model |"<<setw(13)<<" Color |"<<setw(5)<<" Odometer |"<<setw(12)<<" Seats|\n";
        while(information.getline(line, 100))
        {
            string hol= tostr(line);
            if(hol.find(ser) != string::npos){

                char *ptr = strtok(line,",");
                while(ptr != NULL){
                   cout<<setw(spaces[cou])<<ptr;
                    ptr = strtok(NULL,",");
                    cou++;
                }
                cou=0;
                cout<<endl;
            }

        }
        system("pause");
    }
}

void displayRoute()  //TAKE BUS STUCTURE ARRAY AND ITS SIZE AS PARAMETER
{
    char line[200];
    fstream information;
    information.open("route.txt", ios::in);
    if (!information.is_open()) {
        system("cls");
        cout<<"       [-] Log file is not found";
        system("pause");
        goto empMenu;
    }

    char command;
      empMenu://SMALL MENU FOR DISPLAYING ROUTES INFORMATION
      cout<<"\tHow would you like to display route record"<<endl;
      cout<<"       ________________________________________________________\n";
      cout<<"       | 1. Display all routes record                          |\n";
      cout<<"       | 2. Search using routes ID                             |\n";
      cout<<"       | 3. exit                                               |\n";
      cout<<"       |-------------------------------------------------------|\n";
      cin>>command;//INPUT THE COMMAND FROM USER
    int spaces[]={20,5,23,13,10,12,10}, cou=0;
   if(command=='1'){
        //TABLE THAT DISPLAY EVERY BUS RECORD
        cout<<setfill(' ');//FILL THE TABLES EMPTY SPACE WITH THE SPECIFIED CHARACTER
        cout<<"\t|"<<setw(13)<<"Route ID |"<<setw(13)<<"Bus ID     |"<<setw(15)<<" Start |"<<setw(13)<<" End |"<<setw(5)<<" Distance |"<<setw(12)<<" Price|"<<setw(17)<<" Available Seats|\n";
        char line[100];
        fstream myFile;
        myFile.open("route.txt", ios::in);

        while(information.getline(line, 100))
        {
            char *ptr = strtok(line,",");
            while(ptr != NULL){
                cout<<setw(spaces[cou])<<ptr;
                ptr = strtok(NULL,",");
                cou++;
            }
            cou=0;
            cout<<endl;
        }
        system("pause");
   }
    else if(command=='2'){
        string ser;
        cout<<"[+] Enter the search term, it can be start ,ID, destination or any other attribute: ";
        cin>>ser;
        char line[100];
        fstream myFile;
        myFile.open("route.txt", ios::in);
        cout<<setfill(' ');

        cout<<"\t|"<<setw(13)<<"Route ID |"<<setw(13)<<"Bus ID     |"<<setw(15)<<" Start |"<<setw(13)<<" End |"<<setw(5)<<" Distance |"<<setw(12)<<" Price|"<<setw(17)<<" Available Seats|\n";
        while(information.getline(line, 100))
        {
            string hol= tostr(line);
            if(hol.find(ser) != string::npos){

                char *ptr = strtok(line,",");
                while(ptr != NULL){
                   cout<<setw(spaces[cou])<<ptr;
                    ptr = strtok(NULL,",");
                    cou++;
                }
                cou=0;
                cout<<endl;
            }

        }
        system("pause");
    }
}

void displayCus()  //TAKE CUSTOMER STRUCTURE ARRAY AND ITS SIZE AS PARAMETER
{
        char line[200];
    fstream information;
    information.open("customer.txt", ios::in);
    if (!information.is_open()) {
        system("cls");
        cout<<"       [-] Log file is not found";
        system("pause");
        goto empMenu;
    }
        char command;
empMenu://SMALL MENU FOR DISPLAYING CUSTOMER INFORMATION
    cout<<"\tHow would you like to display customer record"<<endl;
    cout<<"       ________________________________________________________\n";
    cout<<"       | 1. Display all customer record                        |\n";
    cout<<"       | 2. Search using customer ID                           |\n";
    cout<<"       | 3. exit                                               |\n";
    cout<<"       |-------------------------------------------------------|\n";
    cin>>command;//INPUT THE COMMAND FROM USER
    int spaces[]={11,30,20,13,4,12,10,10,10,10,10}, cou=0;
    if(command=='1'){
       //TABLE THAT DISPLAY EVERY customer RECORD
        char order;
        cout<<"[+] do you want to display in ascending or descending order(a/d)?";
a:
        cin>>order;
        if(order=='a'||order=='A'||order=='d'||order=='D')
        {
            if(order=='a'||order=='A')
            {
                cout<<setfill(' ');//FILL THE TABLES EMPTY SPACE WITH THE SPECIFIED CHARACTER
                cout<<"\n\t__________________________________________________________________________________________\n";
                cout<<"\t|"<<setw(12)<<"Customer ID |"<<setw(30)<<"Customer name     "<<setw(10)<<"| Age |"<<setw(13)<<" Balance |"<<setw(5)<<" Sex |"<<setw(12)<<" Traveling miles|\n";

                char line[100];
                fstream myFile;
                myFile.open("customer.txt", ios::in);

                while(information.getline(line, 100))
                {
                    char *ptr = strtok(line,",");
                    while(ptr != NULL){
                        cout<<setw(spaces[cou])<<ptr;
                        ptr = strtok(NULL,",");
                        cou++;
                    }
                    cou=0;
                    cout<<endl;
                }
                cout<<"\n\t|________________________________________________________________________________________|";
                system("pause");

                }

            else if( order=='d'|| order=='D'){
                cout<<setfill(' ');//FILL THE TABLES EMPTY SPACE WITH THE SPECIFIED CHARACTER
                cout<<"\n\t__________________________________________________________________________________________\n";
                cout<<"\t|"<<setw(12)<<"Customer ID |"<<setw(30)<<"Customer name     "<<setw(10)<<"| Age |"<<setw(13)<<" Balance |"<<setw(5)<<" Sex |"<<setw(12)<<" Traveling miles|\n";
                    std::string line;
                    std::vector<std::string> v;
                    std::ifstream file("customer.txt");
                    while(getline(file, line)){
                        v.push_back(line);
                    }
                    int cou=0;
                    for(int i = v.size()-1; i>=0; i--){
                        char line[v[i].length()+1];
                        strcpy(line, v[i].c_str());
                        char *ptr = strtok(line,",");
                        while(ptr != NULL){
                            cout<<setw(spaces[cou])<<ptr;
                            ptr = strtok(NULL,",");
                            cou++;
                        }
                        cou=0;
                        cout<<endl;
                    }
                system("pause");
                cout<<"\n\t|________________________________________________________________________________________|";
                }
            }
        else
        {
              cout<<"[-]incorrect input please chose from ascending and descending(a/d)";
              goto a;
        }
    }

    else if(command=='2'){
        string ser;
        cout<<"[+] Enter the search term, it can be name,ID, age or any other attribute: ";
        cin>>ser;
        char line[100];
        fstream myFile;
        myFile.open("customer.txt", ios::in);
        cout<<setfill(' ');
         cout<<"\n\t__________________________________________________________________________________________\n";
                cout<<"\t|"<<setw(12)<<"Customer ID |"<<setw(30)<<"Customer name     "<<setw(10)<<"| Age |"<<setw(13)<<" Balance |"<<setw(5)<<" Sex |"<<setw(12)<<" Traveling miles|\n";
        while(information.getline(line, 100))
        {
            string hol= tostr(line);
            if(hol.find(ser) != string::npos){

                char *ptr = strtok(line,",");
                while(ptr != NULL){
                   cout<<setw(spaces[cou])<<ptr;
                    ptr = strtok(NULL,",");
                    cou++;
                }
                cou=0;
                cout<<endl;
            }

        }
        system("pause");
    }

}
void delCust(string id){//This will delete a customer from the file
    char line[100];
    int cou=0;
    fstream myFile;
    myFile.open("customer.txt", ios::in);
    fstream temp("tmp.txt", ios::out);
    while(myFile.getline(line, 100))
    {
        char *ptr = strtok(line,",");
        bool stat=true;
        while(ptr != NULL){

            if(cou==0){
                if(id== tostr(ptr)){
                    stat=false;
                }
            }
            if(stat==true){
                temp<<ptr;
                if(cou!=5){
                 temp<<",";
                }
            }
            ptr = strtok(NULL,",");
            cou++;
        }
        if(stat==true){
            temp<<"\n";
        }
        stat=true;
        cou=0;
        cout<<endl;
    }
    temp.close();
    myFile.close();
    ofstream fasa("customer.txt");
    fasa.close();
    ofstream ne("customer.txt");
    string hol;
    ifstream rr("tmp.txt");
    while(rr.getline(line, 100)){
        ne<<line<<"\n";
    }
    system("pause");
}

