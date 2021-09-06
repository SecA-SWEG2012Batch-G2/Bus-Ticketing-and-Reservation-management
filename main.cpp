#include <iostream>
#include <cstring>
using namespace std;

void insertRecordMenu(); //prototyping
void adminMenu(); //prototyping
struct date{
	int hour, dd, mm, yy;
};
// structure to hold employees information
struct employeeInfo
{
    int EID=100000;//EMPLOYEE ID
    int age;// EMPLOYEE'S AGE
    string empFullName,email;
    string position;// POSITION OF THE EMPLOYEE IN THE ORGANIZATION i.e.driver,mechanic
    string NID; // NATIONAL ID
    char sex;
    date empDate; // date of employment
    int phoneNumber,driverLicenseNo;

    //function to input and record employee information
void Record_Emp_Info(int empCounter){//TAKE EMPLOYEE COUNT TO AUTOMATICALLY ASSIGN EMPLOYEE ID
    cout<<"\t\t"<<"Employee Record Input Portal"<<endl;
	record:
        cout<<endl<<"\t"<<"Employee Name: ";
        cin.ignore();
        getline(cin, empFullName);//TAKE FULL NAME FROM THE USER
        cout<<"\t"<<"Employee's Age: ";
        cin>>age;
        cout<<"\t"<<"Employee's Sex: ";
        cin>>sex;
        cout<<"\t"<<"Employee's National ID: ";
        cin>>NID;
        position:
        cout<<"\t"<<"Employee's Position: ";
        cin>>position;
            if(position=="driver" || position=="Driver") {//CHECK IF EMPLOYEE IS DRIVER
               cout<<"\t"<<"Employee's Driver License Number: ";
               cin>>driverLicenseNo;
               EID=1000+empCounter;//DRIVER'S ID ALWAYS START WITH 1000
             }
             else if (position=="Teller" || position=="teller") {
               EID=2000+empCounter;//TELLER'S ID ALWAYS START WITH 2000
             }
             else if (position=="Mechanic" || position=="mechanic") {
                EID=3000+empCounter;//MECHANIC'S ID ALWAYS START WITH 3000
             }
             else {
                cout<<"\n\t\t"<<"Sorry, there is no employee with that position!! \n \n ";
                goto position;//ONLY HIRE FOR THOSE POSITION ONLY
             }
        cout<<"\t"<<"Employee's Phone Number (0912345678): ";
        cin>>phoneNumber;
        cout<<"\t"<<"Employee's Email: ";
        cin>>email;
        cout<<"\t"<<"Date of employment (dd/mm/yy): ";
        cin>>empDate.dd>>empDate.mm>>empDate.yy;
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
//FUNCTION TO DISPLAY EMPLOYEE INFORMATION
void displayEmp(employeeInfo information[],int info_size) {//TAKE EMPLOYEE STRUCTURE ARRAY AND ITS SIZE AS PARAMETER
        char command;
        empMenu://SMALL MENU FOR DISPLAYING EMPLOYEE INFORMATION
      cout<<"\tHow would you like to display employee record"<<endl;
      cout<<"       ________________________________________________________\n";
      cout<<"       | 1. Display all employee record                        |\n";
      cout<<"       | 2. Search using employee ID                           |\n";
      cout<<"       | 3. exit                                               |\n";
      cout<<"       |-------------------------------------------------------|\n";
      cin>>command;//INPUT THE COMMAND FROM USER
      switch (command) {//SWITCH USED TO EXECUTE SPECIFIC COMMANDS
        case '1':
                //TABLE THAT DISPLAY EVERY EMPLOYEE RECORD
                cout<<setfill(' ');
                cout<<"\t|"<<setw(12)<<"Employee ID |"<<setw(30)<<"Employee name     "<<setw(10)<<"| Age |"<<setw(13)<<" Position |"<<setw(5)<<" Sex |"<<setw(12)<<" National ID|";
            for (int x=0; x<info_size; x++) {
                cout<<endl<<"\t|"<<setw(9)<<information[x].EID<<setw(4)<<"  |"<<setw(33)<<information[x].empFullName<<"|"<<setw(4)<<information[x].age<<" |"<<setw(12)<<information[x].position<<"|"<<setw(5)<<information[x].sex<<"|"<<setw(12)<<information[x].NID<<"|";
            }
            break;
        case '2':
            int searchId;
            searchEmp:
                //TABLE THAT DISPLAY DISIRED (SEARCHED) EMPLOYEE'S INFORMATION
            cout<<"Input employee id: ";
            cin>>searchId;
            for (int x=0; x<info_size; x++) {
                if (information[x].EID == searchId) {
                    cout<<"\t|"<<setw(12)<<"Employee ID |"<<setw(30)<<"Employee name     "<<setw(10)<<"| Age |"<<setw(13)<<" Position |"<<setw(5)<<" Sex |"<<setw(12)<<" National ID|";
                    cout<<endl<<"\t|"<<setw(9)<<information[x].EID<<setw(4)<<"  |"<<setw(33)<<information[x].empFullName<<"|"<<setw(4)<<information[x].age<<" |"<<setw(12)<<information[x].position<<"|"<<setw(5)<<information[x].sex<<"|"<<setw(12)<<information[x].NID<<"|";
                    break;
                }
                if (x==info_size-1)       cout<<"Employee id not found";
            }
            searchAgain:
            cout<<"\n Do you want to search again (y/n)?";//PROPT THE USER TO SEARCH AGAIN
            cin>>command;
            if (command == 'y' || command=='Y' || command=='n' || command=='N') {
                if (command=='y' ||command=='Y') goto searchEmp;
            }
            else {
                cout<<"Wrong key \n";//LOOP BACK TO PROPT IF WRONG KEY IS PRESSED
                goto searchAgain;
            }
            break;
        case '3':
            break;
        default:
            cout<<"Wrong key \n";//LOOP BACK TO PROPT IF WRONG KEY IS PRESSED
            goto empMenu;
      }
    }
struct bus{
    int BID; //BUS ID
    string model; //BUS MODEL
    string color; //BUS COLOR
    string license;//BUS LICENSE
    int EID;// EMPLOYEE ID
    int distanceTraveled;//DISTANCE THE BUS TRAVELED
    int MID;// MAINTAINANCE ID
    int inputBus(){
        cout<<"[+] Enter the bus id: ";
        cin>>BID;
        cout<<"[+] Enter the bus model: ";
        cin>>model;
        cout<<"[+] Enter the bus color: ";
        cin>>license;
        cout<<"[+] Enter the bus driver employee ID: ";
        cin>>EID;
        cout<<"[+] Enter the distance traveled by bus: ";
        cin>>distanceTraveled;
        cout<<"[+] Enter the bus maintainance ID: ";
        cin>>MID;
    }

};
struct customer{
    int CID; //CUSTOMER ID
    string name;// CUSTOMER NAME
    int age; //AGE OF THE CUSTOMER
    string identificationCard; //ID NUMBER OF THE CUSTOMER
    int balance; //THE BALANCE OF THE CUSTOMER
    char gender;//THE GENDER OF THE CUSTOMER
    int travelDistance; //THE DISTANCE THAT THE CUSTOMER COVERED BY THE COMPANY SERVICE
    void inputCustomer(){
        cout<<"[+] Enter the customer ID: ";
        cin>>this->CID;
        cout<<"[+] Enter the customer name: ";
        cin>>this->name;
        cout<<"[+] Enter the customer age: ";
        cin>>this->age;
        cout<<"[+] Enter the customer balance: ";
        cin>>this->balance;
        cout<<"[+] Enter the customer gender: ";
        cin>>this->gender;
        cout<<"[+] Enter the customer traveled Distance: ";
        cin>>this->travelDistance;
    }
};

struct travelDet{
	int TID;//TRAVEL DETAIL ID
	date day;//DATE OF TRAVEL
	int RID;//ROUTE IT TOOK 
	int EID;//DRIVER WHO WAS ON THAT SPECIFIC TRAVEL
	int numberOfCustomers;//NUMBER OF CUSTOMERS PRESENT ON THAT SPECIFIC TRAVEL
};

struct Booking {//TICKET BOOKING STRUCTURE
    int TID;//TICKET ID
    int BID;//BUS ID
    string route;//ROUTE OF TRAVEL
    float price;//PRICE OF TRAVEL
    int CID;//CUSTOMER ID
    int EID;//EMPLOYEE (TELLER) ID
    date depdate;//DATE OF DEPARTURE
};

struct maintain {
    int BID;//BUS ID
    int EID;//EMPLOYEE ID
    int MID;//MAINTENANCE ID
    date maintainDate;//DATE OF ID
};

void setBooking(Booking &input) {//FUNCTION TO TAKE INPUT OF TICKET BOOKING
       cout << "Enter the ticket ID: ";
       cin >> input.TID;
       cout << "Enter the bus ID: ";
       cin >> input.BID;
       cout << "Enter route: ";
       cin.ignore();
       getline (cin, input.route, '\n');
       cout << "Enter price of the trip: ";
       cin >> input.price;
       cout << "Enter customer ID: ";
       cin >> input.CID;
       cout << "Enter Employee ID: ";
       cin >> input.EID;
       cout << "Enter departure date (dd): ";
       cin >> input.depdate.dd;
       cout << "Enter departure date (mm): ";
       cin >> input.depdate.mm;
       cout << "Enter departure date (yy): ";
       cin >> input.depdate.yy;
    }
void setMaintain(maintain& input) {//FUNCTION TO TAKE INPUT MAINTENANCE DETAIL
    cout << "Enter the bus ID: ";
    cin >> input.BID;
    cout << "Enter Employee ID: ";
    cin >> input.EID;
    cout << "Enter maintenance ID: ";
    cin >> input.MID;
    cout << "Enter maintenance date (dd): ";
    cin >> input.maintainDate.dd;
    cout << "Enter maintenance date (mm): ";
    cin >> input.maintainDate.mm;
    cout << "Enter maintenance date (yy): ";
    cin >> input.maintainDate.yy;
}
 struct Route{
   int BID; //BUS ID
   int RID; // ROUTE ID
   string start; //STARTING POINT OR DEPARTURE
   string End;  // END POINT OR DESTINATION
   float distance; // DISTANCE OF TRAVEL
   float price; //PRICE OF TRAVEL

  Route setData(Route input){     //FUNCTION TO ACCEPT INPUT FROM THE USER
        cout<<"Enter the bus Id: "<<endl;  
        cin>>input.BID;   // INPUT FOR BUS ID
        cout<<"Enter the Route Id: "<<endl;
        cin>>input.RID;  //INPUT FOR ROUTE ID
        cout<<"Enter departure or the Starting point: "<<endl;
        cin>>input.start;   //INPUT FOR DEPARTURE
        cout<<"Enter destination or the End point: "<<endl;
        cin>>input.End;   //INPUT FOR DESTINATION
        }

};
void EditEmployee(employeeInfo employee[]){
    cout<<"Enter employee id: ";
    int Choice;
    cin>>Choice;
    // List of options to edit
    int EditChoice;
    cout << endl << "\t\t\t"<<" What would you like to edit?" << endl;
    cout <<"\t\t\t"<< "  1. Employee Name" << endl;
    cout <<"\t\t\t"<< "  2. Employee age" << endl;
    cout <<"\t\t\t"<< "  3. Employee identification " << endl;
    cout <<"\t\t\t"<< "  4. Employee position" << endl;
    cout <<"\t\t\t"<< "  5. Employee Sex" << endl;
    cout <<"\t\t\t"<< "  6. Employee phone number" << endl;
    cout <<"\t\t\t"<< "  7. Employee Email" << endl;
    cout <<"\t\t\t"<< "  8. Employee date of employment" << endl;
    cout <<"\t\t\t"<< endl << " Edit Choice: ";
    cin >> EditChoice;
    cout << endl;
    // Accept new values based on choice
    switch(EditChoice)
    {
    case 1:
        cout << " Enter Employee Name: ";
        cin >> employee[Choice].empFullName;
        break;
    case 2:
        cout << " Enter Employee age: ";
        cin >> employee[Choice].age;
        break;
    case 3:
        cout << "Enter Employee identification: ";
        cin >> employee[Choice].NID;
        break;
    case 4:
        cout << " Enter Employee driving license number" << endl;
        cin >> employee[Choice].driverLicenseNo;
        break;
    case 5:
        cout << " Enter Employee Gender: ";
        cin >> employee[Choice].sex;
        break;
    case 6:
        cout << " Enter Employee phone number: ";
        cin >> employee[Choice].phoneNumber;
        break;
    case 7:
        cout << " Enter Employee Email: ";
        cin >> employee[Choice].email;
        break;
    case 8:
        cout << " Enter Employee Date of employment: ";
        cin >> employee[Choice].empDate.dd;
        cin >> employee[Choice].empDate.mm;
        cin >> employee[Choice].empDate.yy;
        break;
    }
    cout<<endl<<"\t----\tEmployee Record Edited Successfully!\t----\n"<<endl<<endl;
    displayEmp(employee,5);
    system("pause");
    system("cls");

}
void EditBus(bus Bus[]){
cout<<"Enter bus id: ";
    int Choice;
    cin>>Choice;
    // List of options to edit
    int EditChoice;
    cout << endl << "\t\t\t"<<" What would you like to edit?" << endl;
    cout <<"\t\t\t"<< "  1. Bus Model" << endl;
    cout <<"\t\t\t"<< "  2. Bus color" << endl;
    cout <<"\t\t\t"<< "  3. Bus License " << endl;
    cout <<"\t\t\t"<< "  4. Distance traveled by the bus" << endl;
    cout <<"\t\t\t"<< "  5. Bus seats" << endl;
    cout <<"\t\t\t"<< endl << " Edit Choice: ";
    cin >> EditChoice;
    cout << endl;
    // Accept new values based on choice
    switch(EditChoice)
    {
    case 1:
        cout << " Enter Bus Model: ";
        cin >> Bus[Choice].model;
        break;
    case 2:
        cout << " Enter Bus Color: ";
        cin >> Bus[Choice].color;
        break;
    case 3:
        cout << "Enter Bus License: ";
        cin >> Bus[Choice].license;
        break;
    case 4:
        cout << " Enter Distance traveled by the bus" << endl;
        cin >> Bus[Choice].distanceTraveled;
        break;
    case 5:
        cout << " Enter Bus seats: ";
        cin >> Bus[Choice].seats;
        break;
    }
    cout<<endl<<"\t----\tBus Record Edited Successfully!\t----\n"<<endl<<endl;
    displayBus(Bus,5);
    system("pause");
    system("cls");
}
void EditCustomer(customer Customer[])
{
    cout<<"Enter customers id: ";
    int Choice;
    cin>>Choice;
    // List of options to edit
    int EditChoice;
    cout << endl << "\t\t\t"<<" What would you like to edit?" << endl;
    cout <<"\t\t\t"<< "  1. Customer Name" << endl;
    cout <<"\t\t\t"<< "  2. Customer age" << endl;
    cout <<"\t\t\t"<< "  3. Customer identification " << endl;
    cout <<"\t\t\t"<< "  4. Customer balance" << endl;
    cout <<"\t\t\t"<< "  5. Customer Sex" << endl;
    cout <<"\t\t\t"<< "  6. Customer travel distance" << endl;
    cout <<"\t\t\t"<< endl << " Edit Choice: ";
    cin >> EditChoice;
    cout << endl;
    // Accept new values based on choice
    switch(EditChoice)
    {
    case 1:
        cout << " Enter Customer Name: ";
        cin >> Customer[Choice].name;
        break;
    case 2:
        cout << " Enter Customer age: ";
        cin >> Customer[Choice].age;
        break;
    case 3:
        cout << "Enter Customer identification: ";
        cin >> Customer[Choice].identificationCard;
        break;
    case 4:
        cout << " Enter Customer balance" << endl;
        cin >> Customer[Choice].balance;
        break;
    case 5:
        cout << " Enter Customer Gender: ";
        cin >> Customer[Choice].sex;
        break;
    case 6:
        cout << " Enter Customer travel distance: ";
        cin >> Customer[Choice].travelDistance;
        break;
    }
    cout<<endl<<"\t----\tCustomer Record Edited Successfully!\t----\n"<<endl<<endl;
    displayCus(Customer,10);
    system("pause");
    system("cls");
}
void editRecordMenu(customer Customers[], employeeInfo Employees[], bus buses[])
{
    int opt;
    system("cls");
    cout<<"\t\t\t"<<"***********************************"<<endl;
    cout<<"\t\t\t\t"<<"  ADMIN PORTAL"<<endl;
    cout<<"\t\t\t"<<"***********************************\n"<<endl;
    cout<<"\t\t\t"<<"Choose which record you would like to edit/modify: \n"<<endl;
    cout<<"\t\t\t\t"<<"1.Employee record\n"<<endl;
    cout<<"\t\t\t\t"<<"2.Customer record\n"<<endl;
    cout<<"\t\t\t\t"<<"3.Bus information record\n"<<endl;
    cout<<"\t\t\t\t"<<"4.Back to previous menu\n"<<endl;
    cin>>opt;
    switch(opt)
    {
    case 1:
        EditEmployee(Employees);
        break;
    case 2:
        EditCustomer(Customers);
        break;
    case 3:
        EditBus(buses);
    case 4:
        adminMenu();
        break;
    }
}
//Initialize Customers default data
customer Customers[10];
void CustomerInitializer()
{
Customers[0] = {0,"abebe kebede",23,"Ets0213/22",234,'M',2344};
Customers[1] = {1,"Eden Getachew",29,"Ets3243/22",244,'F',2344};
Customers[2] = {2,"Solomon Feleke",21,"Ets0213/22",234,'M',2344};
Customers[3] = {3,"Daniel yohannes",18,"Ets3243/22",244,'F',2344};
Customers[4] = {4,"abel tadesse",19,"Ets0213/22",234,'M',2344};
Customers[5] = {5,"Meron tesema",23,"Ets3243/22",244,'F',2344};
Customers[6] = {6,"lidya geremew",24,"Ets0213/22",234,'M',2344};
Customers[7] = {7,"dagmawi ketema",22,"Ets3243/22",244,'F',2344};
Customers[8] = {8,"fikirte belete",33,"Ets0213/22",234,'M',2344};
Customers[9] = {9,"hewan adane",23,"Ets3243/22",244,'F',2344};
}
//Initialize Employees default data
employeeInfo Employees[5];
void EmployeeInitializer()
{
Employees[0]={0,23,"abebe kebede","aaa@gmail.com","teller","Ets0213/22",'M',{2,3,2021},0115535654,2344};
Employees[1] = {1,29,"Eden Getachew","eee@gmail.com","Driver","Ets0213/22",'M',{2,3,2021},0115535654,2344};
Employees[2] = {2,21,"Solomon Feleke","sss@gmail.com","Driver","Ets0213/22",'M',{2,3,2021},0115535654,2344};
Employees[3] = {3,24,"Daniel yohannes","ddd@gmail.com","Driver","Ets0213/22",'M',{2,3,2021},0115535654,2344};
Employees[4] = {4,25,"abel tadesse","abc@gmail.com","Driver","Ets0213/22",'M',{2,3,2021},0115535654,2344};
}
//Initialize Bus default data
bus buses[5];
void BusInitializer()
{
buses[0] = {0,"	Single deck","red","aa11",0,1223,0,20};
buses[1] = {1,"	Single deck","white","aa12",1,5678,1,20};
buses[2] = {2,"	Single deck","red","aa13",2,9876,2,20};
buses[3] = {3,"minibus","blue","ab11",3,7654,3,12};
buses[4] = {4,"minibus","white","ab12",4,1234,4,12};
}
void adminMenu()
{
    system("cls");
    int adminOpt;
    cout<<"\t\t\t"<<"***********************************"<<endl;
    cout<<"\t\t\t\t"<<"  ADMIN PORTAL"<<endl;
    cout<<"\t\t\t"<<"***********************************\n"<<endl;
    cout<<"\t\t\t"<<"Choose the task you would like to do: \n"<<endl;
    cout<<"\t\t\t\t"<<"1.Insert a new record\n"<<endl;
    cout<<"\t\t\t\t"<<"2.Edit a record\n"<<endl;
    cout<<"\t\t\t\t"<<"3.Display entries\n"<<endl;
    cin>>adminOpt;
    switch(adminOpt)
    {
    case 1:
        insertRecordMenu();
        break;
    case 2:
        editRecordMenu(Customers);
        break;
    case 3:
        displayCus(Customers,10);
        break;
    }
}

void askPassword()
{
pass:
    system("cls");
    int password=1234;
    int opt;
    cout<<"\n\n\n\t\t\t\t"<<"Please enter password:"<<endl;
    cout<<"\t\t\t\t"<<"password:  ";
    cin>>password;
    if (password==1234)
    {
        system("cls");
        adminMenu();
    }
    else
    {
        system("cls");
        cout<<"\n\t\t\t\t"<<"Incorrect Password! please try again!\n"<<endl;
        cout<<"\t\t\t\t"<<"press any number to try again and 0 to exit"<<endl;
        cin>>opt;
        if(opt==0)
        {
            exit;
        }
        else
        {
            goto pass;
        }
    }

}
void book(){
    system("cls");
cout<<"\t\t\t"<<"***********************************"<<endl;
cout<<"\t\t\t\t"<<"WELCOME TO BEST-BUS!"<<endl;
cout<<"\t\t\t"<<"***********************************"<<endl;
cout<<"\t\t\t"<<"Booking\n"<<endl;
}
void masterMenu()
{
    cout<<"\t\t\t"<<"***********************************"<<endl;
    cout<<"\t\t\t\t"<<"WELCOME TO BEST-BUS!"<<endl;
    cout<<"\t\t\t"<<"***********************************"<<endl;
    cout<<"\t\t\t"<<"Please choose your clearance level:\n"<<endl;
    cout<<"\t\t\t\t"<<"1.Administrator\n"<<endl;
    cout<<"\t\t\t\t"<<"2.Customer"<<endl;
    int option;
    cin>>option;
    switch(option)
    {
    case 1:
        askPassword();
        break;
    case 2:
       book();
    break;

    }
}

int main(){
// 0 for background Color(Black)
// B for text color(light aqua)
    system("Color 0B");
//Initialize Customer sample data
    CustomerInitializer();
    masterMenu();
employeeInfo empData;
empData.Record_Emp_Info(empData);
bus busInfo;
customer customerInfo;
busInfo.inputBus();
customerInfo.inputCustomer();
travelDet travelLog;
Booking ticket;
setBooking(ticket);
maintain mHistory;
setMaintain(mHistory);
Route Terminal,input;
Terminal.setData(input);
return 0;
}
void insertRecordMenu()
{
    int insertRec;
    employeeInfo employee[2];
    customer cuInfo[1];
    system("cls");
    cout<<"\t\t\t"<<"***********************************"<<endl;
    cout<<"\t\t\t\t"<<"   ADMIN PORTAL"<<endl;
    cout<<"\t\t\t"<<"***********************************\n"<<endl;
    cout<<"\t\t\t"<<"Choose which record you would like to insert: \n"<<endl;
    cout<<"\t\t\t\t"<<"1.Employee record\n"<<endl;
    cout<<"\t\t\t\t"<<"2.Customer record\n"<<endl;
    cout<<"\t\t\t\t"<<"3.Bus information record\n"<<endl;
    cout<<"\t\t\t\t"<<"4.Back to previous menu\n"<<endl;
    cin>>insertRec;
    switch(insertRec)
    {
    case 1:
        system("cls");
        cout<<"\t\t\t"<<"***********************************************"<<endl;
        cout<<"\t\t\t\t"<<"Employee Record Input Portal"<<endl;
        cout<<"\t\t\t"<<"***********************************************"<<endl;
        for(int i=0; i<2; i++)
        {
            employee[i].Record_Emp_Info(i);
        }
        break;
    case 2:
        system("cls");
        cout<<"\t\t\t"<<"***********************************************"<<endl;
        cout<<"\t\t\t\t"<<"Customer Information Record Portal"<<endl;
        cout<<"\t\t\t"<<"***********************************************"<<endl;
        for (int x=0; x<1; x++)
        {
            cuInfo[x].inputCustomer(x+1);
        }
        cout<<"\n\n\t\t\t"<<"Would you like to Continue or Exit?"<<endl;
        cout<<"\t\t\t\t"<<"1. Continue"<<endl;
        cout<<"\t\t\t\t"<<"2. Exit"<<endl;
        char Choice;
        cin>>Choice;
        switch(Choice)
        {
        case '1':
            adminMenu();
            break;
        case '2':
            break;

        }
        break;
    case 3:
        system("cls");
        cout<<"\t\t\t"<<"***********************************************"<<endl;
        cout<<"\t\t\t\t"<<" Bus Information Record Portal"<<endl;
        cout<<"\t\t\t"<<"***********************************************"<<endl;

        break;
    case 4:
        adminMenu();
        break;
    }

}
