//ALI MOHANMADIASL

#include <iostream>
#include "Inventory.h"
using namespace std;

int main(){

    inventory I;
    int choice, pos, res;
    string d;

do{

    cout << "\n1. Append";

    cout << "\n2. Insert";

    cout << "\n3. Delete";

    cout << "\n4. Print";

    cout << "\n5. Reverse";

    cout << "\n6. Search";

    cout << "\nChoose a menu option: ";

    cin >> choice;

switch(choice){

    case 1:

        cout << "\nEnter a primary color: ";
        cin >> d;
        I.append(d);
        break;

    case 2:{

        string d;
        cout << "\nEnter a primary color: ";
        cin >> d;
        cout << "\nEnter a position: ";
        cin >> pos;
        res = I.insert(d, pos);
        if(res == -1)
            cout << "\nThis Position does not exist";
            break;
    }

    case 3:
        cout << "\nEnter a position: ";
        cin >> pos;
        res = I.Delete(pos);
        if(res == -1) cout << "\nThis Position does not exist";
        break;

    case 4:
        cout << "\nINVENTORY: \n";
        I.print();
        break;

    case 5:
        I.reverse();
        break;

    case 6:
        cout << "\nEnter a primary color to search for: ";
        cin >> d;
        pos = I.search(d); 
        if(pos == -1) cout << "\nColor not found!";
            else cout << "\nColor found at position: " << pos;
        break;

    default:
    break;

}

}while(choice < 7);

}