#include <stdio.h>
#include <windows.h>
void first();
void gotoxy(int x, int y);
#define COLS 120
#define LINES 45


int main()
{
	system("mode con cols=120 lines=45");
	first();

}
void first()  //ù ȭ�� ����ϴ� �Լ�
{
	int i;
	for (i = 1; i <= COLS; i++) //ù °�� �� ���
	{
		printf("*");
	}
	gotoxy(COLS / 2 - 12, LINES / 2 - 4);
	printf("�Ǵ��� ���");
	gotoxy(COLS / 2 - 12, LINES / 2 - 3);
	printf("�츮 �� �̸�");
	gotoxy(COLS / 2 - 12, LINES / 2 - 2);
	printf("1. ���� ����");
	gotoxy(COLS / 2 - 12, LINES / 2 - 1);
	printf("2. ����(ù�� �ʼ�)");
	gotoxy(COLS / 2 - 12, LINES / 2);
	printf("3. ���� ����");
	gotoxy(COLS / 2 - 12, LINES / 2 + 1);
	printf("4. ��������");
	gotoxy(0, LINES);         //������ �ٿ� �� ����Ϸ��ߴµ� �ȵǳ�.. ����
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