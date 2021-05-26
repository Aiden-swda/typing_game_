//처음 화면을 출력하는 소스 파일

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
	gotoxy(0, LINES - 5);
	for (i = 1; i <= COLS; i++)
	{
		printf("*");
	}
}

void screen() // 대화창 출력하는 함수
{
	int i, j;

	gotoxy(0, LINES - 15);
	printf("┌");
	for (i = 0; i < COLS_BOX; i++) printf("─");
	printf("┐\n");

	for (j = 0; j < LINES_BOX; j++) {
		printf("│");
		for (i = 0; i < COLS_BOX; i++) printf(" ");
		printf("│\n");
	}

	printf("└");
	for (i = 0; i < COLS_BOX; i++) printf("─");
	printf("┘\n");

	return 0;
}

void print_letter(char *s)
{
	int story_x = 2;
	int story_y = LINES - 14;
	screen();
	gotoxy(story_x, story_y);
	texts(s); // texts함수로 텍스트 출력 천천히하기
	Sleep(1000);
	screen_s(&story_y);  // screen_s함수로 story_y값 전달 후 조건에 따라 story_y값 변경

	return 0;
}
