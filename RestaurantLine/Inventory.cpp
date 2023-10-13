#include "Inventory.h"


// inserts the node at the front of the queue
void insertAtFirst(QueueNode **head, QueueNode *node) {
    
    if (*head == nullptr) {
        *head = node;
    } else {
        
        QueueNode *tempNode = *head;
        node->next = tempNode;
        *head = node;
    }
}


QueueNode *createNewNode(string name) {
    // create a new node
    auto *newNode = new QueueNode;
    // setting the name
    newNode->name = std::move(name);
    newNode->raffleTicketNumber = raffleNumber;
    newNode->next = nullptr;
    cout << "Welcome to Snow's - your raffle number is " << raffleNumber << endl;
    raffleNumber++;
    return newNode;
}

// THIS IS A RECURSIVE FUNCTION
void enqueue(QueueNode **head, const string& name) {
    // if head is null, this means list is empty, in this case set head to newNode
    if ((*head) == nullptr) {
        *head = createNewNode(name);
    } else if ((*head)->next == nullptr) {
        (*head)->next = createNewNode(name);
    } else {
        QueueNode *temp = (*head)->next;
        enqueue(&temp, name);
    }
}

// THIS IS A RECURSIVE FUNCTION
// get the count of the nodes
int count(QueueNode *head) {
    if (head == nullptr) {
        return 0;
    } else {
        return 1 + count(head->next);
    }
}

// THIS IS A RECURSIVE FUNCTION
void remove(QueueNode **head, QueueNode *deleteNode) {
    // if the current Node is null, this means either the list is empty or the search Node
    // could not be found
    if ((*head) == deleteNode) {
        *head = nullptr;
    }
    // else if the next Node of the current deleteNode equals the search Node
    // then basically set the next Node of the current Node to the next Node of the deleteNode
    if ((*head)->next == deleteNode) {
        (*head)->next = deleteNode->next;
    } else {
        // else move to the next node
        QueueNode *tempNode = *head;
        remove(&(tempNode->next), deleteNode);
    }
}

void dequeue(QueueNode **head) {
    if (*head == nullptr) {
        cout << "Sorry! Nobody is in the queue.\n";
    } else {
        QueueNode *firstNode = *head;
        *head = firstNode->next;
        cout << firstNode->name << ", you can order now!\n";
        delete firstNode;
    }
}

// THIS IS A RECURSIVE FUNCTION
QueueNode *searchByIdx(QueueNode *head, int idx, int searchIdx) {
    if (head == nullptr) {
        return nullptr;
    } else if (idx == searchIdx) {
        return head;
    } else {
        return searchByIdx(head->next, idx + 1, searchIdx);
    }
}

// THIS IS A RECURSIVE FUNCTION
QueueNode *searchByName(QueueNode *head, const string& searchName) {
    // if current node is null, this means either the list is empty
    // or we have traversed the entire node, so return nullptr
    if (head == nullptr) {
        return nullptr;
    } else if (head->name == searchName) {
        return head;
    } else {
        return searchByName(head->next, searchName);
    }
}

// THIS IS A RECURSIVE FUNCTION
// displays each of the nodes in the queue
void display(QueueNode *head, int index) {
    if (head == nullptr) {
        return;
    } else {
        cout << "(" << index << ")" << "\t" << head->name << "\t\t\t" << head->raffleTicketNumber << endl;
        display(head->next, index + 1);
    }
}