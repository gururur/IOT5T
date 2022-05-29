#include <iostream>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <ctime>

#define ENUM_SET

using namespace std;

// coord����ü ���
#ifndef COORD_SET
typedef struct coord
{
    int y;
    int x;
} coord;
#endif

//ENUM�� Ȱ���ؼ� 0,1,2,3,4,5,6�� ����, TactSW.cpp�� ����
typedef enum : int
{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    OK,
    SUBMIT,	//����� ����, ������İ� �� 
    START	// ���� ���� 
} UDLR;

class Cursor
{
private:
    
    //Ŀ�� ��ǥ
    coord currentYX;

    //�������Լ�
    void printVector(vector<coord> V)
    {
        bool M[8][8];
        memset(&M, false, sizeof(bool) * 8 * 8);
        for (coord current : V)
        {
            M[current.y][current.x] = true;
        }
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                printf("%d", M[i][7 - j]);
            }
            printf("\n");
        }
    }

    // ��Ʈ ��Ʈ���� ���� ����� ���ϰ� ��
    static bool isOnSpace(coord C)
    {
        if (C.y > 7 || C.y < 0 || C.x > 7 || C.x < 0)
        {
            if (C.y > 7)
            {
                C.y = 7;
            }
            if (C.y < 0)
            {
                C.y = 0;
            }   
            if (C.x > 7)
            {
                C.x = 7;
            }   
            if (C.x < 0)
            {
                C.x = 0;
            }
            
        }
        return true;
    }

public:

    //Ŀ�� �����̵�. �ٸ� snake.cpp����  �׷����� �ǽ����� Ȯ���غ��� �ҵ� ��
    // TactSW.cpp �� ����
    bool move(int dot)
    {
        coord ret = currentYX;
        switch (dot)
        {
        case UP:
            ret.y += 1;
            break;

        case DOWN:
            ret.y -= 1;
            break;

        case LEFT:
            ret.x -= 1;
            break;

        case RIGHT:
            ret.x += 1;
            break;

        default:
            break;
        }
        if (isOnSpace(ret))
        {
            //������ space���� ��ġ�Ѵٸ�, ��ǥ���̵�
            currentYX = ret;

            return true;
        }
        return false;
    }

    // 8*8�� �� ���� �����ϴ� �� Ȯ���ϴ� �ڵ�, logicGame.cpp���� ���
    coord get() { return currentYX;}

};
