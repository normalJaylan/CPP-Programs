#include <iostream>
using namespace std;

class Struct {
    public :
        int x;
        int y;
        Struct *next;
    public :
        Struct();
        Struct *add(int a, int b);
};

Struct::Struct() {
    x = y = 0;
}

Struct *Struct::add(int a, int b, Struct *head) {
    Struct *node = new Struct();
    node->x = a;
    node->y = b;
    node->next = head;
    node = head;
    return head;
}

