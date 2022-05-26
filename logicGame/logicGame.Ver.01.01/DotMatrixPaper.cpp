
#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstdlib>

#define DOT_DEV "/dev/dot"
#define COORD_SET
typedef struct coord  //coord 구조체는 x,y 위치를 가지는 구조체
{
    int y;
    int x;
} coord;

class DotMatrixPaper
{
private:
    int dot_fd;
    bool matrixPaper[8][8];

    void openDot() { dot_fd = open(DOT_DEV, O_WRONLY); }
    void closeDot() { close(dot_fd); }

public:
    DotMatrixPaper()
    {
        dot_fd = -1;
        memset(matrixPaper, 0, sizeof(bool) * 8 * 8); // matrix 행렬 모든 값을 0으로 세팅
    }
    ~DotMatrixPaper() { close(dot_fd); }

    // 모든 매트릭스 초기화
    void clear() { memset(matrixPaper, 0, sizeof(bool) * 8 * 8); }
    // tact switch 5번 버튼을 누를 때마다 닷 매트릭 led를 켜고 끄게 함
    void set(coord C) { matrixPaper[C.y][C.x] = !matrixPaper[C.y][C.x]; }

    // 시리얼로 출력 -> 디버깅용
    void printToSerial()
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                printf(matrixPaper[i][j] ? "* " : "o ");
            }
            printf("\n");
        }
    }

    // 매트릭스로 출력
    void drawToMatrix(int microSec)
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
};
