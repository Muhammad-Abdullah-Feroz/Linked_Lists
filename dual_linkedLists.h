#include <iostream>
#include <conio.h>

using namespace std;

template <class T>
class dual_linkedLists
{
private:
    struct node
    {
        T value;
        node *next;
        node *prev;
    };
    node *head;

public:
    dual_linkedLists();
    ~dual_linkedLists();
    void appendNode(T);
    void displayList() const;
    void insertNode(T);
    void deleteNode(T);
};

template <class T>
dual_linkedLists<T>::dual_linkedLists()
{
    head = nullptr;
}

template <class T>
dual_linkedLists<T>::~dual_linkedLists()
{
    node *nextPtr;
    node *nodePtr;
    if (head)
    {
        nodePtr = head;
        while(nodePtr != nullptr){
            nextPtr = nodePtr->next;
            delete nodePtr;
            nodePtr = nextPtr;
        }
    }
}

template <class T>
void dual_linkedLists<T>::appendNode(T value)
{
    node *newNode;
    node *nodePtr;

    newNode = new node;

    newNode->value = value;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        newNode->prev = nullptr;
        head = newNode;
    }
    else
    {
        nodePtr = head;

        while (nodePtr->next != nullptr)
        {
            nodePtr = nodePtr->next;
        }

        newNode->prev = nodePtr;

        nodePtr->next = newNode;
    }
}

template <class T>
void dual_linkedLists<T>::displayList() const
{
    node *nodePtr;

    nodePtr = head;
    cout << endl
         << "Correct Order" << endl;
    while (nodePtr != nullptr)
    {
        cout << nodePtr->value << " . ";
        if (nodePtr->next != nullptr)
            nodePtr = nodePtr->next;
        else
            break;
    }
    cout << endl
         << endl
         << "Reverse Order" << endl;

    while (nodePtr != nullptr)
    {
        cout << nodePtr->value << " . ";
        nodePtr = nodePtr->prev;
    }
}
template <class T>
void dual_linkedLists<T>::insertNode(T value)
{
    // Create the new node and set its value
    node *newNode = new node;
    newNode->value = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    // Case 1: List is empty, insert the first node
    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    node *nodePtr = head;

    // Traverse the list to find the correct insertion point
    while (nodePtr != nullptr && nodePtr->value < value)
    {
        nodePtr = nodePtr->next;
    }

    // Case 2: Insert at the beginning (before the current head)
    if (nodePtr == head)
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    // Case 3: Insert at the end (after the last node)
    else if (nodePtr == nullptr)
    {
        node *last = head;
        while (last->next != nullptr)
        {
            last = last->next;
        }
        last->next = newNode;
        newNode->prev = last;
    }
    // Case 4: Insert in the middle (between two nodes)
    else
    {
        newNode->prev = nodePtr->prev;
        newNode->next = nodePtr;
        nodePtr->prev->next = newNode;
        nodePtr->prev = newNode;
    }
}

template <class T>
void dual_linkedLists<T>::deleteNode(T value)
{
    if (head == nullptr)
    {
        cout << endl
             << "List is empty...";
        return;
    }

    node *nodePtr = head;
    // node* previous = nullptr;
    // node* next = nullptr;

    if (head->value == value)
    {
        head = head->next;
        head->prev = nullptr;
        delete nodePtr;
    }
    else
    {
        // nodePtr = head;
        while (nodePtr != nullptr && nodePtr->value != value)
        {
            nodePtr = nodePtr->next;
        }

        if (nodePtr == nullptr)
        {
            cout << endl
                 << "Not found..." << endl;
        }
        else
        {

            if (nodePtr->prev != nullptr)
            {
                nodePtr->prev->next = nodePtr->next;
            }
            if (nodePtr->next != nullptr)
            {
                nodePtr->next->prev = nodePtr->prev;
            }

            delete nodePtr;
        }
    }
}
