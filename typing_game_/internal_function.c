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
		Sleep(50);
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

int keyControl() {
	char temp = _getch();
	if (temp == ' ')
		return SUBMIT;
	else if (temp == -32){
		temp = _getch();

		if (temp == 72)
			return UP;
		else if (temp == 80)
			return DOWN;
	}
}

void print_letter_in_box(char* s)
{
	int story_x = 2;
	int story_y = LINES - 14;
	screen();
	gotoxy(story_x, story_y);
	texts(s); // texts�Լ��� �ؽ�Ʈ ��� õõ���ϱ�
	Sleep(500);
	screen_s(&story_y);  // screen_s�Լ��� story_y�� ���� �� ���ǿ� ���� story_y�� ����
}

int ask_next_level()
{
	int x = COLS / 2 - 8;
	int y = LINES / 2 - 7;

	system("cls");
	gotoxy(COLS / 2 - 13, LINES / 2 - 10);
	printf(" ���� ������ �����Ͻðڽ��ϱ�? ");

	gotoxy(x, y);
	printf("> ");
	ColorSet(14);
	printf("��. �����ϰڽ��ϴ�.");
	gotoxy(x + 2, y + 2);
	ColorSet(12);
	printf("�ƴϿ�. �����ϰڽ��ϴ�.");
	ColorSet(7);
	screen();
	print_letter_in_box("����Ű�� ������ ��, �����̽� �ٷ� �޴��� �����ϼ���.");

	while (1) {
		int n = keyControl();
		switch (n) {
		case UP: {
			if (y > LINES / 2 - 7) {
				gotoxy(x, y);
				printf(" ");
				y -= 2;
				gotoxy(x, y);
				printf(">");
			}
			break;
		}
		case DOWN: {
			if (y < LINES / 2 - 5) {
				gotoxy(x, y);
				printf(" ");
				y += 2;
				gotoxy(x, y);
				printf(">");
			}
			break;
		}
		case SUBMIT:
			return y - (LINES / 2 - 7);
		}
	}
}