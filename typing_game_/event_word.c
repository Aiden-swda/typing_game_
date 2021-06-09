//이벤트 단어들을 랜덤으로 세팅하기
#include "main.h"

void event_word(int a ,int heart)
{
	int percent = rand() % 100;
	if (percent < 20) //확률 설정
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



