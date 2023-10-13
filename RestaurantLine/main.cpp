//Ali Mohammadiasl


#include <iostream>
#include "Inventory.h"

using namespace std;



// display menu
void displayMenu() {
    cout << "Snow's BBQ Menu\n";
    cout << "1. Add a Name\n";
    cout << "2. Make an order\n";
    cout << "3. Count names\n";
    cout << "4. Draw Raffle Winner\n";
    cout << "5. Display Line\n";
    cout << "6. Exit Menu\n";
}

// adds the name at the end of the queue
void addAName(QueueNode **head) {
    string name;
    cout << "Enter your name: ";
    cin >> name;
    enqueue(head, name);
}

void makeAnOrder(QueueNode **head) {
    dequeue(head);
}

void countNames(QueueNode **head) {
    int totalNames = count(*head);
    cout << "Number of people in the line: " << totalNames << endl;
}

// display line function calls the queue function display
void displayLine(QueueNode **head) {
    if (*head == 0) cout << "There are currently 0 people in line! \n";
    display(*head, 0);
}

void drawRaffleWinner(QueueNode **head) {
    srand(time(nullptr));
    int totalNodes = count(*head); 
    int randomIdx = rand() % totalNodes;
    
    if (*head != nullptr) {
        
        QueueNode *resultNode = searchByIdx(*head, 0, randomIdx);
        
        if (resultNode == nullptr) {
            cout << "No winner could be found!";
        } else {
            
            cout << "The winning raffle number is: " << resultNode->raffleTicketNumber << endl;
            cout << "\n";
            cout << resultNode->name << " do you want:\n";
            cout << "1.\tTo move to the front of the line, or\n";
            cout << "2.\tA free t-shirt\n\n";
            cout << "Choose your option: ";
            int option;
            cin >> option;
            if (option == 1) {
                if (resultNode == *head) {
                    cout << resultNode->name << ", you are already in front of the line.\n";
                } else {
                    cout << resultNode->name << ", you are being moved to the front of the line.\n";
                    
                    remove(head, resultNode);
                    
                    insertAtFirst(head, resultNode);
                }
            } else {
               
                cout << "You got a free T-shirt\n";
            }
        }
    }
}




int main() {
    QueueNode *head = nullptr;
    displayMenu();
    int userChoice;
    do {
        cout << "\nChoose your option: ";
        cin >> userChoice;
        switch (userChoice) {
            case 1:
                addAName(&head);
                break;
            case 2:
                makeAnOrder(&head);
                break;
            case 3:
                countNames(&head);
                break;
            case 4:
                drawRaffleWinner(&head);
                break;
            case 5:
                displayLine(&head);
                break;
            default:
                break;
        }
        if (userChoice != 6 )
            displayMenu() ;
    } while (userChoice != 6);

    cout << "Thanks for visiting San Pedro Fish Market!\n";

}