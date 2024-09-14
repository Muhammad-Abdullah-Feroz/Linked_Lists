#include "dLinkedLists.h"

int main()
{
    dList list;
    list.display();
    list.insertAtStart(5);
    list.insertAtStart(2);
    list.insertAtStart(7);
    list.insertAtStart(6);
    list.insertAtStart(3);
    // list.append(5);
    // list.append(2);
    // list.append(7);
    // list.append(6);
    // list.append(3);
    list.display();
    list.insert(3, 83);
    list.insert(0, 80);
    list.insert(9, 89);
    list.insert(7, 87);
    list.display();
    // // list.insert(9);
    // list.display();
    // // list.delete(2);
    // list.display();
    list.deleteNode(5);
    // list.display();
    list.deleteNode(80);
    list.deleteNode(87);
    // list.display();
    // list.insertAtEnd(11);
    // list.insertAtBegin(11);
    list.display();
    // list.update(9, 3);
    // list.display();

    // list.search(5);
    // list.search(11);
    // list.search(8);
    // list.sort();
    // list.display();
    list.reverse();
    list.display();


    _getch();
    return 0;
}