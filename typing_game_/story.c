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