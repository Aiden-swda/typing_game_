//처음 화면을 출력하는 소스 파일

#include "main.h"

void first()  //첫 화면 출력하는 함수
{
	//print_star();
	ColorSet(7);
	gotoxy(COLS / 2 - 9, LINES / 2 - 6);
	printf("  ");
	ColorSet(121);
	printf("<건덕이 잡기>");
	ColorSet(7);
	gotoxy(COLS / 2 - 9, LINES / 2 - 5);
	printf("made by ");
	ColorSet(121);
	printf("[건구스]");
	ColorSet(7);
	gotoxy(COLS / 2 - 9, LINES / 2 - 3);
	printf("1. 게임 시작");
	gotoxy(COLS / 2 - 9, LINES / 2 - 2);
	printf("2. 도움말(첫판 필수)");
	gotoxy(COLS / 2 - 9, LINES / 2 - 1);
	printf("3. 점수 보기");
	gotoxy(COLS / 2 - 9, LINES / 2);
	printf("4. 게임종료\n");
}

void show_level_select()  // 선택 화면 출력하는 함수
{
	system("cls");
	print_star();
	gotoxy(COLS / 2 - 12, LINES / 2 - 6);
	printf("  ");
	ColorSet(11);
	printf("<난이도 선택>");
	ColorSet(7);
	gotoxy(COLS / 2 - 12, LINES / 2 - 3);
	printf("1. ");
	ColorSet(14);
	printf("쉬움");
	ColorSet(7);
	printf(" (시간 제한 7초)");
	gotoxy(COLS / 2 - 12, LINES / 2 - 2);
	printf("2. ");
	ColorSet(12);
	printf("보통");
	ColorSet(7);
	printf(" (시간 제한 5초");
	gotoxy(COLS / 2 - 12, LINES / 2 - 1);
	printf("3. ");
	ColorSet(192);
	printf("어려움");
	ColorSet(7);
	printf(" (시간 제한 3초)");
	gotoxy(COLS / 2 - 12, LINES / 2);
	printf("4. 다시 메뉴로\n");
	gotoxy(0, LINES - 5);
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
	gotoxy(84, 10);
	printf("⊂_＼");
	gotoxy(84, 11);
	printf("　 ＼＼ Λ＿Λ");
	gotoxy(84, 12);
	printf("　　 ＼( 'ㅅ' ) 두둠칫");
	gotoxy(84, 13);
	printf("　　　 >　⌒＼");
	gotoxy(84, 14);
	printf("　　　/ ♥ へ＼");
	gotoxy(84, 15);
	printf("　　 /　　/　＼＼");
	gotoxy(84, 16);
	printf("　　 |　ノ　　 ＼_つ");
	gotoxy(84, 17);
	printf("　　/　/두둠칫");
	gotoxy(84, 18);
	printf("　 /　/");
	gotoxy(84, 19);
	printf("　(　(＼");
	gotoxy(84, 20);
	printf("　| |、 ＼");
	gotoxy(84, 21);
	printf("　| | ＼ ⌒)");
	gotoxy(84, 22);
	printf("　| |　　) /");
	gotoxy(84, 23);
	printf(" ノ )　  L|");
	ColorSet(7);  // 둠칫 고양이 종료

	ColorSet(10);  // 타자 이모티콘 시작
	gotoxy(17, 13);
	printf("\a☆□□□□□□☆");  // 소리난다
	gotoxy(17, 14);
	printf("□■■■□■□□");
	gotoxy(17, 15);
	printf("□■□□□■□□");
	gotoxy(17, 16);
	printf("□■■■□■■□");
	gotoxy(17, 17);
	printf("□■□□□■□□");
	gotoxy(17, 18);
	printf("□■■■□■□□");
	gotoxy(17, 19);
	printf("□□□□□□□□");
	gotoxy(17, 20);
	printf("□■■■□■□□");
	gotoxy(17, 21);
	printf("□□■□□■□□");
	gotoxy(17, 22);
	printf("□□■□□■■□");
	gotoxy(17, 23);
	printf("□■□■□■□□");
	gotoxy(17, 24);
	printf("□■□■□■□□");
	gotoxy(17, 25);
	printf("☆□□□□□□☆ game");
	ColorSet(7);  // 타자 임티 종료

	ColorSet(115);  // 제목 시작
	gotoxy(17, 2);
	printf("★□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□★");
	gotoxy(17, 3);
	printf("□■■■□□■□■■■□□■□□■■□□■□■■■□■□□■□□□□■□■■■■□■□");
	gotoxy(17, 4);
	printf("□□□■■■■□■□□■■■□■□□■□■□□■□□■□□■■■■■■□□□□■□■□");
	gotoxy(17, 5);
	printf("□□□■□□■□■■■□□■□■□□■□■□□■□□■■□■□□□□■□□□□■□■□");
	gotoxy(17, 6);
	printf("□■□□□□□□□□□□□□□■□□■□■□□■□□■□□■■■■■■□□□■□□■□");
	gotoxy(17, 7);
	printf("□■□□□□□□□■■■■■□■□□■□■□■□■□■□□□□□□□□□□■□□□■□");
	gotoxy(17, 8);
	printf("□■■■■■■□□□□□□■□□■■□□■□■□■□■□□■■■■■■□■□□□□■□");
	gotoxy(17, 9);
	printf("★□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□★");
	ColorSet(7);  // 제목 출력 종료
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
		gotoxy(4, LINES / 2 - 3);
		printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
		gotoxy(4, LINES / 2 - 2);
		printf("□■■■■■■□■□□□□■□□■■■■□□■□□□□□□■■■■■■□□■■■■■□■□□□□■□");
		gotoxy(4, LINES / 2 - 1);
		printf("□■□□□□□□■■□□□■□■□□□□□□■□□□□□□□□■■□□□■□□□□□□■□□□□■□");
		gotoxy(4, LINES / 2);
		printf("□■■■■■■□■□■□□■□■□□■■■□■□□□□□□□□■■□□□□■■■■□□■■■■■■□");
		gotoxy(4, LINES / 2 + 1);
		printf("□■□□□□□□■□□■□■□■□□■■□□■□□□□□□□□■■□□□□□□□□■□■□□□□■□");
		gotoxy(4, LINES / 2 + 2);
		printf("□■■■■■■□■□□□■■□□■■□■□□■■■■■■□■■■■■■□■■■■■□□■□□□□■□");
		gotoxy(4, LINES / 2 + 3);
		printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
		Sleep(1000);
	}

	system("cls");
	ColorSet(7);
	gotoxy(0,0);
}