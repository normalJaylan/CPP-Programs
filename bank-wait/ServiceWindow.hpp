#ifndef ServiceWindow_hpp
#define ServiceWindow_hpp

#include "Node.hpp"

enum WindowStatus {
    SERVICE,
    IDLE,
};

class ServiceWindow {
    public :
        inline ServiceWindow() {
            window_status = SERVICE;
        }
        inline bool isIdle() const {
            if (window_status == IDLE) {
                return true;
            } else {
                return false;
            }
        }
        inline void serveCustomer(Node &customer) {
            this->customer = &customer;
        }
        inline void setBusy() {
            window_status = SERVICE;
        }
        inline void setIdle() {
            window_status = IDLE;
        }
        inline int getCustomerArriveTime() const {
            return customer->arrive_time;
        }
        inline int getCustomerDuration() const {
            return customer->duration;
        }
    private :
        Node* customer = new Node();
        WindowStatus window_status;
};

#endif
