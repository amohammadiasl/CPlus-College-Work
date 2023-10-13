//Ali Mohammadiasl

#include "binaryTree.h"
#include <iostream>

using namespace std;

void displayMenu();

int main() {

int choice = 0;

int input;

IntBinaryTree tree;

do {

displayMenu();

cin >> choice;

cout << endl;

switch (choice) {

case 1:

cout << "Please insert numbers into the tree: ";

cin >> input;

tree.insertNode(input);

cout << endl;

break;

case 2:
//In the order from smallest to largest

cout << "This is the display of the tree in order: ";

tree.displayInOrder();

cout << endl;

//The order that the numbers were inserted
cout << "This is the display of the tree Pre order: ";

tree.displayPreOrder();

cout << endl;


case 3:

cout << "This is the number of leaves on the tree: ";

cout << tree.leafCount();

cout << endl;

break;

case 4:

cout << "The height of the tree is: ";

cout << tree.height();

break;

case 5:

cout << "The width of the tree is: ";

cout << tree.widthTree();

break;

case 6:

exit(0);

break;

default:

cout << endl;

cout << "Invalid Entry" << endl << endl;

cout << "Please enter the appropiate option" << endl << endl;

}

} while (choice != 6);

return 0;

} //end of int main()

void displayMenu() {

cout << endl << endl;

cout << "********************************************************************************";

cout << endl;

cout << " Welcome to the List" << endl;

cout << "********************************************************************************";

cout << endl;

cout << "Please select one of the following options:" << endl;

cout << "1.Insert numbers" << endl;

cout << "2.Display the tree in order" << endl;

cout << "3.Display Leaf Count" << endl;

cout << "4.Display Tree Height" << endl;

cout << "5.Display Tree Width" << endl;

cout << "6.Exit" << endl;

cout << "Enter your choice : ";

}