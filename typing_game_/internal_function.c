//���� ��ɵ��� ���⿡ ����

#include "main.h"

void gotoxy(int x, int y)  //Ŀ�� ��ġ ����
{
	COORD Cur = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void ColorSet(int color_number)  //���� ��, ��� �� �ٲٴ� �Լ�
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, color_number);
}

void texts(char text[]) // �ؽ�Ʈ ��½ð� ����
{
	for (int i = 0; i < strlen(text); i++)
	{
		printf("%c", text[i]);
		Sleep(80);
	}
}

void read_file() //���� �б�
{
	int i, j = 0;
	//���Ͽ��� 
	FILE* fp = fopen("hello.txt", "r");
	//for ������ ���ٴ� �ϳ��� �迭�� ���� 
	for (i = 0; i < WORDLEN; i++)
	{
		fgets(wordBase[j], WORDLEN, fp);
		j++;
	}
	fclose(fp);
}

int get_random_word() //�ܾ� �������� ������
{
	arrayNum = rand() % WORDNUM; 
	return arrayNum;
}

void screen_s(int* story_y) // ��ȭâ ������ ���� �Լ�
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