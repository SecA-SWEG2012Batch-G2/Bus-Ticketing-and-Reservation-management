#include <iostream>
using namespace std;
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
        cout<<"Enter the Root Id: "<<endl;
        cin>>input.RID;  //INPUT FOR ROUTE ID
        cout<<"Enter departure or the Starting point: "<<endl;
        cin>>input.start;   //INPUT FOR DEPARTURE
        cout<<"Enter destination or the End point: "<<endl;
        cin>>input.End;   //INPUT FOR DESTINATION
        }

};


int main()
{
     Route Terminal,input;
      Terminal.setData(input);
    return 0;
}
