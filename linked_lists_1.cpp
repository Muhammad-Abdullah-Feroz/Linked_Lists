#include"integer_linked_list.h"

using namespace std;

int main(){
    integerList list;
    list.displayList();
    list.appendNode(2);
    list.appendNode(5);
    list.appendNode(7);
    list.displayList();
    list.insertNode(1);
    list.insertNode(9);
    list.displayList();
    list.deleteNode(2);
    list.displayList();
    list.deleteNode(5);
    list.displayList();
    list.deleteNode(9);
    list.displayList();
    list.deleteNode(11);
    list.displayList();
    getche();
    return 0;
}