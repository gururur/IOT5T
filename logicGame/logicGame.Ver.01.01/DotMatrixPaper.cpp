
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
typedef struct coord  //coord ����ü�� x,y ��ġ�� ������ ����ü
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
        memset(matrixPaper, 0, sizeof(bool) * 8 * 8); // matrix ��� ��� ���� 0���� ����
    }
    ~DotMatrixPaper() { close(dot_fd); }

    // ��� ��Ʈ���� �ʱ�ȭ
    void clear() { memset(matrixPaper, 0, sizeof(bool) * 8 * 8); }
    // tact switch 5�� ��ư�� ���� ������ �� ��Ʈ�� led�� �Ѱ� ���� ��
    void set(coord C) { matrixPaper[C.y][C.x] = !matrixPaper[C.y][C.x]; }

    // �ø���� ��� -> ������
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

    // ��Ʈ������ ���
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
