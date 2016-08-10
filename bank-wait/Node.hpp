#ifndef Node_hpp
#define Node_hpp

#include "Random.hpp"

#define RANDOM_PARAMETER 100

class Node {
    public :
        int arrive_time;
        int duration;
        Node* next;
    public :
        Node(int arrive_time = 0, int duration = Random::uniform(RANDOM_PARAMETER)):
            arrive_time(arrive_time),
            duration(duration),
            next(nullptr) {}
};

#endif
