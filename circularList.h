#pragma once
#include <iostream>
#include <conio.h>

using namespace std;

class node
{
    int value;
    node *next;

public:
    node(int val)
    {
        this->value = val;
        this->next = nullptr;
    }
    void setValue(int val){
        this->value = val;
    }
    int getValue(){
        return this->value;
    }
    void setNext(node * nextNode){
        this->next = nextNode;
    }
    node * getNext(){
        return this->next;
    }
};

class cList{
    node* head;
    node* tail;
    public:
        cList(){
            head = nullptr;
            tail = nullptr;
        }
};