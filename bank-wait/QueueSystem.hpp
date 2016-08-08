#ifndef QueueSystem_hpp
#define QueueSystem_hpp

#include "Event.hpp"
#include "Queue.hpp"
#include "ServiceWindow.hpp"

class QueueSystem {
    public :
        QueueSystem(int total_service_time, int window_num);            // 初始化队列系统
        ~QueueSystem();                                                 // 销毁
        void simulate(int simulate_num);                                // 启动模拟
        inline double getAvgStayTime() {
            return avg_stay_time;
        }
        inline double getAvgCustomers() {
            return avg_customers;
        }

    private :
        double run();                       // 让队列系统运行一次
        void init();                        // 初始化各种参数
        void end();                        // 清空各种参数
        int getIdleServiceWindow();        // 获得空闲窗口索引
        void customerArrived();             //处理顾客到达事件
        void customerDeparture();           // 处理顾客离开事件

        int window_num;             // 服务窗口总数
        int total_service_time;     //顾客逗留总时间
        int total_customer_num;     //总顾客数
        
        //核心成员
        ServiceWindow* windows;
        Queue<Customer> customer_list;
        Queue<Event> event_list;
        Event* current_event;

        //给外部调用的结果
        double avg_customers;
        double avg_stay_time;
};

#endif 
