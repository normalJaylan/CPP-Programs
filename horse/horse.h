#define SIZE 8

#include <iostream>
#include "struct.h"

using namespace std;

class Horse {
    public :
        int path[SIZE][SIZE];
        int mark[SIZE][SIZE];
        int weight[SIZE];
    public :
        Horse();
        int getWeight(int x, int y);
        void updateWeight(int x, int y);
};

Horse::Horse() {
    for (int i(0);i < SIZE;i++) {
        for (int j(0);j < SIZE;j++) {
            path[i][j] = 0;
            mark[i][j] = 1;
        }
        weight[i] = -1;
    }
}

void Horse::updateWeight(int x, int y) {
    weight[0] = getWeight(x-2, y+1);
    weight[1] = getWeight(x-1, y+2);
    weight[2] = getWeight(x+1, y+2);
    weight[3] = getWeight(x+2, y+1);
    weight[4] = getWeight(x+2, y-1);
    weight[5] = getWeight(x+1, y-2);
    weight[6] = getWeight(x-1, y-2);
    weight[7] = getWeight(x-2, y-1);
}

int Horse::getWeight(int x, int y) {
    int weight(0);
    if ((x - 2) > -1 && (y + 1) < SIZE && mark[x-2][y+1] == 1) {
        weight++;    
    }
    if ((x - 1) > -1 && (y + 2) < SIZE && mark[x-1][y+2] == 1) {
        weight++;
    }
    if ((x + 1) < SIZE && (y + 2) < SIZE && mark[x+1][y+2] == 1) {
        weight++;
    }
    if ((x + 2) < SIZE && (y + 1) < SIZE && mark[x+2][y+1] == 1) {
        weight++;
    }
    if ((x + 2) < SIZE && (y - 1) > -1 && mark[x+2][y-1] == 1) {
        weight++;
    }
    if ((x + 1) < SIZE && (y - 2) > -1 && mark[x+1][y-2] == 1) {
        weight++;
    }
    if ((x - 1) > -1 && (y - 2) > -1 && mark[x-1][y-2] == 1) {
        weight++;
    }
    if ((x - 2) > -1 && (y - 1) > -1 && mark[x-2][y-1] == 1) {
        weight++;
    }
    return weight;
}
