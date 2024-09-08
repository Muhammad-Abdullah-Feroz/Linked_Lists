#include<iostream>
#include<conio.h>

using namespace std;

class node{
    int value;
    node * next;
public:
    void next(node * newNode){
        this->next = newNode;
    }
    int value(){
        return this->value;
    }
};