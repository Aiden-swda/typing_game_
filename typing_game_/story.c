//���丮�� ���⿡ �����ϱ�
// ���丮 ��� ��� ���� (���� �� ����ȭ�� �غ��� ���� �̿�)
// ������ : �ؽ�Ʈâ ���η� (x,y)��ǥ ���� -> �迭�� �ؽ�Ʈ ���� -> texts�Լ��� ������� -> screen_s�Լ��� ��ǥ���� or �ؽ�Ʈâ �ʱ�ȭ

#include "main.h"

void story() 

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