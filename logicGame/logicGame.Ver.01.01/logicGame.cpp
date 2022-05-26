#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "DotMatrixPaper.cpp"
#include "TactSW.cpp"
#include "logicMap.cpp"
#include "Cursor.cpp"

#define TIME_QUANTUM 1667

// x,y ��ǥ���� ������ coord ����ü�� ��������� �ʾ����� �����.
#ifndef COORD_SET
typedef struct coord
{
    int y;
    int x;
} coord;
#endif

class Game
{
private:
    DotMatrixPaper DMP;
    TactSW TSW;
    Cursor c;
    coord cursorCoord;

    //�־��� ��ǥ�� ��Ʈ ���� Ű��
    void vector2Matrix(vector<coord> V)
    {
        DMP.clear();
        for (coord dot : V)
        {
            DMP.set(dot);
        }
    }

public:
    Game()
    {}
    void start()
    {
        int cursor, temp, temp2;
        
        while (true)
        {
            //Ŀ�� ��ġ ��ȯ�� �ø��� ǥ��
            cursorCoord = c.get();  // TactSW�� get()�� �򰥸��� �ʵ��� ����, Cursor.get()�� ��ġ Ȯ�ο�
            printf("game : cursor constructed @ y:%d x:%d\n", cursorCoord.y, cursorCoord.x);
            
            // cursor �ʱ�ȭ  TSW.get()�� cursor�� �ȸ����� -1 �� �ּ�ó����
            //cursor = -1
            //TSW.get()�� tact switch ���� ���� ��ȯ��
            cursor = TSW.get();

            //cursor ������ǥ ����  ,  �� �Ҿ��� �κ�
            temp2 = c.move(cursor);
            printf("game : user selected cursor and game just started\n");
            while (temp2)
            {
                // 20/600�� ���� dotMatrix�� ǥ��
                print(TIME_QUANTUM * 20);

                // �� ������ ��� ��ġ�� Close�Ǿ�����
                // TactSW�� �޼ҵ� get�� ��ġ�� ���� �ӵ��� ����
                // ��ġ�� ���� read��, �̵� ��ǥ�� ����
                temp = TSW.get();

                ///////// Tact switch �� �������� �� �۵��ؾ� �Ǵ� ��ɵ�

                //TackSW.cpp ����, 0~3 �� ������ ���ϰ� �� ���� ���ڵ� �ٸ� ������� ����
                if ((temp >= 0) && (temp < 4))
                {
                    // �׷��ٸ� ����������� �̵�
                    cursor = temp;
                }

                // cursor ��ġ�� �� ��°͵� �ʿ���, �� �Ҿ��� �κ�
                if (temp == 4)
                {
                    DMP.set(c.get());
                }
                //���� �����̳� �׿� ��� �߰��� �ۼ�
            }

            

        }
    }

    //��� ���

    void print(int microSec)
    {
        //Ŀ�� ��ġ �����ؼ� ǥ�����ִ� �Լ� �ʿ�
        //cursor2Matrix(c.get())
        DMP.drawToMatrix(microSec);

    }
};

int main(int argc, const char* argv[])
{
    Game g;

    printf("starting game...\n");
    g.start();
    printf("ending game...\n");

    return 0;
}

