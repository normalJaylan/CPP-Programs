#define SIZE 8

#include <iostream>
#include <stdlib.h>
#include "struct.h"
#include "horse.h"

using namespace std;

void getXY(int);
void print();

Horse *horse = new Horse();
int x,y;
bool flag = false;

void start() {
    int number(1);
    Struct *head = new Struct();
    Struct *temp;
    cout << "Start X : ";
    cin >> head->x;
    cout << "Start Y : ";
    cin >> head->y;
    head->next = NULL;

    horse->path[head->x][head->y] = number++;
    horse->mark[head->x][head->y] = 0;
    
    while (number <= (SIZE * SIZE)) {

        if (number == (SIZE * SIZE)) {                      //最后一步单独处理
            for (int i(0);i < SIZE;i++) {
                for (int j(0);j < SIZE;j++) {
                    if (horse->mark[i][j] == 1) {
                        head = head->add(i, j, head, 0);
                        horse->path[i][j] = number++;               
                        horse->mark[i][j] = 0; 
                        break;
                    }
                }
            }
            continue;
        }
        
        horse->init();                                          //初始化权值表
        horse->updateWeight(head->x, head->y);                  //更新这一点的权值表

        if (flag) {
            horse->weight[temp->key] == SIZE + 1;
        }

        int key = horse->findSmall();                           //找到权值最小的点

        if (key == -1 && number != (SIZE * SIZE + 1)) {
            horse->mark[head->x][head->y] == 1;
            horse->path[head->x][head->y] == 0;
            number--;
            temp = head;
            head = head->remove(head);
            flag = true;
            continue;
        }

        x = head->x;
        y = head->y;
        getXY(key);                                                 //得到该点对应的坐标
        head = head->add(x, y, head, key);                           //将新走的位置坐标插入链表
//        cout << head->x << " , " << head->y << "     " << number << endl;
        horse->path[head->x][head->y] = number++;
        horse->mark[head->x][head->y] = 0;                     //标记为已走过 
    }
   print();
}

void print() {
    for (int i(0);i < SIZE;i++) {
        for (int j(0);j < SIZE;j++) {
            cout << horse->path[i][j] << "    ";
        }
        cout << "" << endl;
    }
}

void getXY(int key) {
    switch (key) {
        case 0 : x -= 2; y += 1; break;
        case 1 : x -= 1; y += 2; break;
        case 2 : x += 1; y += 2; break;
        case 3 : x += 2; y += 1; break;
        case 4 : x += 2; y -= 1; break;
        case 5 : x += 1; y -= 2; break;
        case 6 : x -= 1; y -= 2; break;
        case 7 : x -= 2; y -= 1; break;
    }
}

int main() {
    start();
    return 0;
}
