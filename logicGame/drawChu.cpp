#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdbool.h>
#include <string.h>
#include <asm/ioctls.h>

#define dot_d "/dev/dot"
#define tact_d "/dev/tactsw"

int dot, tact;
unsigned char In;

unsigned char map[8][8];
unsigned char a[8];

int x = 0;
int y = 0;

void light(unsigned char matrix[8][8], int id);
void check();

int main(){
	
	tact = open(tact_d, O_RDWR);
    if(tact < 0){
        printf("open failed! \n");
        return 0;
    }
    while(1){
        while(1){
            read(tact,&In,sizeof(In));
            usleep(100000);
            if(In) {
                break;
            }
        }
        
        switch(In){
        	case 2: //UP
        	x--;
			if(x<0) x=0;
        	
			case 8: //Down
			x++;
			if(x>7) x=7;
			
			case 4: //left
			y--;
			if(y<0) y=0;
			
			case 6: //Right
			y++;
			if(y>7) y=7;
			
			case 5: //Ok
			
			if(map[x][y]=1){
				map[x][y] = 0; //ok 두번 누른 경우 삭제시키기 
			}else{
				map[x][y] = 1;
			}
			
			light(map,1);
			
			case 9: //정답 확인 버튼 
        	//check() 함수
			break;
		}
	}
	return 0;	
}

void light(unsigned char matrix[8][8], int id){
	dot = open(dot_d, O_RDWR);
	unsigned char value = 1;
	unsigned char temp = 0;
	
	// 2차원배열을 1차원배열로 바꿔주는 함수 
	int i, j;
	for(i=0; i<8; i++){
		for(j=8-1; j>=0; j--){
			if(matrix[i][j] == id) temp += value;
			value = value*2;
		}
		a[i] = temp;
		temp = 0;
		value = 1;
	}
	 
	write(dot, &a, sizeof(a));
	unsleep(300000); //led 계속 점등으로 바꾸기 
	close(dot);
}

void check(){
	//정답 배열, map 배열 비교
	// map 배열 초기화 
} 
