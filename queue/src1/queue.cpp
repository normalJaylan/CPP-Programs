#define MAX 10

#include <iostream>
#include <stdlib.h>
using namespace std;

template<class T>
class Queue {
    private :
        int front;
        int rear;
        T data[MAX];
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
}

template<class T>
void Queue<T>::in(T x) {
    if (front == MAX) {
        print();
        cout << "queue full" << endl;
        exit(0);
    } else {
        data[front++] = x;
    }
}

template<class T>
T Queue<T>::out() {
    if (front == rear) {
        cout << "queue empty" << endl;
        exit(0);
    } else {
        return data[rear++];
    }
}

template<class T>
bool Queue<T>::isEmpty() {
    return (front == rear);
}

template<class T>
void Queue<T>::print() {
    if (isEmpty()) {
        cout << "queue empty" << endl;
        exit(0);
    } else {
        for (int i(rear);i < front; i++) {
            cout << data[i] << endl;
        }
    }
}

int main()
{
    Queue<char> queue;
    string str = "Jaylan";
    for (char s : str) {
        queue.in(s);
    }
/* 
    queue.in('a');
    queue.in('b');
    queue.in('c');
    char x =  queue.out();
    cout << x << endl;
    queue.in('d');
*/
    queue.print();
    return 0; 
}
