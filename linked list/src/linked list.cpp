#include <iostream>
using namespace std;

template<class T>
class Node {
public :
	Node() {

	}
	Node<T> *next;
	T data;
};

template<class T>
class list {
public :
	list();
	void add(T x);
	void print();
	void headinsert(T x);
	void insert(T x ,int number);
	void Delete(T x);
	Node<T> *find(T x);
private :
	int length;
	Node<T> *node;
	Node<T> *head;
	Node<T> *last;
};

template<class T>
list<T>::list() {
	node = NULL;
	head = NULL;
	last = NULL;
	length = 0;
}

template<class T>
void list<T>::add(T x) {
	node = new Node<T>();
	node->data = x;
	if (last == NULL) {
		last = node;
		head = node;
	} else {
		last->next = node;
		last = node;
	}
	length++;
}

template<class T>
void list<T>::print() {
	node = head;
	while (node != NULL) {
		cout << node->data << endl;
		node = node->next;
	}
}

template<class T>
void list<T>::headinsert(T x) {
	node = new Node<T>();
	node->data = x;
	if (head == NULL) {
		head = node;
	} else {
		node->next = head;
		head = node;
	}
}

template<class T>
void list<T>::insert(T x, int number) {
	node = head;
	Node<T> *temp = new Node<T>();
	temp->data = x ;
	for (int i=1;i<number;i++) {
		node = node->next;
	}
	temp->next = node->next;
	node->next = temp;
}

template<class T>
void list<T>::Delete(T x) {	Node<T> *temp = new Node<T>();
	node = head;
	Node<T> *temp;
	if (x == head->data) {
		head = node->next;
		return ;
	}
	while (node != NULL && node->data != x) {
		temp = node;
		node = node->next;
	}
	temp->next = node->next;
	delete(node);
}

template<class T>
Node<T> *list<T>::find(T x) {
	node = head;
	while (node != NULL && node->data != x) {
		node = node->next;
	}
	return node;
}

int main() {

	return 0;
}
