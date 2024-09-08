#include <iostream>
#include <conio.h>

using namespace std;

class node
{
    int value;
    node *next;

public:
    void setNext(node *newNode)
    {
        this->next = newNode;
    }
    void setValue(int value)
    {
        this->value = value;
    }
    node *getNext()
    {
        return next;
    }
    int getValue()
    {
        return this->value;
    }
};

class integerList
{
private:
    node *head;

public:
    integerList()
    {
        this->head = NULL;
    }

    void append(int value)
    {
        node *newNode = new node;

        newNode->setValue(value);
        newNode->setNext(nullptr);

        if(!head){
            head = newNode;
        }else{
            node * nodePtr = head;
            node* prev;

            while(nodePtr->getNext() != nullptr){
                nodePtr = nodePtr->getNext();
            }

            nodePtr->setNext(newNode);
        }
    }
};