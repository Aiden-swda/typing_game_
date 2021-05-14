//스토리는 여기에 구현하기

#include "main.h"

void first()  //첫 화면 출력하는 함수
{
	int i;
	for (i = 1; i <= COLS; i++) //첫 째줄 별 출력
	{
		printf("*");
	}
	gotoxy(COLS / 2 - 12, LINES / 2 - 6);
	printf("  ");
	ColorSet(94);
	printf("<건덕이 잡기>");
	ColorSet(7);
	gotoxy(COLS / 2 - 12, LINES / 2 - 5);
	printf("우리 조 이름");
	gotoxy(COLS / 2 - 12, LINES / 2 - 3);
	printf("1. 게임 시작");
	gotoxy(COLS / 2 - 12, LINES / 2 - 2);
	printf("2. 도움말(첫판 필수)");
	gotoxy(COLS / 2 - 12, LINES / 2 - 1);
	printf("3. 점수 보기");
	gotoxy(COLS / 2 - 12, LINES / 2);
	printf("4. 게임종료\n");
	gotoxy(COLS / 2 - 12, LINES / 2 + 2);
	printf("입력:");
	gotoxy(0, LINES-5);
	for (i = 1; i <= COLS; i++)
	{
		printf("*");
	}

}
void gotoxy(int x, int y)  //요게 이제 커서 위치 조정
{
	COORD Cur = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}
void ColorSet(int color_number)  //글자 색, 배경 색 바꾸는 함수
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, color_number);
}