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
void print_help() // ���� ���
{
	gotoxy(15, 13);
	texts("1. ȭ�鿡 ������ ����ܾ �Ȱ��� ���� �Է����ּ���. ");
	ColorSet(12);
	texts("���� �Է�");
	ColorSet(7);
	texts("�� ���� �� ���� ������ ����ϴ�.");
	gotoxy(15, 14);
	texts("2. ü���� �� �������� ������ ������� ");
	ColorSet(14);
	texts("���ӿ���");
	ColorSet(7);
	texts("�Դϴ�. ��Ȯ�� �Է��սô�!!");
	gotoxy(15, 15);
	texts("3. �޺��� ������ ");
	ColorSet(10);
	texts("�߰� ����");
	ColorSet(7);
	texts("�� ȹ���Ͻ� �� �ֽ��ϴ�. ������� ���������!");
	gotoxy(15, 16);
	texts("4. ü���� �������� ����Ȯ���� ");
	ColorSet(11);
	texts("�̺�Ʈ �ܾ�");
	ColorSet(7);
	texts("�� ����մϴ�. ������ ü���� ȸ���սô�~");
	gotoxy(15, 17);
	texts("5. �����̳� ���� ���̵��� ");
	ColorSet(13);
	texts("Ŭ����");
	ColorSet(7);
	texts("�� �ڵ����� ���� ���̵��� �Ѿ�ϴ�. ������ �Ƿ��� �����ּ���!");
	gotoxy(15, 19);
	texts("����ȭ������ ���ư��� �ʹٸ� �ƹ� ���ڳ� �Է��ϼ���.");
	int n;
	scanf("%d", &n);
}