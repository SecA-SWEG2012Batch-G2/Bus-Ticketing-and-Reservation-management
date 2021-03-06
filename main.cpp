#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include<windows.h>
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
    int seats;//SEATS ON THE BUS
    bool availability=true;
    //FUNCTION TO INPUT AND RECORD EMPLOYEE INFORMATION
    int inputBus(int busCounter, int empCounter, employeeInfo driverInfo[]){//TAKE BUS COUNT, EMPLOYEE COUNT AND EMPLOYEE INFORMATION
        int temp=busCounter;
        BID=4001+temp;//BUS ID ALWAYS START WITH 4000
        MID=BID+1000;//MAINTENANCE ID ALWAYS START WITH 5000
        cout<<"\n[+] Enter the bus model: ";
        cin>>model;
        cout<<"[+] Enter the bus color: ";
        cin>>color;
        cout<<"[+] Enter the distance traveled by bus: ";
        cin>>distanceTraveled;
        cout<<"[+] Enter the number of people that the bus can support: ";
        cin>>seats;
        for (int x=0; x<empCounter; x++) {//AUTOMATICALLY ASSIGN A DRIVER TO THE BUS IF AVALIABLE
            if (driverInfo[x].EID<2000) {
                if (busCounter==0) {
                        EID=driverInfo[x].EID;
                        cout<<"Driver assigned!";
                        break;
                }
                busCounter--;
            }
            if (x==empCounter-1) {
                cout<<"There is no driver to be assigned at the moment! \n";
                EID=0;
            }
        }
    }

};
//FUNCTION TO DISPLAY BUS INFORMATION
void displayBus(bus information[], int infoSize)  //TAKE BUS STUCTURE ARRAY AND ITS SIZE AS PARAMETER
{
    char command;
empMenu://SMALL MENU FOR DISPLAYING BUS INFORMATION
    cout<<"\tHow would you like to display bus record"<<endl;
    cout<<"       ________________________________________________________\n";
    cout<<"       | 1. Display all bus record                             |\n";
    cout<<"       | 2. Search using bus ID                                |\n";
    cout<<"       | 3. exit                                               |\n";
    cout<<"       |-------------------------------------------------------|\n";
    cin>>command;//INPUT THE COMMAND FROM USER
    switch (command)  //SWITCH USED TO EXECUTE SPECIFIC COMMANDS
    {
    case '1':
        //TABLE THAT DISPLAY EVERY BUS RECORD
        cout<<setfill(' ');//FILL THE TABLES EMPTY SPACE WITH THE SPECIFIED CHARACTER
        cout<<"\t|"<<setw(12)<<"Employee ID |"<<setw(12)<<"Bus ID     |"<<setw(15)<<" Model |"<<setw(13)<<" Color |"<<setw(5)<<" Odometer |"<<setw(12)<<" Seats|";
        for (int x=0; x<infoSize; x++)
        {
            if (information[x].EID==0)
            {
                cout<<endl<<"\t|"<<setw(9)<<"N/A"<<setw(4)<<"  |"<<setw(11)<<information[x].BID<<"|"<<setw(13)<<information[x].model<<" |"<<setw(12)<<information[x].color<<"|"<<setw(10)<<information[x].distanceTraveled<<"|"<<setw(11)<<information[x].seats<<"|";
                continue;
            }
            if(information[x].BID!=0 && information[x].color!=""){
                cout<<endl<<"\t|"<<setw(9)<<information[x].EID<<setw(4)<<"  |"<<setw(11)<<information[x].BID<<"|"<<setw(13)<<information[x].model<<" |"<<setw(12)<<information[x].color<<"|"<<setw(10)<<information[x].distanceTraveled<<"|"<<setw(11)<<information[x].seats<<"|";
            }

        }
        break;
    case '2':
        int searchId;
searchEmp:
        //TABLE THAT DISPLAY DISIRED (SEARCHED) BUS INFORMATION
        cout<<"Input bus id: ";
        cin>>searchId;
        for (int x=0; x<infoSize; x++)
        {
            if (information[x].BID == searchId)
            {
                cout<<"\t|"<<setw(12)<<"Employee ID |"<<setw(12)<<"Bus ID     |"<<setw(15)<<" Model |"<<setw(13)<<" Color |"<<setw(5)<<" Odometer |"<<setw(12)<<" Seats|";
                if (information[x].EID==0)
                {
                    cout<<endl<<"\t|"<<setw(9)<<"N/A"<<setw(4)<<"  |"<<setw(11)<<information[x].BID<<"|"<<setw(13)<<information[x].model<<" |"<<setw(12)<<information[x].color<<"|"<<setw(10)<<information[x].distanceTraveled<<"|"<<setw(11)<<information[x].seats<<"|";
                    continue;
                }
                cout<<endl<<"\t|"<<setw(9)<<information[x].EID<<setw(4)<<"  |"<<setw(11)<<information[x].BID<<"|"<<setw(13)<<information[x].model<<" |"<<setw(12)<<information[x].color<<"|"<<setw(10)<<information[x].distanceTraveled<<"|"<<setw(11)<<information[x].seats<<"|";
                break;
            }
            if (x==infoSize-1) cout<<"Bus id not found";
        }
searchAgain:
        cout<<"\n Do you want to search again (y/n)?";//PROPT THE USER TO SEARCH AGAIN
        cin>>command;
        if (command == 'y' || command=='Y' || command=='n' || command=='N')
        {
            if (command=='y' ||command=='Y') goto searchEmp;
        }
        else
        {
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

typedef struct customer
{
    int CID; //CUSTOMER ID
    string name;// CUSTOMER NAME
    int age; //AGE OF THE CUSTOMER
    string identificationCard; //ID NUMBER OF THE CUSTOMER
    int balance; //THE BALANCE OF THE CUSTOMER
    char sex;//THE GENDER OF THE CUSTOMER
    int travelDistance; //THE DISTANCE THAT THE CUSTOMER COVERED BY THE COMPANY SERVICE
    //FUNCTION TO INPUT AND RECORD EMPLOYEE INFORMATION
void inputCustomer(int cusCounter) //TAKE CUSTOMER COUNT TO AUTOMATICALLY ASSIGN CUSTOMER ID
    {
        CID=0+cusCounter;//CUSTOMER'S ID ALWAYS START WITH 6000
        cout<<"\n\t\t\t Enter the customer name: ";
        cin.ignore();
        getline(cin, name);//INPUT FULL NAME OF THE CUSTOMER
        cout<<"\t\t\t Enter the customer age: ";
        cin>>age;
        balance=0;
        cout<<"\t\t\t Enter the customer's sex: ";
        cin>>sex;
        cout<<"\t\t\t Enter the customer traveled Distance: ";
        cin>>travelDistance;
    }
} customer;

//FUNCTION TO DISPLAY CUSTOMER INFORMATION
void displayCus (customer information[], int infoSize)  //TAKE CUSTOMER STRUCTURE ARRAY AND ITS SIZE AS PARAMETER
{
    char command;
empMenu://SMALL MENU FOR DISPLAYING CUSTOMER INFORMATION
    cout<<"\tHow would you like to display customer record"<<endl;
    cout<<"       ________________________________________________________\n";
    cout<<"       | 1. Display all customer record                        |\n";
    cout<<"       | 2. Search using customer ID                           |\n";
    cout<<"       | 3. exit                                               |\n";
    cout<<"       |-------------------------------------------------------|\n";
    cin>>command;//INPUT THE COMMAND FROM USER
    switch (command)  //SWITCH USED TO EXECUTE SPECIFIC COMMANDS
    {
    case '1':
        //TABLE THAT DISPLAY EVERY customer RECORD
        char order;
        cout<<"[+] do you want to display in ascending or descending order(a/d)?";
a:
        cin>>order;//arranges record ascending or descending order(based on user's input)
        if(order=='a'||order=='A'||order=='d'||order=='D')
        {
            if(order=='a'||order=='A')
            {
                cout<<setfill(' ');//FILL THE TABLES EMPTY SPACE WITH THE SPECIFIED CHARACTER
                cout<<"\n\t__________________________________________________________________________________________\n";
                cout<<"\t|"<<setw(12)<<"Customer ID |"<<setw(30)<<"Customer name     "<<setw(10)<<"| Age |"<<setw(13)<<" Balance |"<<setw(5)<<" Sex |"<<setw(12)<<" Traveling miles|";
                for (int x=0; x<infoSize; x++)
                {
                    if(information[x].CID!=0 && information[x].name!=""){
                        cout<<endl<<"\t|"<<setw(9)<<information[x].CID<<setw(4)<<"  |"<<setw(33)<<information[x].name<<"|"<<setw(4)<<information[x].age<<" |"<<setw(12)<<information[x].balance<<"|"<<setw(5)<<information[x].sex<<"|"<<setw(15)<<information[x].travelDistance<<setw(2)<<"|";
                    }

                }
                cout<<"\n\t|________________________________________________________________________________________|";
            }
            else
            {
                cout<<setfill(' ');//FILL THE TABLES EMPTY SPACE WITH THE SPECIFIED CHARACTER
                cout<<"\n\t__________________________________________________________________________________________\n";
                cout<<"\t|"<<setw(12)<<"Customer ID |"<<setw(30)<<"Customer name     "<<setw(10)<<"| Age |"<<setw(13)<<" Balance |"<<setw(5)<<" Sex |"<<setw(12)<<" Traveling miles|";
                for (int x=infoSize-1; x>=0; x--)
                {
                    cout<<endl<<"\t|"<<setw(9)<<information[x].CID<<setw(4)<<"  |"<<setw(33)<<information[x].name<<"|"<<setw(4)<<information[x].age<<" |"<<setw(12)<<information[x].balance<<"|"<<setw(5)<<information[x].sex<<"|"<<setw(15)<<information[x].travelDistance<<setw(2)<<"|";
                }
                cout<<"\n\t|________________________________________________________________________________________|";
            }
        }
        else
        {
            cout<<"[-] Wrong input, input a for ascending or d for descending.";
            goto a;
        }
        break;
    case '2':
        int searchId;
searchEmp:
        //TABLE THAT DISPLAY DISIRED (SEARCHED) customer INFORMATION
        cout<<"Input customer id: ";
        cin>>searchId;
        for (int x=0; x<infoSize; x++)
        {
            if (information[x].CID == searchId)
            {
                cout<<"\t|"<<setw(12)<<"Customer ID |"<<setw(30)<<"Customer name     "<<setw(10)<<"| Age |"<<setw(13)<<" Balance |"<<setw(5)<<" Sex |"<<setw(12)<<" Traveling miles|";
                cout<<endl<<"\t|"<<setw(9)<<information[x].CID<<setw(4)<<"  |"<<setw(33)<<information[x].name<<"|"<<setw(4)<<information[x].age<<" |"<<setw(12)<<information[x].balance<<"|"<<setw(5)<<information[x].sex<<"|"<<setw(15)<<information[x].travelDistance<<setw(2)<<"|";
                break;
            }
            if (x==infoSize-1) cout<<"customer id not found";
        }
searchAgain:
        cout<<"\n Do you want to search again (y/n)?";//PROPT THE USER TO SEARCH AGAIN
        cin>>command;
        if (command == 'y' || command=='Y' || command=='n' || command=='N')
        {
            if (command=='y' ||command=='Y') goto searchEmp;
        }
        else
        {
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
	
struct travelDet{//STRUCTURE THAT IS USED TO LOG EVERY TRAVEL MADE USING THE SYSTEM
	int TID;//TRAVEL DETAIL ID
	date day;//DATE OF TRAVEL
	int RID;//ROUTE IT TOOK 
	int EID;//DRIVER WHO WAS ON THAT SPECIFIC TRAVEL
	int numberOfCustomers;//NUMBER OF CUSTOMERS PRESENT ON THAT SPECIFIC TRAVEL
};
struct maintain {//STRUCTURE HOLDING INFORMATION ON THE BUS MAINTENANCE HISTORY 
    int BID;//BUS ID
    int EID;//EMPLOYEE ID
    int MID;//MAINTENANCE ID
    date maintainDate;//DATE OF ID
};

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
   int seatsAva=0;//available seats
   int seatMax=seatsAva;
   int RID; // ROUTE ID
   string start; //STARTING POINT OR DEPARTURE
   string End=" ";  // END POINT OR DESTINATION
   float distance; // DISTANCE OF TRAVEL
   float price; //PRICE OF TRAVEL

  void setRoute(int routeCount, int busCount, bus busInfo[], bool &busAva){     //FUNCTION TO ACCEPT INPUT FROM THE USER
        BID=0;
        RID=6000+routeCount;  //INPUT FOR ROUTE ID
        cout<<"\n Enter departure or the Starting point: ";
        cin.ignore();
        getline(cin,start);   //INPUT FOR DEPARTURE
        cout<<"Enter destination or the  End point: ";
        cin.ignore();
        getline(cin,End);   //INPUT FOR DESTINATION
        cout<<"Enter distance in kilometers: ";
        cin>>distance;
        cout<<"Enter price: ";
        cin>>price;
        int counter=0;
        for (int x=0; x<busCount; x++){
                if (busInfo[x].availability == true && busInfo[x].EID!=0) {
                    counter++;
                    if (counter==1) cout<<"\t Available bus \n \t| NO |"<<setw(12)<<"Bus ID     |"<<setw(15)<<" Model |"<<setw(13)<<" Color |"<<setw(5)<<" Odometer |"<<setw(12)<<" Seats|";
                    cout<<endl<<"\t|"<<setw(3)<<counter<<" |"<<setw(11)<<busInfo[x].BID<<"|"<<setw(13)<<busInfo[x].model<<" |"<<setw(12)<<busInfo[x].color<<"|"<<setw(10)<<busInfo[x].distanceTraveled<<"|"<<setw(11)<<busInfo[x].seats<<"|";
                    }

                else if (x==(busCount-1) && busInfo[x].availability==false) cout<<"\n\t No Available bus at the moment";
            }
        if (counter!=0) {
            tryagain:
            cout<<"\n [+] input bus id to assign to the route: ";
            cin>>counter;
            for (int x=0; x<busCount;x++) {
                if (busInfo[x].BID==counter) {
                    BID=counter;
                    seatsAva=busInfo[x].seats;
                    busAva=false;
                    break;
                   }
                 else if (x==busCount-1) {
                    cout<<"Wrong bus ID! \n";
                    goto tryagain;
                       }
                   }
              }
        }
};
struct Booking {//TICKET BOOKING STRUCTURE
    int TID;//TICKET ID
    int BID;//BUS ID
    int RID;//ROUTE ID
    int seatNum;//seat number
    float price;//PRICE OF TRAVEL
    int CID;//CUSTOMER ID
    int EID;//EMPLOYEE (TELLER) ID
    date depdate;//DATE OF DEPARTURE
    void printTicket(Route routeInfo[],int routeSiz, customer information[], int infoSize ){
        //Function that displays the ticket
        string name;
        int identify;//identify on which array the route exist
        for(int i=0; i<=infoSize; i++){
            if(information[i].CID==CID){
                name = information[i].name;//prints the name from the customer record
            }
        }
        for (int x=0; x<routeSiz; x++) if (routeInfo[x].RID==RID) identify=x;
        cout<<" \n\t________________________________________________________\n";
        cout<<"\t|                     BUS TICKET                        |\n";
        cout<<"\t|-------------------------------------------------------|\n";
        cout<<"\t|"<<setw(14)<<"Ticket ID:"<<setw(7)<<TID<<setw(36)<<" |\n";
        cout<<"\t|"<<setw(9)<<"Bus ID:"<<setw(7)<<BID<<setw(17)<<"Seat No:"<<seatNum<<setw(21)<<" |\n";
        cout<<"\t|"<<setw(8)<<"name: "<<setw(17)<<name<<setw(32)<<"|\n";
        cout<<"\t|"<<setw(14)<<"Customer ID:"<<setw(7)<<CID<<setw(36)<<" |\n";
        cout<<"\t|"<<setw(9)<<"From:"<<setw(15)<<routeInfo[identify].start<<"    To:"<<setw(15)<<routeInfo[identify].End<<setw(11)<<" |\n";
        cout<<"\t|"<<setw(11)<<"Route ID:"<<setw(7)<<RID<<setw(39)<<" |\n";
        cout<<"\t|"<<setw(9)<<"Price: "<<setw(12)<<price<<setw(36)<<"|\n";
        cout<<"\t|"<<setw(8)<<"Date: "<<setw(8)<<depdate.dd<<"/"<<depdate.mm<<"/"<<depdate.yy<<setw(33)<<"|\n";
        cout<<"\t|_______________________________________________________|\n";
    }
    //FUNCTION TO TAKE INPUT OF TICKET BOOKING
    void setBooking(int ticketCount,Route avaRoute[], int routeSize, customer information[], int infoSize) {
        //take number of tickets, available routes with its array size and customer information with its array size
       TID=7001+ticketCount;//ticket id generator
       int inputRoute,temp;//take which route the customer wanna take
       cout<<endl;
       //outputs the available routes (routes which have assigned driver and bus)
       cout<<"\t|"<<setw(13)<<"Route ID |"<<setw(13)<<"Bus ID     |"<<setw(15)<<" Start |"<<setw(13)<<" End |"<<setw(5)<<" Distance |"<<setw(12)<<" Price|"<<setw(17)<<" Available Seats|";
            for (int x=0; x<routeSize; x++) {
                if (avaRoute[x].BID!=0) {
                    cout<<endl<<"\t|"<<setw(9)<<avaRoute[x].RID<<setw(4)<<"  |"<<setw(11)<<avaRoute[x].BID<<" |"<<setw(13)<<avaRoute[x].start<<" |"<<setw(12)<<avaRoute[x].End<<"|"<<setw(10)<<avaRoute[x].distance<<"|"<<setw(11)<<avaRoute[x].price<<"|"<<setw(11)<<avaRoute[x].seatsAva<<setw(6)<<"|";
                    }
              }
       tryagain:
           //prompts again if customer inputs wrong route (routes which are not in the list)
            cout<<"\n [+] input Route id to book your ticket: ";
            cin>>inputRoute;//take which route the customer wanna take
            for (int x=0; x<routeSize;x++) {
                if (avaRoute[x].RID==inputRoute && avaRoute[x].BID!=0) {
                        //checks if the route entered by the customer is available
                    RID=inputRoute;//assign the route id after it's checked for availability
                    BID=avaRoute[x].BID;//record which bus the customer will be taking
                    price=avaRoute[x].price;//record the price of the trip
                    avaRoute[x].seatsAva--;//update available seats since seat is assigned for customer
                    seatNum=avaRoute[x].seatMax-avaRoute[x].seatsAva;//which seat will the customer be taking
                    temp=x;
                    break;
                   }
                 else if (x==routeSize-1) {
                        //check if the route entered by the customer is from the list
                    cout<<"Wrong Route id! \n";
                    goto tryagain;//get to try until they get the right one
                       }
                   }
       char chs;//char variable to take command from the user
       int counter=0;//counts trial of input
        cout << "\nEnter customer ID: ";//take customer id to buy a ticket and deduct price from balance (if prompted)
       a:cin >> CID;
       bool stt=false;
       for(int i=0; i<infoSize; i++){
            //check if the customer is registered or not
        if(information[i].CID==CID){
            stt=true;
            break;
        }
       }
       if(stt==false){
        cout<<"[-] No customer with that ID, please enter valid ID: ";
        counter++;
        if (counter<3) goto a;//input customer id again if left with trials
        else {
          cout<<"\n\tToo many attempts!\n";
          avaRoute[temp].seatsAva++;//revert the number of seats to the original
        }
       }
       if (counter<3) {
           //all the function will not take place if correct customer id is not available
       f:
       cout<<"\t=> Do you want to pay in cash or to be deducted from prepaid account \n\t [+} press 'y' for prepaid \t [+] press 'n' for cash";
       cin>>chs;
       if(chs=='y'||chs=='Y'||chs=='n'||chs=='N'){
           //take the price fee from customer's balance or paid in cash
        if(chs=='y'||chs=='Y'){
            for(int i=0; i<infoSize; i++){
                if(information[i].CID==CID){
                    if(information[i].balance>=price){
                        //check if the customer have enough balance
                        information[i].balance-=price;
                    }
                    else{
                        cout<<"[-] Insufficient balance, payment will be done in cash!\n";
			    //if balance not sufficent payment option will be changed to cash
                    }
                }
            }
        }
       }
       else{
        goto f;
       }
       //take the date of departure
       cout << "Enter departure date (dd): ";
       cin >> depdate.dd;
       if (depdate.dd>31) {
	       //upper limit of day
            depdate.dd=31;
       }
       else if (depdate.dd<1) {
	       //lower limit of day
            depdate.dd=1;
       }
       cout << "Enter departure date (mm): ";
       cin >> depdate.mm;
       if (depdate.mm>13) {
	       //upper limit of month
            depdate.mm=13;
       }
       else if (depdate.mm<1) {
	       //lower limit of month
            depdate.mm=1;
       }
       cout << "Enter departure date (yy): ";
       cin >> depdate.yy;
       printTicket(avaRoute,routeSize,information,infoSize);//call the ticket printer
        }

    }
};
	void displayRoute(Route information[], int infoSize) {
    char command;
      empMenu://SMALL MENU FOR DISPLAYING ROUTES INFORMATION
      cout<<"\tHow would you like to display route record"<<endl;
      cout<<"       ________________________________________________________\n";
      cout<<"       | 1. Display all routes record                          |\n";
      cout<<"       | 2. Search using routes ID                             |\n";
      cout<<"       | 3. exit                                               |\n";
      cout<<"       |-------------------------------------------------------|\n";
      cin>>command;//INPUT THE COMMAND FROM USER
      switch (command) {//SWITCH USED TO EXECUTE SPECIFIC COMMANDS
        case '1':
            //TABLE THAT DISPLAY EVERY routes RECORD
            cout<<setfill(' ');//FILL THE TABLES EMPTY SPACE WITH THE SPECIFIED CHARACTER
            cout<<"\t|"<<setw(13)<<"Route ID |"<<setw(13)<<"Bus ID     |"<<setw(15)<<" Start |"<<setw(13)<<" End |"<<setw(5)<<" Distance |"<<setw(12)<<" Price|"<<setw(17)<<" Available Seats|";
            for (int x=0; x<infoSize; x++) {
                if (information[x].BID==0) {
                    cout<<endl<<"\t|"<<setw(9)<<information[x].RID<<setw(4)<<"  |"<<setw(11)<<" N/A "<<" |"<<setw(13)<<information[x].start<<" |"<<setw(12)<<information[x].End<<"|"<<setw(10)<<information[x].distance<<"|"<<setw(11)<<information[x].price<<"|"<<setw(11)<<information[x].seatsAva<<setw(6)<<"|";
                    continue;
                    }
                cout<<endl<<"\t|"<<setw(9)<<information[x].RID<<setw(4)<<"  |"<<setw(11)<<information[x].BID<<" |"<<setw(13)<<information[x].start<<" |"<<setw(12)<<information[x].End<<"|"<<setw(10)<<information[x].distance<<"|"<<setw(11)<<information[x].price<<"|"<<setw(11)<<information[x].seatsAva<<setw(6)<<"|";
              }
            break;
        case '2':
            int searchId;
            searchEmp:
            //TABLE THAT DISPLAY DISIRED (SEARCHED) routes INFORMATION
            cout<<"Input routes id: ";
            cin>>searchId;
            for (int x=0; x<infoSize; x++) {
                if (information[x].RID == searchId) {
                  cout<<"\t|"<<setw(13)<<"Route ID |"<<setw(13)<<"Bus ID     |"<<setw(15)<<" Start |"<<setw(13)<<" End |"<<setw(5)<<" Distance |"<<setw(12)<<" Price|"<<setw(17)<<" Available Seats|";
                    if (information[x].BID==0) {
                       cout<<endl<<"\t|"<<setw(9)<<information[x].RID<<setw(4)<<"  |"<<setw(11)<<" N/A "<<" |"<<setw(13)<<information[x].start<<" |"<<setw(12)<<information[x].End<<"|"<<setw(10)<<information[x].distance<<"|"<<setw(11)<<information[x].price<<"|"<<setw(11)<<information[x].seatsAva<<setw(6)<<"|";
                       break;
                        }
                    cout<<endl<<"\t|"<<setw(9)<<information[x].RID<<setw(4)<<"  |"<<setw(11)<<information[x].BID<<" |"<<setw(13)<<information[x].start<<" |"<<setw(12)<<information[x].End<<"|"<<setw(10)<<information[x].distance<<"|"<<setw(11)<<information[x].price<<"|"<<setw(11)<<information[x].seatsAva<<setw(6)<<"|";
                    break;
                }
                if (x==infoSize-1) cout<<"route id not found";
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

void deleteCustomer(customer information[], int cusSize){
    int inp;
    cout<<"[+] Enter the Customer ID to remove it from the list: ";
    cin>>inp;
    for(int i=0; i<cusSize; i++){
        if(inp==information[i].CID){
            information[i].CID=0;
            information[i].name="";
            information[i].identificationCard="";
            information[i].age=0;
            information[i].travelDistance=0;
            information[i].balance=0;
            cout<<"[+] Customer with id "<<inp<<" has been deleted from the record\n";
            system("pause");
        }
    }
}
void deleteEmployee(employeeInfo information[], int empSize){
    int inp;
    cout<<"[+] Enter the Employee ID to remove it from the list: ";
    cin>>inp;
    for(int i=0; i<empSize; i++){
        if(inp==information[i].EID){
            information[i].EID=0;
            information[i].empFullName="";
            information[i].email="";
            information[i].driverLicenseNo=0;
            information[i].NID="";
            information[i].position="";
            cout<<"[+] Employee with id "<<inp<<" has been deleted from the record\n";
            system("pause");
        }
    }
}
void deleteBus(bus information[], int busSize){
    int inp;
    cout<<"[+] Enter the Bus ID to remove it from the list: ";
    cin>>inp;
    for(int i=0; i<busSize; i++){
        if(inp==information[i].BID){
            information[i].BID=0;
            information[i].color="";
            cout<<"[+] BUS with id "<<inp<<" has been deleted from the record\n";
            system("pause");
        }
    }
}
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
	void displayRecord(customer Customers[], employeeInfo Employees[], bus buses[]){
    int opt;
    system("cls");
    cout<<"\t\t\t"<<"***********************************"<<endl;
    cout<<"\t\t\t\t"<<"  ADMIN PORTAL"<<endl;
    cout<<"\t\t\t"<<"***********************************\n"<<endl;
    cout<<"\t\t\t"<<"Choose which record you would like to display: \n"<<endl;
    cout<<"\t\t\t\t"<<"1.Employee record\n"<<endl;
    cout<<"\t\t\t\t"<<"2.Customer record\n"<<endl;
    cout<<"\t\t\t\t"<<"3.Bus information record\n"<<endl;
    cout<<"\t\t\t\t"<<"4.Back to previous menu\n"<<endl;
    cin>>opt;
    switch(opt)
    {
    case 1:
        displayEmp(Employees, 5);
        cout<<endl;
        system("pause");
        adminMenu();
        break;
    case 2:
        displayCus(Customers, 10);
        cout<<endl;
        system("pause");
        adminMenu();
        break;
    case 3:
        displayBus(buses, 4);
        cout<<endl;
        system("pause");
        adminMenu();
    case 4:
        adminMenu();
        break;
    }
}
void deleteRecordMenu(customer Customers[], employeeInfo Employees[], bus buses[]){
    int opt;
    system("cls");
    cout<<"\t\t\t"<<"***********************************"<<endl;
    cout<<"\t\t\t\t"<<"  ADMIN PORTAL"<<endl;
    cout<<"\t\t\t"<<"***********************************\n"<<endl;
    cout<<"\t\t\t"<<"Choose which record you would like to delete: \n"<<endl;
    cout<<"\t\t\t\t"<<"1.Employee record\n"<<endl;
    cout<<"\t\t\t\t"<<"2.Customer record\n"<<endl;
    cout<<"\t\t\t\t"<<"3.Bus information record\n"<<endl;
    cout<<"\t\t\t\t"<<"4.Back to previous menu\n"<<endl;
    cin>>opt;
    switch(opt)
    {
    case 1:
        deleteEmployee(Employees, 10);
        adminMenu();
        break;
    case 2:
        deleteCustomer(Customers,10);
        adminMenu();
        break;
    case 3:
        deleteBus(buses, 10);
        adminMenu();
    case 4:
        adminMenu();
        break;
    }
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
void masterMenu();
//Initialize Customers sample data
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
//Initialize employee sample data
employeeInfo Employees[5];
void EmployeeInitializer()
{
Employees[0]={0,23,"abebe kebede","aaa@gmail.com","teller","Ets0213/22",'M',{2,3,2021},0115535654,2344};
Employees[1] = {1,29,"Eden Getachew","eee@gmail.com","Driver","Ets0213/22",'M',{2,3,2021},0115535654,2344};
Employees[2] = {2,21,"Solomon Feleke","sss@gmail.com","Driver","Ets0213/22",'M',{2,3,2021},0115535654,2344};
Employees[3] = {3,24,"Daniel yohannes","ddd@gmail.com","Driver","Ets0213/22",'M',{2,3,2021},0115535654,2344};
Employees[4] = {4,25,"abel tadesse","abc@gmail.com","Driver","Ets0213/22",'M',{2,3,2021},0115535654,2344};
}
bus buses[5];
void BusInitializer()
{
    //Initialize bus data
buses[0].BID=1;buses[0].model="Iveco";buses[0].color="blue";buses[0].license="A12456";buses[0].EID=1;buses[0].distanceTraveled=20000;buses[0].MID=1;buses[0].seats=60;buses[0].availability=true;
buses[1].BID=2;buses[1].model="Iveco";buses[1].color="blue";buses[1].license="A12457";buses[1].EID=2;buses[1].distanceTraveled=20000;buses[1].MID=2;buses[1].seats=60;buses[1].availability=true;
buses[2].BID=3;buses[2].model="TATA";buses[2].color="blue";buses[2].license="A12458";buses[2].EID=3;buses[2].distanceTraveled=20000;buses[2].MID=3;buses[2].seats=60;buses[2].availability=true;
buses[3].BID=4;buses[3].model="Iveco";buses[3].color="blue";buses[3].license="A12459";buses[3].EID=4;buses[3].distanceTraveled=20000;buses[3].MID=4;buses[3].seats=60;buses[3].availability=true;
buses[4].BID=5;buses[4].model="Iveco";buses[4].color="blue";buses[4].license="A12460";buses[4].EID=5;buses[4].distanceTraveled=20000;buses[4].MID=5;buses[4].seats=60;buses[4].availability=true;}
Route routeInfo[4];
void RoutInit(){
	//Initialize route data
    routeInfo[0].BID=1;routeInfo[0].seatsAva=60,routeInfo[0].RID=1;routeInfo[0].start="AA";routeInfo[0].End="HA";routeInfo[0].distance=520;routeInfo[0].price=200;
    routeInfo[1].BID=2;routeInfo[1].seatsAva=60,routeInfo[1].RID=2;routeInfo[1].start="AA";routeInfo[1].End="DR";routeInfo[1].distance=500;routeInfo[1].price=180;
    routeInfo[2].BID=3;routeInfo[2].seatsAva=60,routeInfo[2].RID=3;routeInfo[2].start="AA";routeInfo[2].End="BD";routeInfo[2].distance=670;routeInfo[2].price=300;
    routeInfo[3].BID=4;routeInfo[3].seatsAva=60,routeInfo[3].RID=4;routeInfo[3].start="AA";routeInfo[3].End="MK";routeInfo[3].distance=800;routeInfo[3].price=400;

}

int prepaid(customer information[], int infoSize) //function used for perpaid card
{
    int CID, bal;
    bool stat=false;
    char cont;
info:
    cout<<"\n[+] Enter the ID of the customer to add prepaid card: ";
    cin>>CID;//the customer's id (customer who is updating his prepaid account)
	//search the customer's record
    for(int i=0; i<infoSize; i++)
    {
        if(information[i].CID==CID)
        {
            stat = true;
            cout<<"\n\t Current balance: "<<information[i].balance<<"\n";
            cout<<"[+]  Enter the amount to add to the prepaid card: ";
            cin>>bal;
            information[i].balance+=bal;//calculate the new balance
            cout<<"    the prepaid balance of the user is "<<information[i].balance<<"\n";
        }
    }
    if(stat==false)
    {
	    //if invalid id is put, prompt to input customer id again
        cout<<"[-] No customer with that ID, do you want to try again(y/n)?";
        cin>>cont;
        if(cont=='y'||cont=='Y'||cont=='n'||cont=='N')
        {
            if(cont=='y'||cont=='Y')
            {
                goto info;
            }
        }

    }
}

void adminMenu()
{//adminstrator's menu
    system("cls");
    tryagain:
    char adminOpt;
    cout<<"\t\t\t"<<"***********************************"<<endl;
    cout<<"\t\t\t\t"<<"  ADMIN PORTAL"<<endl;
    cout<<"\t\t\t"<<"***********************************\n"<<endl;
    cout<<"\t\t\t"<<"Choose the task you would like to do: \n"<<endl;
    cout<<"\t\t\t\t"<<"1.Insert a new record\n"<<endl;
    cout<<"\t\t\t\t"<<"2.Edit a record\n"<<endl;
    cout<<"\t\t\t\t"<<"3.Display entries\n"<<endl;
    cout<<"\t\t\t\t"<<"4.Delete entries\n"<<endl;
    cout<<"\t\t\t\t"<<"5.Recharge Customer's Balance\n"<<endl;
    cin>>adminOpt;
    switch(adminOpt)//execute user's choice
    {
    case '1':
        insertRecordMenu();
        system("pause");
        system ("cls");
        goto tryagain;
        break;
    case '2':
        editRecordMenu(Customers,Employees,buses);
        system("pause");
        system ("cls");
        goto tryagain;
        break;
    case '3':
        displayRecord(Customers,Employees,buses);
        system("pause");
        system ("cls");
        goto tryagain;
        break;
    case '4':
        deleteRecordMenu(Customers,Employees,buses);
        system("pause");
        system ("cls");
        goto tryagain;
        break;
    case '5':
        prepaid(Customers,10);
        system("pause");
        system ("cls");
        goto tryagain;
        break;
    default:
		    //prompt again if wrong key is put
        system("cls");
        cout<<"\n\t\t\t\t  !Wrong key! \n\n";
        goto tryagain;
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
void book(customer cuInfo[], int nRoute){
    system("cls");
opto:cout<<"\t\t\t"<<"***********************************"<<endl;
cout<<"\t\t\t\t"<<"WELCOME TO BEST-BUS!"<<endl;
cout<<"\t\t\t"<<"***********************************"<<endl;
cout<<"\t\t\t"<<"1. Booking\n"<<endl;
char opt;
cin>>opt;
switch(opt){
    case '1':
        int tik;
        cout<<"[+] Enter the number of tickets you want to have: ";
        cin>>tik;
        Booking tickets[tik];
        for (int x=0; x<tik; x++) {
            tickets[x].setBooking(x,routeInfo,nRoute,cuInfo,10);
        }
        bookExit:cout<<"\t\t\t"<<"***********************************"<<endl;
        cout<<"\t\t\t"<<"   THANKS FOR CHOOSING BEST-BUS!"<<endl;
        cout<<"\t\t\t"<<"***********************************"<<endl;
        cout<<"\t\t\t"<<"1. Go to Main Menu\n"<<endl;
        cout<<"\t\t\t"<<"0. Exit\n"<<endl;
        cin>>opt;
        if (opt == '1')  masterMenu();
        else if (opt =='0') exit(0);
        else{
            cout<<"\tWrong key!/n";
            goto bookExit;
            }
    }
}
void masterMenu()
{
    tryagain:
    cout<<"\t\t\t"<<"***********************************"<<endl;
    cout<<"\t\t\t\t"<<"WELCOME TO BEST-BUS!"<<endl;
    cout<<"\t\t\t"<<"***********************************"<<endl;
    cout<<"\t\t\t"<<"Please choose your clearance level:\n"<<endl;
    cout<<"\t\t\t\t"<<"1.Administrator\n"<<endl;
    cout<<"\t\t\t\t"<<"2.Customer"<<endl;
    char option;
    cin>>option;
    switch(option)
      {
    case '1':
        askPassword();
        system("pause");
        system ("cls");
        goto tryagain;
        break;
    case '2':
       book(Customers, 4);
       system("pause");
        system ("cls");
        goto tryagain;
        break;
    default:
        system("cls");
        cout<<"\n\t\t\t\t  !Wrong key! \n\n";
        goto tryagain;

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
