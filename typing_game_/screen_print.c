//ó�� ȭ���� ����ϴ� �ҽ� ����

#include "main.h"

void first()  //ù ȭ�� ����ϴ� �Լ�
{
	int i;

	for (i = 1; i <= COLS; i++) //ù °�� �� ���
	{
		printf("*");
	}
	gotoxy(COLS / 2 - 12, LINES / 2 - 6);
	printf("  ");
	ColorSet(94);
	printf("<�Ǵ��� ���>");
	ColorSet(7);
	gotoxy(COLS / 2 - 12, LINES / 2 - 5);
	printf("�츮 �� �̸�");
	gotoxy(COLS / 2 - 12, LINES / 2 - 3);
	printf("1. ���� ����");
	gotoxy(COLS / 2 - 12, LINES / 2 - 2);
	printf("2. ����(ù�� �ʼ�)");
	gotoxy(COLS / 2 - 12, LINES / 2 - 1);
	printf("3. ���� ����");
	gotoxy(COLS / 2 - 12, LINES / 2);
	printf("4. ��������\n");
	gotoxy(COLS / 2 - 12, LINES / 2 + 2);
	printf("�Է�:");
	gotoxy(0, LINES - 5);
	for (i = 1; i <= COLS; i++)
	{
		printf("*");
	}
}

void screen() // ��ȭâ ����ϴ� �Լ�
{
	int i, j;

	gotoxy(0, LINES - 15);
	printf("��");
	for (i = 0; i < COLS_BOX; i++) printf("��");
	printf("��\n");

	for (j = 0; j < LINES_BOX; j++) {
		printf("��");
		for (i = 0; i < COLS_BOX; i++) printf(" ");
		printf("��\n");
	}

	printf("��");
	for (i = 0; i < COLS_BOX; i++) printf("��");
	printf("��\n");

	return 0;
}

void print_letter(char *s)
{
	int story_x = 2;
	int story_y = LINES - 14;
	screen();
	gotoxy(story_x, story_y);
	texts(s); // texts�Լ��� �ؽ�Ʈ ��� õõ���ϱ�
	Sleep(1000);
	screen_s(&story_y);  // screen_s�Լ��� story_y�� ���� �� ���ǿ� ���� story_y�� ����

	return 0;
}
