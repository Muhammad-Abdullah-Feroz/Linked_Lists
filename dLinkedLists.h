#pragma once

#include <iostream>
#include <conio.h>

using namespace std;

class node
{
private:
    int value;
    node *next;
    node *prev;

public:
    node();
    node(int value);
    int getValue();
    node *getNext();
    node *getPrev();
    void setValue(int newVal);
    void setNext(node *nextNode);
    void setPrev(node *prevNode);
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

int node::getValue()
{
    return this->value;
}
node *node::getNext()
{
    return this->next;
}
node *node::getPrev()
{
    return this->prev;
}

void node::setNext(node *nextNode)
{
    this->next = nextNode;
}
void node::setPrev(node *prevNode)
{
    this->prev = prevNode;
}
void node::setValue(int newVal)
{
    this->value = newVal;
}

class dList
{
private:
    node *head;
    node *tail;

public:
    dList();
    ~dList();
    void append(int value);
    void insertAtStart(int value);
    void insert(int idx, int value);
    void deleteNode(int value);
    void display();
    void reverse();
};

dList::dList()
{
    head = nullptr;
    tail = nullptr;
}

void dList::append(int value)
{
    node *newNode = new node(value);

    if (head == nullptr)
    {
        head = newNode;
        tail = head;
    }
    else
    {
        // nodePtr = tail;
        tail->setNext(newNode);
        newNode->setPrev(tail);
        tail = newNode;
    }
}

void dList::display()
{
    node *nodePtr = head;

    if (!nodePtr)
    {
        cout << endl
             << "List is empty";
    }
    else
    {
        cout << endl;
        while (nodePtr->getNext())
        {
            cout << nodePtr->getValue() << " -> ";
            nodePtr = nodePtr->getNext();
        }
        cout << nodePtr->getValue();
    }
}

void dList::insertAtStart(int value)
{
    node *newNode = new node(value);

    if (head == nullptr)
    {
        head = newNode;
        tail = head;
    }
    else
    {
        newNode->setNext(head);
        head->setPrev(newNode);
        head = newNode;
    }
}

void dList::insert(int idx, int value)
{
    if (idx < 0)
    {
        cout << endl
             << "Invalid Index...";
    }
    else if (idx == 0)
    {
        insertAtStart(value);
    }
    else
    {
        node *nodePtr = head;
        int index = 0;
        while (nodePtr && index != idx)
        {
            nodePtr = nodePtr->getNext();
            index++;
        }
        if (index == idx)
        {
            if (!nodePtr)
            {
                append(value);
            }
            else
            {
                node *newNode = new node(value);
                newNode->setNext(nodePtr);
                newNode->setPrev(nodePtr->getPrev());
                nodePtr->getPrev()->setNext(newNode);
                nodePtr->setPrev(newNode);
            }
        }
    }
}

void dList::deleteNode(int value)
{
    if (head == nullptr)
    {
        cout << endl
             << "List is already empty...";
        return;
    }
    else
    {
        node *nodePtr = head;
        while (nodePtr)
        {
            if (nodePtr->getValue() == value)
            {
                if (nodePtr == head)
                {
                    head = nodePtr->getNext();
                    head->setPrev(nullptr);
                }
                else if (nodePtr == tail)
                {
                    tail = nodePtr->getPrev();
                    tail->setNext(nullptr);
                }
                else
                {
                    nodePtr->getPrev()->setNext(nodePtr->getNext());
                    nodePtr->getNext()->setPrev(nodePtr->getPrev());
                }
                delete nodePtr;
                return;
            }
            nodePtr = nodePtr->getNext();
        }
    }
}

void dList::reverse()
{
    if (head == nullptr)
    {
        cout << endl
             << "List is empty...";
    }
    else
    {
        node *current = head;
        node *next;

        while (current)
        {
            next = current->getNext();
            current->setNext(current->getPrev());
            current->setPrev(next);
            current = next;
        }

        current = head;
        head = tail;
        tail = current;
    }
}

dList::~dList()
{
}
