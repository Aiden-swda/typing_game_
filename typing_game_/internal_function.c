//내부 기능들은 여기에 구현

#include "main.h"

void gotoxy(int x, int y)  //커서 위치 조정
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

void read_file() //파일 읽기
{
	int i, j = 0;
	//파일열기 
	FILE* fp = fopen("hello.txt", "r");
	//for 문으로 한줄당 하나씩 배열에 저장 
	for (i = 0; i < WORDLEN; i++)
	{
		fgets(wordBase[j], WORDLEN, fp);
		j++;
	}
	fclose(fp);
}

int get_random_word() //단어 랜덤으로 꺼내기
{
	arrayNum = rand() % WORDNUM; 
	return arrayNum;
}

void screen_s(int* story_y) // 대화창 꽉차면 비우는 함수
{
	if (*story_y == (LINES - 4)) {
		system("cls");
		screen();
		*story_y = LINES - 14;
	}
	else {
		*story_y += 2;
	}
}