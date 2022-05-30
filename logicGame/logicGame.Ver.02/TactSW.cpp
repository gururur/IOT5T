#include <iostream>
#include <fcntl.h>
#include <unistd.h>

static char tactswDev[] = "/dev/tactsw";

class TactSW
{
private:
public:
    int get()
    {
        unsigned char b;
        int tactswFd = -1;
        tactswFd = open(tactswDev, O_RDONLY);
        read(tactswFd, &b, sizeof(b));
        close(tactswFd);

        // return°ªµéÀº cursor.cpp¿Í ¿¬°üµÊ
        switch (b)
        {
        case 2:
            return 0; //UP
        case 4:
            return 2; //LEFT
        case 5:
            return 4; //OK
        case 6:
            return 3; //RIGHT
        case 8:
            return 1; //DOWN
        case 9:
	    return 5; //SUBMIT 
	case 1:
	    return 6; //START

        default:
            return -1;
        }
    }
};
