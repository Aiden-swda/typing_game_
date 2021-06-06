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
		Sleep(10);
	}
}

void CursorView(char show) // 커서숨기기
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void print_letter_in_box1(char* s)
{
	screen();
	gotoxy(2, LINES - 14);
	texts(s); // texts함수로 텍스트 출력 천천히하기
	Sleep(1000);
}

void print_letter_in_box2(char* s)
{
	main_screen();
	gotoxy(32, 31);
	texts(s); // texts함수로 텍스트 출력 천천히하기
	Sleep(1000);
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

int ask_next_level()
{
	int x = 45;
	int y = 15;

	system("cls");
	gotoxy(42, 12);
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
	print_letter_in_box1("방향키로 움직인 뒤, 스페이스 바로 메뉴를 선택하세요.");

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