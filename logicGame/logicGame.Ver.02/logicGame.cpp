#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "DotMatrixPaper.cpp"
#include "TactSW.cpp"
#include "Cursor.cpp"
#include "CharacterLCD.cpp"

#define TIME_QUANTUM 1667

// x,y 좌표값을 가지는 coord 구조체가 만들어지지 않았으면 만든다.
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
    CharacterLCD clcd;

    //주어진 좌표에 도트 끄고 키기
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
        int rnd = 0;
        // CLCD에 게임시작방법 표시
		printf("game : waiting for user to press start\n");
		clcd.beforeGame(); 
        while (true)
        {
            //커서 위치 반환해 시리얼에 표시
            cursorCoord = c.get();  // TactSW의 get()과 헷갈리지 않도록 주의, Cursor.get()은 위치 확인용
            printf("game : cursor constructed @ y:%d x:%d\n", cursorCoord.y, cursorCoord.x);
            
            //TactSW가 Start버튼을 누를때까지 대기
			while(TSW.get() !=6) {
				rnd = rand()%4;		//정답 행렬 무작위로 고르기 
			}
            
            // cursor 초기화  TSW.get()의 cursor가 안먹혀서 -1 은 주석처리함
            //cursor = -1
            //TSW.get()은 tact switch 누른 것을 반환함
            cursor = TSW.get();

            //cursor 시작좌표 정의  ,  좀 불안한 부분
            temp2 = c.move(cursor);
            printf("game : user selected cursor and game just started\n");
            clcd.gaming(rnd);	// clcd에 힌트 표시하기 
            while (temp2)
            {
                // 20/600초 동안 dotMatrix에 표시
                print(TIME_QUANTUM * 20);

                // 이 순간은 모든 장치가 Close되어있음
                // TactSW의 메소드 get은 장치를 빠른 속도로 열고
                // 장치의 값을 read함, 이동 좌표를 담음
                temp = TSW.get();

                ///////// Tact switch 를 조작했을 때 작동해야 되는 기능들

                //TackSW.cpp 참고, 0~3 은 방향을 뜻하고 그 외의 숫자도 다른 기능으로 존재
                if ((temp >= 0) && (temp < 4))
                {
                    // 그렇다면 진행방향으로 이동
                    cursor = temp;
                }

                // cursor 위치에 점 찍는것도 필요함, 좀 불안한 부분
                if (temp == 4)
                {
                    DMP.set(c.get());
                }
                
                //정답 제출이나 그외 등등 추가로 작성
                if (temp == 5){
                	DMP.checkTheans(rnd);
                	//rnd 0부터 시작, 정답 제출한 뒤 다음 문제로 넘어가기 
                	rnd++;
                	//matirxPaper 배열 초기화 
                	DMP.clear();
				}
            }

        }
    }

    //장비에 출력
    void print(int microSec)
    {
        //커서 위치 점등해서 표시해주는 함수 필요
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

