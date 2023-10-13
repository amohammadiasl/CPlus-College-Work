/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include<string>
#include<iomanip>
#include<limits>
using namespace std;

class inventory{
    private:
    int checkInNumber;
    string workDescription, custPhone;
    float priceQuoted;
    
public: inventory(){
    checkInNumber = 0;
    workDescription = "";
    custPhone = "";
    priceQuoted = 0.0;
  
}

void setCheckInNumber(int c){
    if(c > 0){
    checkInNumber = c;
    }
}

int getCheckInNumber(){
    return checkInNumber;
}

void setWorkDescription(string w){
    if(w.length()<30){
    workDescription = w;
    }
}

string getWorkDescription(){
    return workDescription;
}

void setCustPhone(string p){
    if(p.length()<11){
    custPhone=p;
    }
}

string getCustPhone(){
    return custPhone;
}

void setPriceQuoted(float p){
    if(p>=0.0){
    priceQuoted=p;
    }
}

float getPriceQuoted(){
    return priceQuoted;
    }

};
    
int main(){

    inventory repair[3] = {inventory(),inventory(),inventory()}; 
    int checkInNumber;
    string workDesc,custPhone;
    float priceQuoted;


    for(int i = 0 ; i < 3 ; i++){
        cout<<"Repair "<<i+1<<endl;
        cout<<"Enter check in number: ";
        cin>>checkInNumber;

    while(cin.fail() || checkInNumber<=0){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"Please input a positive value!!"<<endl;
        cin>>checkInNumber;
    }
        cin.ignore();
        cout<<"Enter work done: ";
        getline(cin,workDesc);

    while(workDesc.size()>=30){
        cout<<"Please input repair needs in less than 30 characters!!"<<endl;
        getline(cin,workDesc);
    }

        cout<<"Enter phone number: ";
        getline(cin,custPhone);

    while(custPhone.size()>=11){
        cout<<"Please input phone number in less than 11 characters!!"<<endl;
        getline(cin,custPhone);
    }

        cout<<"Enter quoted repair price: ";
        cin>>priceQuoted;

    while(cin.fail() ||priceQuoted<0){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"Please input a positive value!!"<<endl;
        cin>>priceQuoted;
    }

    repair[i].setCheckInNumber(checkInNumber);
    repair[i].setWorkDescription(workDesc);
    repair[i].setCustPhone(custPhone);
    repair[i].setPriceQuoted(priceQuoted);
}

    float totalQuote = 0;

    cout<<endl<<"Dexter's Repair shop"<<endl<<endl;

    for(int i = 0 ; i < 3 ; i++){
        cout<<endl;
        cout<<left<<setw(20)<<"CheckIn Number:"<<repair[i].getCheckInNumber()<<endl;
        cout<<left<<setw(20)<<"Work Description:"<<repair[i].getWorkDescription()<<endl;
        cout<<left<<setw(20)<<"Customer Phone:"<<repair[i].getCustPhone()<<endl;
        cout<<left<<setw(20)<<"Quote to repair:"<<"$"<<repair[i].getPriceQuoted()<<endl;
        totalQuote+=repair[i].getPriceQuoted();
    }

    cout<<"-------------------------------"<<endl;
    cout<<left<<setw(20)<<"Total of all quotes: $"<<totalQuote;

    return 0;
}
