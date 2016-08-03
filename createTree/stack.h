#define MAX 50

#include <iostream>
using namespace std;

template<class T>
class Stack {
    public :
        int top;
        T* data[MAX];
    public :
        Stack();
        void add(T *address);
        T *remove();
        bool isEmpty();
};

template<class T>
Stack<T>::Stack() {
    top = 0;
}

template<class T>
void Stack<T>::add(T *address) {
    data[top++] = address;
}

template<class T>
T *Stack<T>::remove() {
    return (data[--top]);
}

template<class T>
bool Stack<T>::isEmpty() {
    return (top == 0);
}
