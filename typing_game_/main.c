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
void first()  //첫 화면 출력하는 함수
{
	int i;
	for (i = 1; i <= COLS; i++) //첫 째줄 별 출력
	{
		printf("*");
	}
	gotoxy(COLS / 2 - 12, LINES / 2 - 4);
	printf("건덕이 잡기");
	gotoxy(COLS / 2 - 12, LINES / 2 - 3);
	printf("우리 조 이름");
	gotoxy(COLS / 2 - 12, LINES / 2 - 2);
	printf("1. 게임 시작");
	gotoxy(COLS / 2 - 12, LINES / 2 - 1);
	printf("2. 도움말(첫판 필수)");
	gotoxy(COLS / 2 - 12, LINES / 2);
	printf("3. 점수 보기");
	gotoxy(COLS / 2 - 12, LINES / 2 + 1);
	printf("4. 게임종료");
	gotoxy(0, LINES);         //마지막 줄에 별 출력하려했는데 안되네.. 뭐지
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