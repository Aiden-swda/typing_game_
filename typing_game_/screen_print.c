//처음 화면을 출력하는 소스 파일

#include "main.h"

void first()  //첫 화면 출력하는 함수
{
	print_star();
	ColorSet(7);
	gotoxy(COLS / 2 - 12, LINES / 2 - 6);
	printf("  ");
	ColorSet(121);
	printf("<건덕이 잡기>");
	ColorSet(7);
	gotoxy(COLS / 2 - 12, LINES / 2 - 5);
	printf("made by ");
	ColorSet(121);
	printf("[건구스]");
	ColorSet(7);
	gotoxy(COLS / 2 - 12, LINES / 2 - 3);
	printf("1. 게임 시작");
	gotoxy(COLS / 2 - 12, LINES / 2 - 2);
	printf("2. 도움말(첫판 필수)");
	gotoxy(COLS / 2 - 12, LINES / 2 - 1);
	printf("3. 점수 보기");
	gotoxy(COLS / 2 - 12, LINES / 2);
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
	//gotoxy(COLS / 2 - 12, LINES / 2 - 5);
	//printf("우리 조 이름");
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

	return 0;
}

void print_letter(char *s)
{
	int story_x = 2;
	int story_y = LINES - 14;
	screen();
	gotoxy(story_x, story_y);
	texts(s); // texts함수로 텍스트 출력 천천히하기
	Sleep(500);
	screen_s(&story_y);  // screen_s함수로 story_y값 전달 후 조건에 따라 story_y값 변경

	return 0;
}

void emoticon() // 첫 화면 이모티콘
{
	ColorSet(10);  // 둠칫 고양이 시작
	gotoxy(80, 10);
	printf("⊂_＼");
	gotoxy(80, 11);
	printf("　 ＼＼ Λ＿Λ");
	gotoxy(80, 12);
	printf("　　 ＼( ‘ㅅ') 두둠칫");
	gotoxy(80, 13);
	printf("　　　 >　⌒＼");
	gotoxy(80, 14);
	printf("　　　/ 　 へ＼");
	gotoxy(80, 15);
	printf("　　 /　　/　＼＼");
	gotoxy(80, 16);
	printf("　　 |　ノ　　 ＼_つ");
	gotoxy(80, 17);
	printf("　　/　/두둠칫");
	gotoxy(80, 18);
	printf("　 /　/");
	gotoxy(80, 19);
	printf("　(　(＼");
	gotoxy(80, 20);
	printf("　| |、 ＼");
	gotoxy(80, 21);
	printf("　| | ＼ ⌒)");
	gotoxy(80, 22);
	printf("　| |　　) /");
	gotoxy(80, 23);
	printf(" ノ )　  L|");
	ColorSet(7);  // 둠칫 고양이 종료

	ColorSet(10);  // 타자 이모티콘 시작
	gotoxy(17, 10);
	printf("\a☆□□□□□□☆");  // 소리난다
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
	printf("☆□□□□□□☆ game");
	ColorSet(7);  // 타자 임티 종료
	
}
void print_help() // 도움말 출력
{
	gotoxy(15, 13);
	printf("1. 화면에 나오는 영어단어를 똑같이 따라 입력해주세요. ");
	ColorSet(12);
	printf("빨리 입력");
	ColorSet(7);
	printf("할 수록 더 많은 점수를 얻습니다.");
	gotoxy(15, 14);
	printf("2. 체력이 다 떨어지면 점수와 상관없이 ");
	ColorSet(14);
	printf("게임오버");
	ColorSet(7);
	printf("입니다. 정확히 입력합시다!!");
	gotoxy(15, 15);
	printf("3. 콤보를 쌓으면 ");
	ColorSet(10);
	printf("추가 점수");
	ColorSet(7);
	printf("를 획득하실 수 있습니다. 고득점을 노려보세요!");
	gotoxy(15, 16);
	printf("4. 체력이 떨어지면 일정확률로 ");
	ColorSet(11);
	printf("이벤트 단어");
	ColorSet(7);
	printf("가 출몰합니다. 맞혀서 체력을 회복합시다~");
	gotoxy(15, 17);
	printf("5. 쉬움이나 보통 난이도를 ");
	ColorSet(13);
	printf("클리어");
	ColorSet(7);
	printf("시 자동으로 다음 난이도로 넘어갑니다. 성장한 실력을 보여주세요!");
	gotoxy(15, 19);
	printf("메인화면으로 돌아가고 싶다면 아무 숫자나 입력하세요.");
	int n;
	scanf("%d", &n);
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