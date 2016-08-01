#define SIZE 8

#include <iostream>
using namespace std;

class Struct {
    public :
        int x;
        int y;
        int key;
        Struct *next;
    public :
        Struct();
        Struct *add(int a, int b, Struct *head, int k);
        Struct *remove(Struct *head);
        void print(Struct *head);
};

Struct::Struct() {
    x = y = 0;
}

void Struct::print(Struct *head) {
    for (int i(0);i < SIZE;i++) {
        for (int j(0);j < SIZE;j++) {
            cout << head->x << " , " << head->y << endl;
        }
    }
}

Struct *Struct::add(int a, int b, Struct *head, int k) {
    Struct *node = new Struct();
    node->x = a;
    node->y = b;
    node->key = k;
    node->next = head;
    head = node;
    return head;
};

Struct *Struct::remove(Struct *head) {
    Struct *node = head;
    head = head->next;
    delete(node);
    return head;
}

