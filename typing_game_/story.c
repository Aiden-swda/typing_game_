//���丮�� ���⿡ �����ϱ�

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
	gotoxy(0, LINES-5);
	for (i = 1; i <= COLS; i++)
	{
		printf("*");
	}

}
void gotoxy(int x, int y)  //��� ���� Ŀ�� ��ġ ����
{
	COORD Cur = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}
void ColorSet(int color_number)  //���� ��, ��� �� �ٲٴ� �Լ�
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, color_number);
}