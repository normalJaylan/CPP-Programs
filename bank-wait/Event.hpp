#ifndef Event_hpp
#define Event_hpp

#include "Random.hpp"
#define RANDOM_PARAMETER 100

class Event {
    public :
        int occur_time;
        int event_type;     // -1表示到达事件, >=0 表示离开事件, 同时数值表示离开的服务窗口

        Event* next;

        Event(int occur_time = Random::uniform(RANDOM_PARAMETER), int event_type = -1):
            occur_time(occur_time),
            event_type(event_type),
            next(nullptr) {}
};

#endif
