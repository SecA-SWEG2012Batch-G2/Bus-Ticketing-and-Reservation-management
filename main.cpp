#include <iostream>
#include <cstring>
using namespace std;

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
                cout<<"We are sorry, we are not hiring for that position!! \n ";
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


int main(){
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
