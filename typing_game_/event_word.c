//�̺�Ʈ �ܾ���� �������� �����ϱ�
#include "main.h"

void event_word(int a ,int heart)
{
	int percent = rand() % 100;
	if (percent < 20) //20�ۼ�Ʈ
	{
		ColorSet(1);
		gotoxy(COLS / 2 - 5, 9);
		printf("%s\n", wordBase[a]);
		event = 1;
	}
	else {
		ColorSet(7);
		gotoxy(COLS / 2 - 5, 9);
		printf("%s\n", wordBase[a]);
		event = 0;
	}
	
}



