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

    void display(){
        if(!head){
            cout<<endl<<"The list is empty..."<<endl;
        }else{
            node * nodePtr = head;

            while(nodePtr){
                cout<<nodePtr->getValue()<<" . ";
                nodePtr = nodePtr->getNext();
            }
            cout<<endl;
        }
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
    void insert(int index , int value){
        if (index < 0){
            cout<<endl<<"Invalid index...";
        }
        else if(index == 0)
        {
            if(!head){
                head = new node;
                head->setValue(value);
                head->setNext(nullptr);
            }else{
                node* newNode = new node;
                newNode->setValue(value);
                newNode->setNext(head);
                head = newNode;
            }
        }
        else
        {
            node * nodePtr = head;
            node * newNode = new node;
            node * prev;

            newNode->setValue(value);

            while(nodePtr){
                if (index == 0){
                    break;
                }
                index--;
                prev = nodePtr;
                nodePtr = nodePtr->getNext();
            }

            if(index == 0){
                newNode->setNext(nodePtr);
                prev->setNext(newNode);
            }else{
                cout<<endl<<"Invalid Index...";
            }
        }
    }
};


int main(){
    integerList list;
    list.display();
    list.append(2);
    list.append(5);
    list.append(7);
    list.display();
    list.insert(4,8);
    // list.insert(9);
    list.display();
    // list.delete(2);
    list.display();
    // list.delete(5);
    list.display();
    // list.delete(9);
    list.display();
    // list.delete(11);
    list.display();
    _getch();
    return 0;
}