#include<stdio.h>
#include<stdlib.h>
#include<fontl.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdbool.h>
#include<string.h>
#include<asm/ioctls.h>

#define dot_d "/dev/dot"		// dot_matrix의 가상파일 주소
#define tact_d "/dev/tactsw"	// tactsw의 가상파일 주소

int dot, tact;					// 해당장치를 마운트해줄 변수 공간
unsigned char In;				// read 함수로 tactsw의 값을 받아와 저장할 변수

unsigned char map[8][8];		//  그림을 그리기 위해 생성한 2차원 배열
unsinged char a[8];				// 2차원 배열값을 8비트 8개의 1차원배열로 만들어 dot_matrix에 표시
 
char flag = 1;					// flag의 상태가 1일 때 : 행값을 버튼으로 받음
								// flag의 상태가 0일 때 : 열값을 버튼으로 받음
int x,y;						// 행렬값 저장

void config_input();
void input_vector(int scal);
void light(unsigned char matrix[8][8]);

int main(){
	tact = open(tact_d, O_RDWR);
	if(tact<0){
		printf("open failed \n");
		return 0;
	}
	while(1){
		while(1){
			read(tact, &In, sizeof(In));
			unsleep(100000);
			if(In){
				break;
			}
		}
		if(In==9)
			config_input();
	}
	return 0;
} 

void light(unsigned char matrix[8][8]){
	dot = open(dot_d, O_RDWR);
	unsigned char value - 1;
	unsigned char temp = 0;
	
	// 2차원배열을 1차원배열로 바꿔주는 함수 
	int i, j;
	for(i=0; i<8; i++){
		for(j=8-1; j>=0; j--){
			if(matrix[i][j] == id) temp += value;
			if(id == 3){
				if(matrix[i][j] > 0 && matrix[i][j] < 3)
				temp += value;
			}
			value = value*2;
		}
		a[i] = temp;
		temp = 0;
		value = 1;
	}
	
	//1차원으로 바꾼 값을 도트매트릭스에 표시 
	write(dot, &a, sizeof(a));
	unsleep(500000); // led가 0.5초동안 점등되도록 하기 
	close(dot);
}

// x좌표와 y좌표를 받는 함수
void input_vector(int scal){
	if(flag == 1){
		x=scal;
	}
	if(flag == 2){
		y = scal;
	}
} 

void config_input(){
	flag = 2;	// x값을 누르고 확인 버튼을 누르면 y값 입력하도록 flag를 2로 증가 
}
