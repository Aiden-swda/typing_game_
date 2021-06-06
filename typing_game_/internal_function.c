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
		Sleep(10);
	}
}

void CursorView(char show) // Ŀ�������
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void print_letter_in_box1(char* s)
{
	screen();
	gotoxy(2, LINES - 14);
	texts(s); // texts�Լ��� �ؽ�Ʈ ��� õõ���ϱ�
	Sleep(1000);
}

void print_letter_in_box2(char* s)
{
	main_screen();
	gotoxy(32, 31);
	texts(s); // texts�Լ��� �ؽ�Ʈ ��� õõ���ϱ�
	Sleep(1000);
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

int ask_next_level()
{
	int x = 45;
	int y = 15;

	system("cls");
	gotoxy(42, 12);
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
	print_letter_in_box1("����Ű�� ������ ��, �����̽� �ٷ� �޴��� �����ϼ���.");

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