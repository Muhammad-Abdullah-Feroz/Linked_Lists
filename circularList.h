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
    void setValue(int val)
    {
        this->value = val;
    }
    int getValue()
    {
        return this->value;
    }
    void setNext(node *nextNode)
    {
        this->next = nextNode;
    }
    node *getNext()
    {
        return this->next;
    }
};

class cList
{
    node *head;
    node *tail;

public:
    cList()
    {
        head = nullptr;
        tail = nullptr;
    }
    void display()
    {
        node *nodePtr = head;
        cout << endl;
        if (!head)
        {
            cout << "List is empty...";
            return;
        }
        while (nodePtr != tail)
        {
            cout << nodePtr->getValue() << " -> ";
            nodePtr = nodePtr->getNext();
        }
        cout << nodePtr->getValue();
    }
    void insertAtStart(int value)
    {
        node *newNode = new node(value);
        newNode->setNext(head);
        if (head == nullptr)
        {
            tail = newNode;
            head = newNode;
        }
        else
        {
            head = newNode;
        }

        tail->setNext(head);
    }
    void append(int value)
    {
        node *newNode = new node(value);
        newNode->setNext(head);
        node *nodePtr = head;
        if (head)
        {
            while (nodePtr != tail)
            {
                nodePtr = nodePtr->getNext();
            }
            nodePtr->setNext(newNode);
            tail = newNode;
        }
        else
            insertAtStart(value);
    }
    void insertAtIndex(int idx, int value)
    {
        if (idx < 0)
        {
            cout << endl
                 << "Invalid Index...";
        }
        else
        {
            if (idx == 0)
            {
                insertAtStart(value);
                return;
            }
            node *nodePtr = head;
            node *previous = nullptr;
            while (previous != tail && idx != 0)
            {
                previous = nodePtr;
                nodePtr = nodePtr->getNext();
                idx--;
            }

            if (idx == 0)
            {
                node *newNode = new node(value);
                previous->setNext(newNode);
                newNode->setNext(nodePtr);
                if (previous == tail)
                {
                    tail = newNode;
                }
            }
            else
            {
                cout << endl
                     << "Invalid Index...";
            }
        }
    }
};