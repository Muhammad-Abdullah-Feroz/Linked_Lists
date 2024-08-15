#include"dual_linkedLists.h"

using namespace std;

int main(){
    dual_linkedLists<char> list;
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
    cout<<endl<<"end";
    getche();
    return 0;
}


/*
Correct Order

Correct Order
a . d . f .
Correct Order
a . b . d . f . h .
Correct Order
b . d . f . h .
Correct Order
b . f . h .
Correct Order
b . f .
Not found...

Correct Order
b . f .
*/