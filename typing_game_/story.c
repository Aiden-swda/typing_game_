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
	screen_s1(&story_y);  // screen_s�Լ��� story_y�� ���� �� ���ǿ� ���� story_y�� ����

	return 0;
}
void print_help() // ���� ���
{
	gotoxy(7, 7);
	printf("�� ȭ�鿡 ǥ�õǴ� ����ܾ �ð� ���� ��Ȯ�� �Է��ϼ���.");
	ColorSet(12);
	printf(" ������ �Է��� ����");
	ColorSet(7);
	printf(" �� ���� ������ ����ϴ�.");
	gotoxy(7, 10);
	printf("�� �ܾ ���ѽð� ���� ������ ���ϰų� Ʋ���� ü���� �����Ǹ�, ü���� ��� ������ �� ");
	ColorSet(14);
	printf("���ӿ���");
	ColorSet(7);
	printf("�˴ϴ�.");
	gotoxy(7, 13);
	printf("�� �ܾ �����Ͽ� ���߸� ");
	ColorSet(10);
	printf("Combo");
	ColorSet(7);
	printf("�� ���̰� ");
	ColorSet(10);
	printf("�߰� ����");
	ColorSet(7);
	printf("�� ȹ���Ͻ� �� �ֽ��ϴ�.");
	gotoxy(7, 16);
	printf("�� ü���� �������� ���� �ִ� ");
	ColorSet(11);
	printf("�̺�Ʈ �ܾ�");
	ColorSet(7);
	printf("�� �����˴ϴ�. ���� �� ");
	ColorSet(11);
	printf("ü��");
	ColorSet(7);
	printf("�� ȸ���մϴ�.");
	gotoxy(7, 19);
	printf("�� ���� ������ �ѱ� �ÿ� ");
	ColorSet(13);
	printf("Ŭ����");
	ColorSet(7);
	printf("�� �Ǿ� �ڵ����� ���� ���̵��� �̵��մϴ�. ����� ���ϴ�!");
	gotoxy(29, 25);
	printf("[ ����ȭ������ ���ư����� �����̽��ٸ� �������� ]");
	while (1) // �����̽��� ������ ����
	{
		char n = _getch();
		if (n == SPACE_BAR)
			break;
	}
}