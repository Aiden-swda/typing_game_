#include <stdio.h>
#include <windows.h>
void first();
void gotoxy(int x, int y);
#define COLS 120
#define LINES 45


int main()
{
	system("mode con cols=120 lines=45");
	first();

}
void first() //처음 텍스트 출력을 담당할 놈
{
	int i;
	for (i = 1; i <= COLS; i++) //첫 줄 별장식
	{
		printf("*");
	}
	gotoxy(COLS / 2 - 20, LINES/2 - 4);
	printf("건덕이 잡기");
	gotoxy(COLS / 2 - 20, LINES/2 - 3);
	printf("우리 조 이름");
	gotoxy(COLS / 2 - 20, LINES/2 - 2);
	printf("1. 게임 시작");
	gotoxy(COLS / 2 - 20, LINES/2 - 1);
	printf("2. 도움말(첫판 필수)");
	gotoxy(COLS / 2 - 20, LINES/2);
	printf("3. 점수 보기");
	gotoxy(COLS / 2 - 20, LINES/2 + 1);
	printf("4. 게임종료");
	gotoxy(0, COLS);                     //여기부분에 오류가 있는지 커서 이동이 안돼
	for (i = 1; i <= COLS; i++)
	{
		printf("*");
	}

}
void gotoxy(int x, int y)  //요놈이 이제 좌표 지정하는 놈
{
	COORD Cur = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}