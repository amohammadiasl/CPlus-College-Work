//Ali Mohammadiasl
#include <iostream>

#include <string>

using namespace std;

//define the node for the linked list

struct node {


    string data;


    node *next;

    node(string elem) {

        data = elem;

        next = NULL;

    }

};

//define the stack class

class stack {

private:

    //properties of the stack class


    node *top;

    int length;

public:

    //function prototypes

    stack();

    bool push(string);

    string pop();

    string peek();

    bool concatTopTwo();

    bool appendStoTop();

    void display();

    int getLength();

    bool isEmpty();

};

//default contructor, sets top to NULL and length to 0

stack::stack() {

    top = NULL;

    length = 0;

}

//returns true if stack is empty, otherwise false

bool stack::isEmpty() {

    return length == 0;

}

//returns the length of the stack

int stack::getLength() {

    return length;

}

//pushes an element to the stack if it is a valid string according to the parameters

bool stack::push(string elem) {

    if(elem.length() == 0  || elem.length() > 10) {

        cout << "The string " << elem << " of length "<<elem.length()<<" is invalid!" << endl;

        return false;

    }

    else {

        //create a new node with the data elem

        node *newNode = new node(elem);

        if(top == NULL) {

            top = newNode;

        }

        //condition for non empty stack

        else {

            newNode->next = top;

            top = newNode;

        }

        //increment length

        length++;

        return true;

    }

}

//removes the node from the top of the stack

string stack::pop() {


    if(top == NULL) {

        return "";

    }


    node *temp = top;


    top = top->next;


    length--;

    //get the data of the former top node

    string top_str = temp->data;


    delete temp;


    return top_str;

}

//return the data at the top of the stack if not empty

string stack::peek() {

    if(top == NULL)

        return "";

    return top->data;

}

//if stack is not empty, append s to the data of the top element

bool stack::appendStoTop() {

    if(top == NULL) {

        return false;

    }

    else {

        if(top->data.length() > 9)

            top->data = top->data.substr(0,9) + "s";

        else

            top->data =  top->data + "s";

    }

}

//if the stack has two components, pop them and put them together at the very top

bool stack::concatTopTwo() {

    if(length < 2) {

        return false;

    }

    else {

        string a = pop();

        string b = pop();

        string concat = a + b;

        if(concat.length() > 10)

            concat = concat.substr(0,10);

        push(concat);

        return true;

    }

}

//displays the content of the stack

void stack::display() {

    if(top == NULL) {

        cout << "Stack Empty. Undeflow!" << endl;

    }

    else {

        node *tracer = top;

        while(tracer != NULL) {

            if(tracer->next == NULL)

                cout << tracer->data;

            else

                cout << tracer->data << "-->";

            tracer = tracer->next;

        }

        cout << endl;

    }

}

//recives references to the stack objects and diplays them
void displayStack(stack &names) {

    cout << "Names Stack: " << endl;

    names.display();


}



void createStory(stack &names) {

  

   if(names.getLength() < 5  ) {

       cout << "There aren't enough words in the stack to create the story. Please populate the stack"<<endl;

       cout << "with sufficient number of terms to create a story. Atleast 5 nouns (names) are needed to create the story"<<endl;

   }

   else {

       cout << "Danny was preparing for his friend " << names.pop() << "'s birthday party when " << names.pop() << " called him and said that he can not make it to the party. " << endl;

       cout << "Upset, Danny called his other friends " << names.pop() << " and " << names.pop() << " to make sure that they will make it to the party. " << "At the end, Danny's best friend " << names.pop() << " came in clutch and brought a cake and everything went well at the party."  << endl;

   }

}

//main contains the code for user input and menu related operation.

int main() {

    stack name;

    string input;

    int choice;

    bool again = true;

    while(again) {

        cout << "\n****STORY GAME****" << endl;

        cout << "******************" << endl;

        cout << "1. Push " << endl;

        cout << "2. Pop " << endl;

        cout << "3. Concetanate top two words of stack" << endl;

        cout << "4. Add and 's' to the top word of the stack" << endl;

        cout << "5. Display stack" << endl;

        cout << "6. Make a story" << endl;

        cout << "7. Exit" << endl;

        cout << "Enter your choice: ";

        cin >> choice;

        switch(choice) {

            case 1:

                cout << "Enter the Noun to push to the stack:" << endl;

                cin >> input;

                if(name.push(input))

                    cout << "The noun " << input << " was successfully pushed to the stack" << endl;

                break;

            case 2:

                input = name.pop();

                if(input == "")

                    cout << "Stack Empty. Underflow" << endl;

                else

                    cout << input << " was popped from the noun stack" << endl;

                break;

            case 3:

                if(name.concatTopTwo())

                    cout << "top two terms of the noun stack were concatenated and turned into a single term" << endl;

                else

                    cout << "Not enough words in the noun stack" << endl;

                break;

            case 4:

                if(name.appendStoTop())

                    cout << "'s' was appended to the noun at the top of the noun stack" << endl;

                else

                    cout << "Stack Empty. Underflow!" << endl;

                break;

            case 5:

                displayStack(name);

                break;

            case 6:

                createStory(name);

                break;

            case 7:

                again = false;

                break;

            default:

                cout << "Invalid Choice! Enter a valid choice (1-9)";

        }

    }

}

