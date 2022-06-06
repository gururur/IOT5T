#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdbool.h>
#include <string.h>
#include <iostream>
#include <string>
#include <cstring>

#define tact_d "/dev/tactsw"
#define DOT_DEV "/dev/dot"
#define CLCD "/dev/clcd"
#define TIME_QUANTUM 1667
#ifndef COORD_SET

int tact;
int head;
int score = 0;
int rnd; // 배열참조용 정수
unsigned char In;
using namespace std;

char rhint[4][32] = {"R : 22 6 6 22    22 6 6 22  ",
             		 "R : 11 11 4 121   222 8 22 11 ",
             		 "R : 1 1 6 11       11 6 1 1   ",
             		 "R : 2 4 6 33       33 6 4 2   "};	// 행 힌트 

char chint[4][32] = {"C : 0 8 8 22       22 8 8 0   ",
                     "C : 2 4 33 4       4 33 4 2   ",
             		 "C : 1 1 6 11      11 6 1 1    ",
             		 "C : 2 4 6 33      33 6 4 2    "};	// 열 힌트 

bool matrixPaper[8][8] = {{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0}};  // 그림 그리기용 매트릭스
			
bool matrixCursor[8][8] = {{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0}};  // 커서 표시용 매트릭스

bool matrixAns[4][8][8] = {
        {
            {0, 1, 1, 0, 0, 1, 1, 0},
            {0, 1, 1, 1, 1, 1, 1, 0},
            {0, 1, 1, 1, 1, 1, 1, 0},
            {0, 1, 1, 0, 0, 1, 1, 0},
            {0, 1, 1, 0, 0, 1, 1, 0},
            {0, 1, 1, 1, 1, 1, 1, 0},
            {0, 1, 1, 1, 1, 1, 1, 0},
            {0, 1, 1, 0, 0, 1, 1, 0}
        },
        {
            {0, 0, 1, 0, 0, 1, 0, 0},
            {0, 0, 1, 0, 0, 1, 0, 0},
            {0, 0, 1, 1, 1, 1, 0, 0},
            {0, 1, 0, 1, 1, 0, 1, 0},
            {1, 1, 0, 1, 1, 0, 1, 1},
            {1, 1, 1, 1, 1, 1, 1, 1},
            {0, 1, 1, 0, 0, 1, 1, 0},
            {0, 0, 1, 0, 0, 1, 0, 0}
        },
        {
            {0, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 1, 1, 1, 1, 1, 1},
            {0, 0, 1, 0, 0, 1, 0, 0},
            {0, 0, 1, 0, 0, 1, 0, 0},
            {1, 1, 1, 1, 1, 1, 0, 0},
            {0, 0, 0, 0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0, 1, 0, 0}
        },
        {
            {0, 0, 0, 1, 1, 0, 0, 0},
            {0, 0, 1, 1, 1, 1, 0, 0},
            {0, 1, 1, 1, 1, 1, 1, 0},
            {1, 1, 1, 0, 0, 1, 1, 1},
            {1, 1, 1, 0, 0, 1, 1, 1},
            {0, 1, 1, 1, 1, 1, 1, 0},
            {0, 0, 1, 1, 1, 1, 0, 0},
            {0, 0, 0, 1, 1, 0, 0, 0}
        }
    }; // 정답지 매트릭스
        
typedef struct coord
{
    int y;
    int x;
} coord;
#endif

class DotMatrix	//도트 매트릭스 함수 
{
private:
    int dot_fd;
    void openDot() { dot_fd = open(DOT_DEV, O_WRONLY); }
    void closeDot() { close(dot_fd); }

public:
    DotMatrix() // 두 매트릭스를 보여줌
    {
        dot_fd = -1;
        memset(matrixPaper, 0, sizeof(bool) * 8 * 8);
        memset(matrixCursor, 0, sizeof(bool) * 8 * 8);
    }
    ~DotMatrix() { close(dot_fd); }

    // matrixPaper 초기화
    void clearPaper() { memset(matrixPaper, 0, sizeof(bool) * 8 * 8); }
    // matrixCursor 초기화
    void clearCursor() { memset(matrixCursor, 0, sizeof(bool) * 8 * 8); }

    // matrixPaper에 그림을 그림
    void draw(coord C) {matrixPaper[C.y][C.x] = true; }
    // matrixPaper에 그려진 그림을 지움
    void erase(coord C) { matrixPaper[C.y][C.x] = false;  }
    
    // 커서의 위치를 출력
    void cursor(coord C) { matrixCursor[C.y][C.x] = true; }

    // matrixPaper의 값 출력
    void drawToPaper(int microSec)
    {
        openDot();
        unsigned char rows[8];
        for (int i = 0; i < 8; i++)
        {
            rows[i] = 0;
            for (int j = 0; j < 8; j++)
            {
                if (matrixPaper[i][j])
                {
                    rows[i] |= 1 << j;
                }
            }
        }
        write(dot_fd, &rows, sizeof(rows));
        usleep(microSec);
        closeDot();
    }

    // matrixCursor의 값 출력
    void drawToCursor(int microSec)
    {
        openDot();
        unsigned char rows[8];
        for (int i = 0; i < 8; i++)
        {
            rows[i] = 0;
            for (int j = 0; j < 8; j++)
            {
                if (matrixCursor[i][j])
                {
                    rows[i] |= 1 << j;
                }
            }
        }
        write(dot_fd, &rows, sizeof(rows));
        usleep(microSec);
        closeDot();
    }
};

class CharacterLCD	// CLCD 함수 
{
private:
    int clcd_fd;

    //CharacterLCD에 출력
    void print(string S)
    {
        char* cstr = new char[S.length() + 1];
        strcpy(cstr, S.c_str());
        clcd_fd = open(CLCD, O_WRONLY);
        write(clcd_fd, cstr, 32);
        close(clcd_fd);
    }

public:
    void beforeGame()	// 게임을 시작하기 전에 출력 
    {
        string s1 = "   Nemo Logic   ";
        string s2 = " Ready to Start ";
        print(s1 + s2);
    }

    void rHint(int rnd)	// 행힌트 출력 
    {
        string s1 = rhint[rnd];
        print(s1);
    }
    void cHint(int rnd)	// 열힌트 출력 
    {
        string s1 = chint[rnd];
        print(s1);
    }
    
    void endGame(int score)	// 점수 출력 
    {
    	string s1 = " score : ";
    	char sc2[9];
    	sprintf(sc2, "%d", score);
        string s2 = sc2;
        print(s1 + s2);
    }
};

int main(){
    	
	DotMatrix DM;
    CharacterLCD CL;
    
    coord ret = {0,0};	// 도트 매트릭스 위치 초기화 
    rnd = rand()%4;		// 시작 시 문제를 무작위로 결정 
	
	tact = open(tact_d, O_RDWR);
    if(tact < 0){
        printf("open failed! \n");
        return 0;
    }
    
    CL.beforeGame();
    sleep(5); //기기를 작동하고 5초 뒤에 게임 시작 
    CL.rHint(rnd);
    
    while(1){
        switch(In){
        	case 1: // 행힌트 출력 
        		CL.rHint(rnd);
        		break;
        	case 3: // 열힌트 출력 
	        	CL.cHint(rnd);
	        	break;
        	
        	//커서를 움직이는 키 
        	case 2: //UP
            	ret.y -= 1;
            	break;
			case 8: //Down
            	ret.y += 1;
            	break;
			case 4: //Left
            	ret.x += 1;
            	break;
			case 6: //Right
            	ret.x -= 1;
            	break;
			
			case 5: //Ok
				DM.draw(ret);
				break;
			
			case 9: //SCORE
				for (int i = 0; i < 8; i++) 
				{
					// 정답지와 작성한 행렬 비교 
		            for (int j = 0; j < 8; j++) 
		            		{
		               			if (matrixPaper[i][j] == matrixAns[rnd][i][j])
		                   			score = score + 1;
		            		}
		        }
	            CL.endGame(score);
	               
	            sleep(5);	 //점수 보여준 뒤 5초 후 재시작
		        DM.clearPaper();
				score=0;
				ret={0,0};
				rnd = rand()%4; 
				CL.rHint(rnd);  //점수 보여준 뒤 재시작(다른 문제 시작)
				break;
			
				case 10:	//재시작
					DM.clearPaper();
					score=0;
					ret={0,0};
					rnd = rand()%4; 
					CL.rHint(rnd);
					break;
				
			
				case 12: 	//ERASE
					DM.erase(ret);
					break;
		}
	
        while(1){
        	DM.clearCursor();
        	DM.cursor(ret);

        	DM.drawToPaper(TIME_QUANTUM * 20);
        	DM.drawToCursor(TIME_QUANTUM * 20);
            read(tact,&In,sizeof(In));
            usleep(100000); //1초 딜레이
            if(In) {
                break;
            		}
        }

	}
	return 0;	
}

//  matrixPaper : 그린 그림의 값을 가지는 8*8 배열
//  matrixCursor : 커서의 위치를 나타내는 8*8 배열
//  clearPaper :  matrixPaper 초기화
//  clearCursor : matrixCursor 초기화
//  draw : 커서가 위치한 좌표와 같은 matrixPaper 배열좌표의 값을 true로 변경 = 그림그림
//  erase : 커서가 위치한 좌표와 같은 matrixPaper 배열좌표의 값을 false로 변경 = 그림지움
//  cursor : 8*8 닷 매트릭스 상에서 커서의 위치를 true로 변경, clearCursor와 while 반복하기 때문에 커서의 위치만 불빛이 켜짐
