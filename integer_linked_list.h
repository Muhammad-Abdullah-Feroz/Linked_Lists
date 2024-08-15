#pragma once
#include <iostream>
#include <conio.h>

using namespace std;

class integerList
{
private:
    struct listNode
    {
        int value;
        listNode *next;
    };
    listNode *head;

public:
    integerList()
    {
        head = nullptr;
    }
    ~integerList();
    void appendNode(int);
    void insertNode(int);
    void deleteNode(int);
    void displayList() const;
};

integerList::~integerList(){
    listNode* nodePtr;
    listNode* nextPtr;

    nodePtr = head;
    while(nodePtr != nullptr){
        nextPtr = nodePtr->next;
        delete nodePtr;
        nodePtr = nextPtr;
    }
}

void integerList::appendNode(int num)
{
    listNode *newNode;
    listNode *nodePtr;

    newNode = new listNode;
    newNode->value = num;
    newNode->next = nullptr;

    if (!head)
    {
        head = newNode;
    }
    else
    {
        nodePtr = head;

        while (nodePtr->next)
        {
            nodePtr = nodePtr->next;
        }

        nodePtr->next = newNode;
    }
}
void integerList::displayList() const
{
    cout << endl;
    if (!head)
    {
        cout << "List is empty..." << endl;
    }
    else
    {
        listNode *ptr;
        ptr = head;
        while (ptr)
        {
            cout << ptr->value << " . ";
            ptr = ptr->next;
        }
    }
}
void integerList::insertNode(int num)
{
    if (!head)
    {
        head->value = num;
        head->next = nullptr;
    }
    else
    {
        listNode *newNode;
        listNode *nodePtr = head;
        listNode *previousNode = nullptr;

        newNode = new listNode;
        newNode->value = num;

        while (nodePtr != nullptr && nodePtr->value < num)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        if (previousNode == nullptr)
        {
            head = newNode;
            newNode->next = nodePtr;
        }
        else
        {
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
}
void integerList::deleteNode(int num)
{
    if (!head)
    {
        cout << endl
             << "List is empty...";
    }
    else
    {
        if (head->value == num)
        {
            listNode *numPtr;
            numPtr = head->next;
            delete head;
            head = numPtr;
        }
        else
        {
            listNode *nodePtr = head;
            listNode *previousNode = nullptr;

            while (nodePtr != nullptr && nodePtr->value != num)
            {
                previousNode = nodePtr;
                nodePtr = nodePtr->next;
            }

            if (nodePtr == nullptr)
            {
                cout << endl
                     << "Vaue not found...";
            }
            else
            {
                previousNode->next = nodePtr->next;
                delete nodePtr;
            }
        }
    }
}
