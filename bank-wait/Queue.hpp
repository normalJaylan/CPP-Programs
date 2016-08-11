#ifndef Queue_hpp
#define Queue_hpp

#include <iostream>
#include <cstdlib>

#include "Event.hpp"

template <typename T>
class Queue {
    public :
        Queue();
        ~Queue();
        void clearQueue();
        T* enqueue(T &node);
        T* dequeue();
        T* orderEnqueue(Event &event);
        int length();
    private :
        T* front;
        T* rear;
};

template <typename T> 
Queue<T>::Queue() {                     //创建头节点
    front = new T;
    if (!front) {
        std::cout << "内存空间申请失败..." << std::endl;
        exit(-1);
    }

    front->next = nullptr;
    rear = front;
}

template <typename T> 
Queue<T>::~Queue() {                //销毁队列
    clearQueue();
    delete(front);
    front = rear = nullptr;
}

template <typename T>
T* Queue<T>::enqueue(T &node) {
    T* new_node = new T;
    if (!new_node) {
        std::cout << "内存空间申请失败..." << std::endl;
        exit(-1);
    }
    new_node = &node;
    rear->next = new_node;
    rear = new_node;
    return front;
}

template <typename T>
T* Queue<T>::dequeue() {
    if (!front) {
        std::cout << "队列为空..." << std::endl;
        return nullptr;
    }

    T* temp;
    temp = front->next;
    front->next = temp->next;

    if (rear == temp) {         // 如果队列中只有一个节点
        rear = front;
    }
    return temp;
}

template <typename T>
T* Queue<T>::orderEnqueue(Event &event) {
    Event* temp = new Event;
    if (!temp) {
        std::cout << "内存空间申请失败..." << std::endl;
        exit(-1);
    }
    temp = &event;

    if (!front->next) {             // 如果队列为空
        rear->next = temp; 
        rear = temp;
        return front;
    }

    Event* temp_event_list = front;
    
    while (temp_event_list->next && temp_event_list->next->occur_time < event.occur_time) {
        temp_event_list = temp_event_list->next;
    }
    
    temp->next = temp_event_list->next;         // 将事件插入队列
    temp_event_list->next = temp;

    return front;
}

template <typename T>
int Queue<T>::length() {
    T* temp;
    temp = front->next;
    int length = 0;
    while (temp) {
        temp = temp->next;
        length++;
    }
    return length;
}

template <typename T>
void Queue<T>::clearQueue() {
    T* temp;
    while (front->next) {
        temp = front->next;
        front->next = temp->next;
        delete(temp);
    }

    front->next = nullptr;
    rear = front;
}

#endif
