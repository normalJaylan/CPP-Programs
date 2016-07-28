#define MAX 5

#include <iostream>
using namespace std;



template<class T>
class stack {
private :
	int top;
	int font;
	T data[MAX];
public :
	stack();
	void push(T data);
	T pop();
	bool isEmpty();
};

template<class T>
stack<T>::stack() {
	top = font = 0;
}

template<class T>
void stack<T>::push(T x) {
	if (top == 5) {
		cout << "stack full" << endl;
		return ;
	}
	data[top++] = x;
}

template<class T>
T stack<T>::pop() {
	if (top <= 0) {
		cout << "stack empty" << endl;
		exit(0);
	}
	return data[--top];
}

template<class T>
bool stack<T>::isEmpty() {
	if (top <= 0)
		return true;
	else
		return false;
}

int main() {
	stack<int> sta;
/*
	sta.push(9);
	sta.push(7);
	sta.push(5);
	sta.push(3);
	sta.push(1);
*/
	sta.push(1);
	sta.push(2);
	
	cout << sta.pop() << endl;
	cout << sta.pop() << endl;
	cout << sta.pop() << endl;

/*	while (!sta.isEmpty()) {
		cout << sta.pop() << endl;
	}
*/
	return 0;
}

