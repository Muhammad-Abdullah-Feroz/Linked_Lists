#include "circularList.h"

int main()
{
    cList list;
    list.display();
    list.append(5);
    list.append(2);
    list.append(7);
    list.append(6);
    list.append(3);
    list.insertAtIndex(0,5);
    list.insertAtIndex(0,2);
    list.insertAtIndex(2,7);
    list.insertAtIndex(1,6);
    list.insertAtIndex(5,8);
    list.insertAtIndex(4,3);
    list.display();


    _getch();
    return 0;
}