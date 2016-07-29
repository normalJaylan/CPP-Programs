#define MAX 50

#include <iostream>
using namespace std;

class Struct {
    public :
        Struct *next;
        int x;
        int y;
    public :
        Struct();
        Struct *add(int x, int y, Struct *head);
        Struct *remove(Struct *head);
};

Struct::Struct() {
    x = y = 0;
}

Struct *Struct::add(int a, int b, Struct *head) {
    Struct *node = new Struct();
    node->x = a;
    node->y = b;
    node->next = head;
    head = node;
    return head;
}

Struct *Struct::remove(Struct *head) {
    Struct *temp = head;
    head = head->next;
    delete(temp);
    return head;
}


