//스토리는 여기에 구현하기

#include "main.h"


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

void texts(char text[]) // 텍스트 출력시간
{
	for (int i = 0; i < strlen(text); i++)
	{
		printf("%c", text[i]);
		Sleep(80);
	}
}

void story() // 스토리 출력 방식 예시 (나중에 변경해서 사용)
{
	int story_x = 2;
	int story_y = LINES - 14;

	gotoxy(story_x, story_y);
	char story1[] = "[system : 게임이 시작됩니다.]";
	texts(story1);
	Sleep(1000);
	screen_s(&story_y);

	gotoxy(story_x, story_y);
	char story2[] = "[system : 이번 난이도를 클리어하셨습니다.]";
	texts(story2);
	Sleep(1000);
	screen_s(&story_y);

	gotoxy(story_x, story_y);
	char story3[] = "[system : 체력이 1 소모되었습니다.]";
	texts(story3);
	Sleep(1000);
	screen_s(&story_y);

	gotoxy(story_x, story_y);
	char story4[] = "[system : 콤보 성공! 추가 점수를 획득합니다.]";
	texts(story4);
	Sleep(1000);
	screen_s(&story_y);

	gotoxy(story_x, story_y);
	char story5[] = "[system : 다음 난이도로 이동합니다.]";
	texts(story5);
	Sleep(1000);
	screen_s(&story_y);

	gotoxy(story_x, story_y);
	char story6[] = "[system : 축하드립니다! 게임을 클리어하셨습니다!]";
	texts(story6);
	Sleep(1000);
	screen_s(&story_y);

	gotoxy(story_x, story_y);
	char story7[] = "[system : 새로운 창에서 스토리 출력]";
	texts(story7);
	Sleep(1000);
	screen_s(&story_y);

	return 0;
}