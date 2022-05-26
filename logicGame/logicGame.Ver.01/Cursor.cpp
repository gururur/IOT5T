#include <iostream>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <ctime>

#define ENUM_SET

using namespace std;

// coord구조체 사용
#ifndef COORD_SET
typedef struct coord
{
    int y;
    int x;
} coord;
#endif

//ENUM을 활용해서 0,1,2,3,4를 설정, TactSW.cpp와 연관
typedef enum : int
{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    OK
} UDLR;

class Cursor
{
private:
    
    //커서 좌표
    coord currentYX;

    //디버깅용함수
    void printArray(coord A)
    {
        bool M[8][8];
        memset(&M, false, sizeof(bool) * 8 * 8);
        for (coord C : A)
        {
            M[C.y][C.x] = true;
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

    // 도트 매트릭스 위를 벗어나지 못하게 함
    static bool isOnSpace(coord C)
    {
        if (C.y > 7 || C.y < 0 || C.x > 7 || C.x < 0)
        {
            if (C.y > 7)
            {
                C.y = 7
            }
            if (C.y < 0)
            {
                C.y = 0
            }   
            if (C.x > 7)
            {
                C.x = 7
            }   
            if (C.x < 0)
            {
                C.x = 0
            }
            
        }
        return true;
    }

public:

    //커서 방향이동. 다만 snake.cpp에서  그러던데 실습통해 확인해봐야 할듯 함
    // TactSW.cpp 와 연관
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
            //규정된 space내에 위치한다면, 좌표로이동
            currentYX = ret;

            return true;
        }
        return false;
    }

    // 8*8의 판 위에 존재하는 지 확인하는 코드, logicGame.cpp에서 사용
    coord get() { return currentYX;}

};
