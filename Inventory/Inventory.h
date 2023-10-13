//ALI MOHANMADIASL

#pragma once
#include <iostream>
using namespace std;

struct node{

    string data;
    node *next;

};

class inventory{

    private:
    node *a, *b;

    public:

inventory();

    void append(string);

    int insert(string, int);

    int Delete(int);

    void reverse();

    void print();

    int search(string);

};