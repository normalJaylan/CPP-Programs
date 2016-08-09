#ifndef Node_h
#define Node_h

#define RANDOM_PARAMETER 100

#include "Random.hpp"

struct Node {
    int arrive_time;
    int duration;
    Struct Node* next;          

    Node(int arrive_time = 0, int duration = Random::uniform(RANDOM_PARAMETER)):
        arrive_time(arrive_time),
        duration(duration),
        next(nullptr) {}
};

typedef struct Node Node;
typedef struct Node Customer;

#endif
