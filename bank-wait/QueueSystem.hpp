#ifndef QueueSystem_hpp
#define QueueSystem_hpp

#include "Event.hpp"
#include "Queue.hpp"
#include "ServiceWindow.hpp"

class QueueSystem {
    public :
        QueueSystem(int total_service_time, int window_num);
        ~QueueSystem();
        
        void simulate(int simulate_num);
        
        inline double getAvgStayTime() {
            return avg_stay_time;
        }
        inline double getAvgCustomers() {
            return avg_customers;
        }
    private :
        double run();
        void init();
        void end();
        int getIdleServiceWindow();
        void customerArrived();
        void customerDeparture();
        
        int window_num;
        int total_service_time;
        int total_customer_stay_time;
        int total_customer_num;

        ServiceWindow* windows;
        Queue<Node> customer_list;
        Queue<Event> event_list;
        Event* current_event;

        double avg_customers;
        double avg_stay_time;
};

QueueSystem::QueueSystem(int total_service_time, int window_num) {
    this->total_service_time = total_service_time;
    this->window_num = window_num;
    this->total_customer_stay_time = 0;
    this->total_customer_num = 0;
    windows = new ServiceWindow[window_num];
}

QueueSystem::~QueueSystem() {
    delete[] windows;
}

void QueueSystem::simulate(int simulate_num) {
    double sum = 0;
    for (int i=0;i < simulate_num;i++) {
        sum += run();
    }
    avg_stay_time = (double) sum / simulate_num;
    avg_customers = (double) total_customer_num / (total_service_time * simulate_num);
}

void QueueSystem::init() {
    Event* event = new Event;
    current_event = event;
}

double QueueSystem::run() {
    this->init();
    while (current_event) {             
        if (current_event->event_type == -1) {      // 判断当前事件类型
            customerArrived();
        } else {
            customerDeparture();
        }
        delete current_event;

        current_event = event_list.dequeue();       // 从队列中获取新事件
    }
    this->end();
  
    return (double) total_customer_stay_time / total_customer_num;      // 返回用户平均逗留时间
}

void QueueSystem::end() {               // 系统运行结束, 将所有服务窗口设置为空闲,并清空用户等待队列和事件驱动队列
    for (int i(0);i < window_num;i++) {         // 设置所有服务窗口空闲
        windows[i].setIdle();
 //       *(windows + i).setIdle();             测试
    }

    customer_list.clearQueue();         // 清空用户等待队列

    event_list.clearQueue();            // 清空事件驱动队列
}

int QueueSystem::getIdleServiceWindow() {
    for (int i(0);i < window_num;i++) {
        if (windows[i].isIdle()) {
            return i;
        }   
    }
    return -1;
}

void QueueSystem::customerArrived() {
    total_customer_num++;               // 当有用户到来时,用户总数+1
    
    // 生成下一个用户到达事件
    int intertime = Random::uniform(100);   // 下一个用户到达的时间间隔,假设100分钟内一定会出现一个用户

    int time = current_event->occur_time + intertime;   // 下一个用户到达事件 = 当前事件的发生时间 + 下一个用户到达的时间间隔
    Event temp_event(time);
    // 如果下一个用户到达时间小于银行关门事件,把该用户放入到事件驱动队列中
    // 同时将该用户放入等待队列中排队
    if (time < total_service_time) {
        event_list.orderEnqueue(temp_event);
    }
    Node* customer = new Node(current_event->occur_time);
    customer_list.enqueue(*customer);

    // 如果当前有空闲窗口, 直接将该用户送入服务窗口
    int idleIndex = getIdleServiceWindow();
    if (idleIndex >= 0) {
        customer = customer_list.dequeue();
        windows[idleIndex].serveCustomer(*customer);
        windows[idleIndex].setBusy();

        // 用户到达窗口服务时,将该用户的一个离开事件放到事件驱动队列中
        Event temp_event(current_event->occur_time + customer->duration, idleIndex);
        event_list.orderEnqueue(temp_event);
    }
    delete customer;
}

void QueueSystem::customerDeparture() {
    // 如果离开事件发生的时间比服务时间大, 不需要做任何处理
    if (current_event->occur_time < total_service_time) {
        // 用户逗留时间 = 离开时间 - 到达时间
        total_customer_stay_time += current_event->occur_time - windows[current_event->event_type].getCustomerArriveTime();
        // 如果队列中有人等待, 立即服务等待的用户
        if (customer_list.length()) {
            Node* customer;
            customer = customer_list.dequeue();
            windows[current_event->event_type].serveCustomer(*customer);

            // 离开事件
            Event temp_event(
                current_event->occur_time + customer->duration,
                current_event->event_type
            );
            event_list.orderEnqueue(temp_event);
            delete customer;
        } else {
            // 如果等待队列中没有人,且当前窗口的用户离开了,则这个窗口是空闲的
            windows[current_event->event_type].setIdle();
        }
    }
  
}

#endif
