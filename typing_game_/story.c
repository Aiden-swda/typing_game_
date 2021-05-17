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

void texts(char text[]) // 텍스트 출력시간 설정
{
	for (int i = 0; i < strlen(text); i++)
	{
		printf("%c", text[i]);
		Sleep(80);
	}
}

void story() // 스토리 출력 방식 예시 (내가 더 최적화를 해볼게 아직 미완)
// 실행방식 : 텍스트창 내부로 (x,y)좌표 설정 -> 배열에 텍스트 저장 -> texts함수로 출력조절 -> screen_s함수로 좌표변경 or 텍스트창 초기화
{
	int story_x = 2;
	int story_y = LINES - 14;

	gotoxy(story_x, story_y);
	char story1[] = "[system : 게임이 시작됩니다.]";  // 배열로 출력할 텍스트 선언
	texts(story1); // texts함수로 텍스트 출력 천천히하기
	Sleep(1000);
	screen_s(&story_y);  // screen_s함수로 story_y값 전달 후 조건에 따라 story_y값 변경

	return 0;
}