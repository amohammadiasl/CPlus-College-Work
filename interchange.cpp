/* Ali Mohammadiasl*/
#include <stdio.h>
#include <iostream>
using namespace std;

void inter (char* point){ //function for changing values of 1st and 4th column

int a = 0, b = 3;
char temp;
for(int i = 0; i < 30; i++){
    temp = (*(point +i));
    (*(point + i )) =  (*(point + i + 3));
    (*(point + i + 3)) = temp;
    i+= 5;
    }
cout << "The columns in your array have been switched." << "\n\n";
}

void vow (char* point) {//function for finding the total number of vowels in the words

int i, j, array = 0;
cout << " ";

    for(i = 0; i < 30; i++){
        if (*(point + i) == 'a' || *(point + i) == 'e' || 
            *(point + i) == 'i' || *(point + i) == 'o' || *(point + i) == 'u'){
            array++;
        }
    }
cout << "There are " << array << " vowels in this array." << "\n\n";
}

void disp (char* point){ //function to display all values matrix

cout << " ";

for(int i=0; i<30; i++){
    cout << *(point + i ) << ' '; 
   
    if ( i % 6 == 5 ){
      cout << '\n' << ' ';//A new line is printed
                          //with every 5th character
                         //cout << " ";
      }
     
    }
}


    

void srch (char* point){ //function to search a specific character given by the user

int array = 0;
char character;
cout << "Enter a character to search: ";
cin >> character;
cout << " ";
for (int i = 0; i < 30; i++){
    if (*(point + i) == character){
        array++;
    }
    }
        
cout << "Number of times " << character << " is found: " << array << "\n\n";
}


int main (){
char str[5][6] = { "sweet", "heart", "egrit", "clone", "odors" };

char *point;
point = &str[0][0];
int choice = 0;
while(choice!=5){
       cout<<" MENU" << '\n';       
       cout<<" 1. Interchange column 1 with column 4" << '\n';
       cout<<" 2. Count and display the total number of vowels in the words." << '\n';
       cout<<" 3. Display the array in a matrix (rows and columns)"<< '\n';
       cout<<" 4. Search for and display number of times a specific character appears"<< '\n';
       cout<<" 5. Exit"<< '\n';
       cout<<" CHOICE : ";
       cin>>choice;
       switch(choice){
            case 1  :   inter(point);       
                       break;
            case 2  :   vow(point);       
                       break;
            case 3  :   disp(point);       
                       break;
            case 4  :   srch(point);       
                       break;
            case 5  :   cout<<" GoodBye ";
                       break;
       }
   }
return 0;
}

