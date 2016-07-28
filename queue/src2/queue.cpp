#define MAX 5

#include <iostream>
#include <stdlib.h>
using namespace std;

template<class T>
class Queue {
    public :
        int front;
        int rear;
        T data[MAX];
        char operate;
    public :
        Queue();
        void in(T x);
        T out();
        bool isEmpty();
        void print();
};

template<class T>
 Queue<T>::Queue() {
    front = rear = 0;
    operate = '-';
 }

template<class T>
void Queue<T>::in(T x) {
    if (rear == front && operate == '+') {
        print();
        cout << "queue full" << endl;
        exit(0);
    } else {
        data[front] = x;
        front = (front + 1) % MAX;
        operate = '+';
    }
}

template<class T>
T Queue<T>::out() {
    if (isEmpty()) {
        cout << "queue empty" << endl;
        exit(0);
    } else {
        T x = data[rear];
        rear = (rear + 1) % MAX;
        operate = '-';
        return x;
    }
}

template<class T>
bool Queue<T>::isEmpty() {
    return (rear == front && operate == '-');
}

template<class T>
void Queue<T>::print() {
    if (isEmpty()) {
        cout << "queue empty" << endl;
        exit(0);
    } else {
        int i,j;
        if (rear == front && operate == '+')
            front = MAX;
        if (rear > front) {
            i = front;
            j = rear;
        } else {
            i = rear;
            j = front;
        }
        for (i;i<j;i++) {
            cout << data[i] << endl;
        }
    }
}

int main() {
    Queue<string> queue;
    queue.print();
    return 0;
}
