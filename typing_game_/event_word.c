//�̺�Ʈ �ܾ���� �������� �����ϱ�
#include "main.h"

void event_word(int a ,int heart)
{
	int percent = rand() % 100;
	if (percent < 20) //Ȯ�� ����
	{
		ColorSet(11);
		gotoxy(COLS / 2 - 6, 9);
		printf("%s\n", wordBase[a]);
		event = 1;
		ColorSet(7);
	}
	else {
		ColorSet(7);
		gotoxy(COLS / 2 - 6, 9);
		printf("%s\n", wordBase[a]);
		event = 0;
	}
	
}



