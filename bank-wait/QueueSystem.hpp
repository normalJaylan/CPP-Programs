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
        int customer_stay_time;
        int total_customer_num;

        ServiceWindow* windows;
        Queue<Node> customer_list;
        Queue<Event> event_list;
        Event* current_event;

        double avg_customers;
        dobule avg_stay_time;
};

#endif
