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
	FILE* fp = fopen("wordBase.txt", "r");
	//for ������ ���ٴ� �ϳ��� �迭�� ���� 
	for (i = 0; i < WORDNUM; i++)
	{
		fgets(wordBase[j], WORDLEN, fp);
		j++;
	}
	fclose(fp);
}

int get_random_word(int *wordLength) //�ܾ� �������� ������
{
	//�������� �ܾ� ������
	arrayNum = rand() % WORDNUM; 
	//�ܾ��� ���� �ľ�
	*wordLength = strlen(wordBase[arrayNum]) - 1;
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

int input_menu()
{
	int input;
	scanf("%d", &input);
	if ((input <= 4) && (input >= 1))
		return input;
	else
		input_menu();
}

int get_levelInput()
{
	int input;
	scanf("%d", &input);
	if ((input <= 4) && (input >= 1))
		return input;
	else
		get_levelInput();
}