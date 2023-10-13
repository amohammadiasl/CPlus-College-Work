#include<iostream>

using namespace std;

static int raffleNumber = 1;

struct QueueNode {
    string name;
    int raffleTicketNumber{};
    QueueNode *next{};
};

void insertAtFirst(QueueNode **head, QueueNode *node);
QueueNode *createNewNode(string name);
void enqueue(QueueNode **head, const string& name);
int count(QueueNode *head);
void remove(QueueNode **head, QueueNode *deleteNode);
void dequeue(QueueNode **head);
QueueNode *searchByIdx(QueueNode *head, int idx, int searchIdx);
QueueNode *searchByName(QueueNode *head, const string& searchName);
void display(QueueNode *head, int index);