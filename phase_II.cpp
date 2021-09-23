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
