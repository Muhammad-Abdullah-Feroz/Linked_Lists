#pragma once
#include<iostream>

using namespace std;

template <class T>
class LinkedList
{
private:
    struct listNode
    {
        T value;
        listNode *next;
    };
    listNode *head;

public:
    LinkedList()
    {
        head = nullptr;
    }
    ~LinkedList();
    void appendNode(T);
    void insertNode(T);
    void deleteNode(T);
    void displayList() const;
};

template <class T>
LinkedList<T>::~LinkedList(){
    listNode* nodePtr;
    listNode* nextPtr;

    nodePtr = head;
    while(nodePtr != nullptr){
        nextPtr = nodePtr->next;
        delete nodePtr;
        nodePtr = nextPtr;
    }
}

template <class T>
void LinkedList<T>::appendNode(T num)
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

template <class T>
void LinkedList<T>::displayList() const
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

template <class T>
void LinkedList<T>::insertNode(T num)
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

template <class T>
void LinkedList<T>::deleteNode(T num)
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
