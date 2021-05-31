//이벤트 단어들을 랜덤으로 세팅하기
#include "main.h"

void event_word(int a ,int heart)
{
	int percent = rand() % 100;
	if (percent < 20) //20퍼센트
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



