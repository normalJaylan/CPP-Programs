#define SIZE 15

#include <iostream>
#include <stdlib.h>
#include "struct.h"
using namespace std;

Struct *move(int x, int y);
void print();
void start();

int maze[SIZE][SIZE] = {0};         //-1: 走不通; 0: 不能走; 1: 可以走; 2: 已走过
Struct *head = new Struct();

void createMaze() {
    maze[0][0] = maze[1][0] = maze[1][1] = maze[2][1] = maze[3][1] = maze[4][1] = maze[5][1] = maze[5][2] = maze[5][3] = maze[5][4] =
    maze[5][5] = maze [5][6] = maze[5][7] = maze[4][7] = maze[3][7] = maze[3][8] = maze[3][9] = maze[3][10] = maze[3][11] = maze[4][11] = 
    maze[5][11] = maze[6][11] = maze[7][11] = maze[8][11] = maze[9][11] = maze[9][10] = maze[9][9] = maze[9][8] = maze[9][7] = maze[9][6] = 
    maze[9][5] = maze[10][5] = maze[11][5] = maze[12][5] = maze[13][5] = maze[13][6] = maze[14][6] = maze[14][7] = maze[14][8] = maze[14][9] =
    maze[14][10] = maze[13][10] = maze[12][10] = maze[12][11] = maze[12][12] = maze[13][12] = maze[13][13] = maze[13][14] = maze[14][14] = 1;
    maze[0][2] = maze[3][5] = maze[4][5] = maze[3][2] = maze[6][1] = maze[7][1] = maze[8][1] = maze[9][1] = maze[10][1] = 1;
    
}

void print() {
    for (int i(0);i<SIZE;i++) {
        for (int j(0);j<SIZE;j++) {
            if (maze[i][j] == 0) 
                cout << " 1";
            else 
                cout << "  ";
        }
        cout << "" << endl;
    }
}

void start() {
    head->x = 0;
    head->y = 0;
    head->next = NULL;

    head = move(head->x, head->y);

    while (true) {
       head =  move(head->x, head->y);
       if (head == NULL) {                                      //没有通路,退出程序
           cout << "迷宫没有通路..." << endl;
           exit(0);
       }
       if ((head->x == SIZE - 1) && (head->y == SIZE - 1)) {     //找到通路,打印路线
           cout << "存在通路" << endl;
           exit(0); 
       }
    }    
}



Struct *move(int x, int y) {
    int a, b;
    a = b = 15;
    if ((y + 1) < SIZE && maze[x][y+1] == 1) {            //选择下一步方向,优先选择右下
        a = x;
        b = y + 1;
    //    cout << "右" << endl;
    }
    else if ((x + 1) < SIZE && maze[x+1][y] == 1) {
        a = x + 1;
        b = y;
  //      cout << "下" << endl;
    }
    else if ((y -1) > -1 && maze[x][y-1] == 1) {
        a = x;
        b = y - 1;
   //     cout << "左" << endl;
    }
    else if ((x - 1) > -1 && maze[x-1][y] == 1) {
        a = x - 1;
        b = y;
  //      cout << "上" << endl;
    }
    if (a == 15 && b == 15) {                         //无路可走,需要回退
        maze[x][y] = -1;
        head = head->remove(head);
    } else {
        cout << a << " , " << b << endl;
        maze[x][y] = 2;
        head = head->add(a, b, head);                 //有路可走,坐标入栈
    }
    return head;
}

int main() {
    createMaze();
    start();    
//    print();
}
