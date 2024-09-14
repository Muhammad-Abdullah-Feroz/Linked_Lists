#pragma once

#include<iostream>
#include<conio.h>

using namespace std;

class node
{
private:
    int value;
    node* next;
    node* prev;
public:
    node();
    node(int value);
    int getValue();
    node* getNext();
    node* getPrev();
    void setValue(int newVal);
    void setNext(node * nextNode);
    void setPrev(node * prevNode);
};

node::node()
{
    value = 0;
    next = nullptr;
    prev = nullptr;
}

node::node(int value)
{
    this->value = value;
    next = nullptr;
    prev = nullptr;
}

int node::getValue(){
    return this->value;
}
node* node::getNext(){
    return this->next;
}
node* node::getPrev(){
    return this->prev;
}

void node::setNext(node * nextNode){
    this->next = nextNode;
}
void node::setPrev(node * prevNode){
    this->prev = prevNode;
}
void node::setValue(int newVal){
    this->value = newVal;
}


class dList
{
private:
    node * head;
    node * tail;
public:
    dList();
    ~dList();
    void append(int value);
    void display();

};

dList::dList()
{
    head = nullptr;
    tail = nullptr;
}

void dList::append(int value){
    node * newNode = new node(value);

    if(head == nullptr){
        head = newNode;
        tail = head;
    }else{
        // nodePtr = tail;
        tail->setNext(newNode);
        newNode->setPrev(tail);
        tail = newNode;
    }
}

void dList::display(){
    node * nodePtr = head;

    if (!nodePtr){
        cout<<endl<<"List is empty";
    }else{
        cout<<endl;
        while(nodePtr->getNext()){
            cout<<nodePtr->getValue()<<" -> ";
            nodePtr = nodePtr->getNext();
        }
        cout<<nodePtr->getValue();
    }
}


dList::~dList()
{
}
