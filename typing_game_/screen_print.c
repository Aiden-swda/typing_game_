//처음 화면을 출력하는 소스 파일

#include "main.h"

int first_menu()  //첫 화면 출력하는 함수
{
	int x = COLS / 2 - 8;
	int y = LINES / 2 - 7;

	//print_star();
	ColorSet(7);
	gotoxy(COLS / 2 - 12, LINES / 2 - 13);
	printf("=====================");
	gotoxy(COLS / 2- 13, LINES / 2 - 12);
	printf("│    건덕이 잡기v1   │");
	gotoxy(COLS / 2 - 12, LINES / 2 - 11);
	printf("=====================");
	ColorSet(7);
	gotoxy(x, y);
	printf("> 게임 시작");
	gotoxy(x, y+2);
	printf("  도움말");
	gotoxy(x, y+4);
	printf("  점수 보기");
	gotoxy(x, y+6);
	printf("  게임종료");
	ColorSet(7);
	gotoxy(COLS - 21, LINES - 17);
	printf("made by [ 건구스 ]");

	screen();
	emoticon();
	print_letter_in_box("방향키로 움직인 뒤, 스페이스 바로 메뉴를 선택하세요");

	gotoxy(x, y);

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
			if (y < LINES / 2 - 1) {
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

int second_menu()  // 선택 화면 출력하는 함수
{
	int x = COLS / 2 - 8;
	int y = LINES / 2 - 7;

	system("cls");
	print_star();
	ColorSet(7);
	gotoxy(COLS / 2 - 12, LINES / 2 - 13);
	printf("=====================");
	gotoxy(COLS / 2 - 13, LINES / 2 - 12);
	printf("│     난이도 선택    │");
	gotoxy(COLS / 2 - 12, LINES / 2 - 11);
	printf("=====================");
	gotoxy(x, y);
	printf("> ");
	ColorSet(14);
	printf("쉬움");
	gotoxy(x+2, y+2);
	ColorSet(12);
	printf("보통");
	gotoxy(x+2, y+4);
	ColorSet(192);
	printf("어려움");
	ColorSet(7);
	gotoxy(x+2, y+6);
	printf("다시 메뉴로");

	gotoxy(COLS - 21, LINES - 17);
	printf("made by [ 건구스 ]");

	screen();
	emoticon();
	print_letter_in_box("방향키로 움직인 뒤, 스페이스 바로 난이도를 선택하세요.");

	gotoxy(x, y);

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
			if (y < LINES / 2 - 1) {
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

void screen() // 대화창 출력하는 함수
{
	int i, j;

	gotoxy(0, LINES - 15);
	printf("┌");
	for (i = 0; i < COLS_BOX; i++) printf("─");
	printf("┐\n");

	for (j = 0; j < LINES_BOX; j++) {
		printf("│");
		for (i = 0; i < COLS_BOX; i++) printf(" ");
		printf("│\n");
	}

	printf("└");
	for (i = 0; i < COLS_BOX; i++) printf("─");
	printf("┘\n");
}

void emoticon() // 첫 화면 이모티콘
{
	ColorSet(10);  // 둠칫 고양이 시작
	gotoxy(82, 10);
	printf("⊂_＼");
	gotoxy(82, 11);
	printf("　 ＼＼ Λ＿Λ");
	gotoxy(82, 12);
	printf("　　 ＼( ‘ㅅ') 두둠칫");
	gotoxy(82, 13);
	printf("　　　 >　⌒＼");
	gotoxy(82, 14);
	printf("　　　/ 　 へ＼");
	gotoxy(82, 15);
	printf("　　 /　　/　＼＼");
	gotoxy(82, 16);
	printf("　　 |　ノ　　 ＼_つ");
	gotoxy(82, 17);
	printf("　　/　/두둠칫");
	gotoxy(82, 18);
	printf("　 /　/");
	gotoxy(82, 19);
	printf("　(　(＼");
	gotoxy(82, 20);
	printf("　| |、 ＼");
	gotoxy(82, 21);
	printf("　| | ＼ ⌒)");
	gotoxy(82, 22);
	printf("　| |　　) /");
	gotoxy(82, 23);
	printf(" ノ )　  L|");
	ColorSet(7);  // 둠칫 고양이 종료

	ColorSet(10);  // 타자 이모티콘 시작
	gotoxy(17, 10);
	printf("\a□□□□□□□□");  // 소리난다
	gotoxy(17, 11);
	printf("□■■■□■□□");
	gotoxy(17, 12);
	printf("□■□□□■□□");
	gotoxy(17, 13);
	printf("□■■■□■■□");
	gotoxy(17, 14);
	printf("□■□□□■□□");
	gotoxy(17, 15);
	printf("□■■■□■□□");
	gotoxy(17, 16);
	printf("□□□□□□□□");
	gotoxy(17, 17);
	printf("□■■■□■□□");
	gotoxy(17, 18);
	printf("□□■□□■□□");
	gotoxy(17, 19);
	printf("□□■□□■■□");
	gotoxy(17, 20);
	printf("□■□■□■□□");
	gotoxy(17, 21);
	printf("□■□■□■□□");
	gotoxy(17, 22);
	printf("□□□□□□□□ game");
	ColorSet(7);  // 타자 임티 종료
	
}

void print_star()  // 무지개 별 출력
{
	int i;
	int d = 1;
	for (i = 1; i <= COLS; i++) //첫 째줄 별 출력
	{
		printf("*");
		if (d == 15)
			d = d - 13;
		else
			d++;
		ColorSet(d);
	}
	ColorSet(7);
	gotoxy(0, LINES - 16);
	for (i = 1; i <= COLS; i++)
	{
		printf("*");
		if (d == 15)
			d = d - 13;
		else
			d++;
		ColorSet(d);
	}

}
void English() // English 출력
{
	int i;
	for (i = 0; i < 4; i++)
	{
		if (i == 0 || i == 2)
			ColorSet(10);
		else
			ColorSet(13);
		gotoxy(8, LINES / 2 - 3);
		printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
		gotoxy(8, LINES / 2 - 2);
		printf("□■■■■■■□■□□□□■□□■■■■□□■□□□□□□■■■■■■□□■■■■■□■□□□□■□");
		gotoxy(8, LINES / 2 - 1);
		printf("□■□□□□□□■■□□□■□■□□□□□□■□□□□□□□□■■□□□■□□□□□□■□□□□■□");
		gotoxy(8, LINES / 2);
		printf("□■■■■■■□■□■□□■□■□□■■■□■□□□□□□□□■■□□□□■■■■□□■■■■■■□");
		gotoxy(8, LINES / 2 + 1);
		printf("□■□□□□□□■□□■□■□■□□■■□□■□□□□□□□□■■□□□□□□□□■□■□□□□■□");
		gotoxy(8, LINES / 2 + 2);
		printf("□■■■■■■□■□□□■■□□■■□■□□■■■■■■□■■■■■■□■■■■■□□■□□□□■□");
		gotoxy(8, LINES / 2 + 3);
		printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
		Sleep(1000);
	}

	system("cls");
	ColorSet(7);
	gotoxy(0,0);
}