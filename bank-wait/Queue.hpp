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
        void clearQueue();                  // 清空队列
        T* enqueue(T &node);
        T* dequeue();
        T* orderEnqueue(Event &event);      // 只使用于事件入队
        int length();
    private :
        T* front;
        T* rear;
};

template <typename T>
Queue::Queue() {
    this->front = new T;
    if (!this->front) {
        std::cout << "内存空间申请失败..." << std::endl;
        exit(-1);
    }

    this->front->next = nullptr;
    this->rear = this->front;
}

template <typename T>
Queue::~Queue() {
    this->clearQueue();                 //清空队列中的所有元素

    delete this->front;             //删除头节点

    this->front = this->rear = nullptr;
}

template <typename T>
T* Queue::enqueue(T &node) {                //入队操作
    T* new_node = new T;
    if (!new_node) {
        std::cout << "内存空间申请失败..." << std::endl;
        exit(-1);
    }

    *new_node = node;
    this->rear->next = new_node;
    this->rear = new_node;
    return this->front;
}

template <typename T>                   //出队操作
T* Queue::dequeue() {
    if (!this->front->next) {
        return nullptr;
    }

    T* temp_node;
    temp_node = this->front->next;
    this->front->next = temp_node->next;

    if (this->rear == temp_node) {
        this->rear = this->front;
    }
    return temp_node;                   //释放空间?
}

template <typename T>
T* Queue::orderEnqueue(Event &event) {
    Event* temp = new Event;
    if (!temp) {
        std::cout << "内存空间申请失败..." << std::endl;
    }

    *temp = event;
    if (!this->front->next) {           //如果队列为空,执行入队操作
        this->enqueue(*temp);
    }

    Event* temp_event_list = this->front;

    while (temp_event_list->next && temp_event_list->occur_time < event.occur_time) {
        temp_event_list = temp_event_list->next;
    }

    temp->next = temp_event_list->next;
    temp_event_list->next = temp;

    return this->front;
}

template <template T>
int Queue::length() {
    T* temp_node;
    temp_node = this->front;
    int length = 0;
    while (temp_node) {
        temp_node = temp_node->next;
        lenght++;
    }
    return length;
}

template <typename T>
void Queue::clearQueue() {
    T* temp_node;
    while (this->front->next) {
        temp_node = this->front->next;
        this->front->next = temp_node->next;
        delete temp_node;
    }
}

#endif 
