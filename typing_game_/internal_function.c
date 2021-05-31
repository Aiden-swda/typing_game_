//내부 기능들은 여기에 구현

#include "main.h"

void gotoxy(int x, int y)  //커서 위치 조정
{
	COORD Cur = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void ColorSet(int color_number)  //글자 색, 배경 색 바꾸는 함수
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, color_number);
}

void texts(char text[]) // 텍스트 출력시간 설정
{
	for (int i = 0; i < strlen(text); i++)
	{
		printf("%c", text[i]);
		Sleep(50);
	}
}

void read_file() //파일 읽기
{
	int i, j = 0;
	//파일열기 
	FILE* fp = fopen("wordBase.txt", "r");
	//for 문으로 한줄당 하나씩 배열에 저장 
	for (i = 0; i < WORDNUM; i++)
	{
		fgets(wordBase[j], WORDLEN, fp);
		j++;
	}
	fclose(fp);
}

int get_random_word(int *wordLength) //단어 랜덤으로 꺼내기
{
	//랜덤으로 단어 꺼내기
	arrayNum = rand() % WORDNUM; 
	//단어의 길이 파악
	*wordLength = strlen(wordBase[arrayNum]) - 1;
	return arrayNum;
}

void screen_s(int* story_y) // 대화창 꽉차면 비우는 함수
{
	if (*story_y == (LINES - 4)) {
		system("cls");
		screen();
		*story_y = LINES - 14;
	}
	else {
		*story_y += 2;
	}
}

int keyControl() {
	char temp = _getch();
	if (temp == ' ')
		return SUBMIT;
	else if (temp == -32){
		temp = _getch();

		if (temp == 72)
			return UP;
		else if (temp == 80)
			return DOWN;
	}
}

void print_letter_in_box(char* s)
{
	int story_x = 2;
	int story_y = LINES - 14;
	screen();
	gotoxy(story_x, story_y);
	texts(s); // texts함수로 텍스트 출력 천천히하기
	Sleep(500);
	screen_s(&story_y);  // screen_s함수로 story_y값 전달 후 조건에 따라 story_y값 변경
}

int ask_next_level()
{
	int x = COLS / 2 - 8;
	int y = LINES / 2 - 7;

	system("cls");
	gotoxy(COLS / 2 - 13, LINES / 2 - 10);
	printf(" 다음 레벨로 진행하시겠습니까? ");

	gotoxy(x, y);
	printf("> ");
	ColorSet(14);
	printf("네. 진행하겠습니다.");
	gotoxy(x + 2, y + 2);
	ColorSet(12);
	printf("아니요. 종료하겠습니다.");
	ColorSet(7);
	screen();
	print_letter_in_box("방향키로 움직인 뒤, 스페이스 바로 메뉴를 선택하세요.");

	while (1) {
		int n = keyControl();
		switch (n) {
		case UP: {
			if (y > LINES / 2 - 7) {
				gotoxy(x, y);
				printf(" ");
				y -= 2;
				gotoxy(x, y);
				printf(">");
			}
			break;
		}
		case DOWN: {
			if (y < LINES / 2 - 5) {
				gotoxy(x, y);
				printf(" ");
				y += 2;
				gotoxy(x, y);
				printf(">");
			}
			break;
		}
		case SUBMIT:
			return y - (LINES / 2 - 7);
		}
	}
}