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

void texts(char text[]) // �ؽ�Ʈ ��½ð� ����
{
	for (int i = 0; i < strlen(text); i++)
	{
		printf("%c", text[i]);
		Sleep(80);
	}
}

void story() // ���丮 ��� ��� ���� (���� �� ����ȭ�� �غ��� ���� �̿�)
// ������ : �ؽ�Ʈâ ���η� (x,y)��ǥ ���� -> �迭�� �ؽ�Ʈ ���� -> texts�Լ��� ������� -> screen_s�Լ��� ��ǥ���� or �ؽ�Ʈâ �ʱ�ȭ
{
	int story_x = 2;
	int story_y = LINES - 14;

	gotoxy(story_x, story_y);
	char story1[] = "[system : ������ ���۵˴ϴ�.]";  // �迭�� ����� �ؽ�Ʈ ����
	texts(story1); // texts�Լ��� �ؽ�Ʈ ��� õõ���ϱ�
	Sleep(1000);
	screen_s(&story_y);  // screen_s�Լ��� story_y�� ���� �� ���ǿ� ���� story_y�� ����

	return 0;
}