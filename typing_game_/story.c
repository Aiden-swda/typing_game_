//���丮�� ���⿡ �����ϱ�

#include "main.h"


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

void texts(char text[]) // �ؽ�Ʈ ��½ð�
{
	for (int i = 0; i < strlen(text); i++)
	{
		printf("%c", text[i]);
		Sleep(80);
	}
}

void story() // ���丮 ��� ��� ���� (���߿� �����ؼ� ���)
{
	int story_x = 2;
	int story_y = LINES - 14;

	gotoxy(story_x, story_y);
	char story1[] = "[system : ������ ���۵˴ϴ�.]";
	texts(story1);
	Sleep(1000);
	screen_s(&story_y);

	gotoxy(story_x, story_y);
	char story2[] = "[system : �̹� ���̵��� Ŭ�����ϼ̽��ϴ�.]";
	texts(story2);
	Sleep(1000);
	screen_s(&story_y);

	gotoxy(story_x, story_y);
	char story3[] = "[system : ü���� 1 �Ҹ�Ǿ����ϴ�.]";
	texts(story3);
	Sleep(1000);
	screen_s(&story_y);

	gotoxy(story_x, story_y);
	char story4[] = "[system : �޺� ����! �߰� ������ ȹ���մϴ�.]";
	texts(story4);
	Sleep(1000);
	screen_s(&story_y);

	gotoxy(story_x, story_y);
	char story5[] = "[system : ���� ���̵��� �̵��մϴ�.]";
	texts(story5);
	Sleep(1000);
	screen_s(&story_y);

	gotoxy(story_x, story_y);
	char story6[] = "[system : ���ϵ帳�ϴ�! ������ Ŭ�����ϼ̽��ϴ�!]";
	texts(story6);
	Sleep(1000);
	screen_s(&story_y);

	gotoxy(story_x, story_y);
	char story7[] = "[system : ���ο� â���� ���丮 ���]";
	texts(story7);
	Sleep(1000);
	screen_s(&story_y);

	return 0;
}