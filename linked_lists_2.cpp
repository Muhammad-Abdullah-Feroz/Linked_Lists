#include"LinkedList.h"
#include<conio.h>

using namespace std;

int main(){
    LinkedList<char> list;
    list.displayList();
    list.appendNode('a');
    list.appendNode('d');
    list.appendNode('f');
    list.displayList();
    list.insertNode('b');
    list.insertNode('h');
    list.displayList();
    list.deleteNode('a');
    list.displayList();
    list.deleteNode('d');
    list.displayList();
    list.deleteNode('h');
    list.displayList();
    list.deleteNode('j');
    list.displayList();
    getche();
    return 0;
}