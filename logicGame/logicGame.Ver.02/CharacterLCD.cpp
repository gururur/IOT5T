#include<iostream>
#include<fcntl.h>
#include<unistd.h>
#include<string>
#include<cstring>

#define CLCD "/dev/clcd"
using namespace std;

char rhint[4][30] = {"행 : 0 0 0 0 0 0 0 0", 
		     "행 : 11 11 4 121 222 8 22 11", 
		     "행 : 1 0 0 0 0 0 0 0",
		     "행 : 0 0 0 1 0 0 0 0"};	// 행 힌트 
					
char chint[4][30] = {"열 : 0 0 0 0 0 0 0 0",
                     "열 : 2 4 33 4 4 33 4 2",
		     "열 : 0 0 1 0 0 0 0 0",
		     "열 : 0 0 1 0 0 0 0 0"};	// 열 힌트 

class CharacterLCD
{
	private:
		int clcd_fd;
		
		//CharacterLCD에 출력
		void print(string S)
		{
			char *cstr = new char[S.length()+1];
			strcpy(cstr, S.c_str());
			clcd_fd = open(CLCD, O_WRONLY);
			write(clcd_fd, cstr, 32);
			close(clcd_fd);
		 } 
	
	public:
		void beforeGame()	// 게임을 시작하기 전에 출력 
		{
			string s1 = "	Nemo Logic	";
			string s2 = "	Press Start	";
			print(s1+s2);
		}
		
		void gaming(int rnd)
		{
			print(strcat(rhint[rnd], chint[rnd]));
		 } 
		 
		 void endGame(int score)
		 {
		 	string s1 = "점수 : " + score;
		 	print(s1);
		 }
		
};

