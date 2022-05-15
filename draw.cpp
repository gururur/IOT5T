#include<stdio.h>
#include<stdlib.h>
#include<fontl.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdbool.h>
#include<string.h>
#include<asm/ioctls.h>

#define dot_d "/dev/dot"		// dot_matrix�� �������� �ּ�
#define tact_d "/dev/tactsw"	// tactsw�� �������� �ּ�

int dot, tact;					// �ش���ġ�� ����Ʈ���� ���� ����
unsigned char In;				// read �Լ��� tactsw�� ���� �޾ƿ� ������ ����

unsigned char map[8][8];		//  �׸��� �׸��� ���� ������ 2���� �迭
unsinged char a[8];				// 2���� �迭���� 8��Ʈ 8���� 1�����迭�� ����� dot_matrix�� ǥ��
 
char flag = 1;					// flag�� ���°� 1�� �� : �ప�� ��ư���� ����
								// flag�� ���°� 0�� �� : ������ ��ư���� ����
int x,y;						// ��İ� ����

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
	
	// 2�����迭�� 1�����迭�� �ٲ��ִ� �Լ� 
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
	
	//1�������� �ٲ� ���� ��Ʈ��Ʈ������ ǥ�� 
	write(dot, &a, sizeof(a));
	unsleep(500000); // led�� 0.5�ʵ��� ����ǵ��� �ϱ� 
	close(dot);
}

// x��ǥ�� y��ǥ�� �޴� �Լ�
void input_vector(int scal){
	if(flag == 1){
		x=scal;
	}
	if(flag == 2){
		y = scal;
	}
} 

void config_input(){
	flag = 2;	// x���� ������ Ȯ�� ��ư�� ������ y�� �Է��ϵ��� flag�� 2�� ���� 
}
