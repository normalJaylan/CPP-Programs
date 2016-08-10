#ifndef Random_hpp
#define Random_hpp

#include <cstdlib>
#include <cmath>

class Random {
    public :
        static double uniform(double max = 1) {             // [0, 1)之间服从均匀分布的随机值
            return ((double)std::rand() / (RAND_MAX))*max;
        }
};

#endif
