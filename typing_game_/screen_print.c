//처음 화면을 출력하는 소스 파일

#include "main.h"

int first_menu()  //첫 화면 출력하는 함수
{
	int x = COLS / 2 - 8;
	int y = LINES / 2 - 7;

	print_star();
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
	gotoxy(COLS / 2 - 12, LINES / 2 - 12);
	printf("=====================");
	gotoxy(COLS / 2 - 13, LINES / 2 - 11);
	printf("│     난이도 선택    │");
	gotoxy(COLS / 2 - 12, LINES / 2 - 10);
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
void catchmeifyoucan() // 첫 화면 출력
{
	gotoxy(0, 8);
	printf("                                                     @@          @@\n");
	printf("                                                  (@@              @@)\n");
	printf("                     @@)               @@          @:    (:@@:)    :@          @@               (@@\n");
	printf("                    @                 :#            @@@@@@0@@0@@@@@@            #:                 @\n");
	printf("                   (##@@#:      (#@#<--(@@@@      _-@@            @@-_      @@@@)-->#@#)     :#@@##)\n");
	printf("                        (@@@@@@@@@         @@@@@@@                    @@@@@@@         @@@@@@@@@)\n\n");
	//
	printf("                       #####    #   #######   #   ####  ####  ####  #   ######  #    ########  #      \n");
	printf("                           #    #   #         #   #   ##    ##   #  #       #   #          #   #          \n");
	printf("                          # #####   #    ######    # #        # #   #     ##    ###       #    #         \n");
	printf("                         #      #   #         #     #   #  #   #    #    #  #   #        #     #       \n");
	printf("                        #       #   #######   #     #          #    #   #    #  #       #      #        \n");
	printf("                          #                          #        #     #     #     #      #       #      \n");
	printf("                          #           #########       ##    ##      #     #######     #        #            \n");
	printf("                          #######             #         ####        #     #######    #         #            \n\n");
	//
	printf("            @@)                             * C A T C H M E I F Y O U C A N *                      (@@\n");
	printf("           @     @@         @@@)                                                        (@@@         @@     @\n");
	printf("          @    _@  @       @          @@@@@@    _____@@#<<(==)>>#@@_____    @@@@@@          @       @  @_    @\n");
	printf("          (#@@#@       @@@@:@@@@@@@@@@  || @@@@@  | @ << (-==-) >> @ |  @@@@@ ||  @@@@@@@@@@:@@@@       @#@@#)\n");
	printf("               @@@@@@@@              @@@@@   |  @@@@ --<< (==) >>-- @@@@  |   @@@@@              @@@@@@@@\n");
	printf("                                      @   @###@@@  @@@@_        _@@@@  @@@###@   @\n");
	printf("                                                       @-  ()  -@\n");
	printf("                                                        @------@\n");
	printf("                                                         @@__@@\n");
}
void print_gameover()
{
	ColorSet(12);  // gameover 문구 출력 시작
	gotoxy(3, 5);
	printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
	gotoxy(3, 6);
	printf("□□■■■■□□□□■■□□□■□□□□■□■■■■■■□□■■■■□□■□□□□■□■■■■■■□■■■■■□□");
	gotoxy(3, 7);
	printf("□■□□□□□□□■□□■□□■■□□■■□■□□□□□□■□□□□■□■□□□□■□■□□□□□□■□□□□■□");
	gotoxy(3, 8);
	printf("□■□□■■■□□■■■■□□■□■■□■□■■■■■■□■□□□□■□■□□□□■□■■■■■■□■■■■■□□");
	gotoxy(3, 9);
	printf("□■□□■■□□■□□□□■□■□□□□■□■□□□□□□■□□□□■□□■□□■□□■□□□□□□■□□□□■□");
	gotoxy(3, 10);
	printf("□□■■□■□□■□□□□■□■□□□□■□■■■■■■□□■■■■□□□□■■□□□■■■■■■□■□□□□■□");
	gotoxy(3, 11);
	printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
	ColorSet(10);  // gameover 문구 출력 끝
	gotoxy(COLS / 2 - 20, LINES / 2 - 4);  // 우는 소 출력 시작
	printf("□□□□□□□□□□□□□□□□□□□□□");
	gotoxy(COLS / 2 - 20, LINES / 2 - 3);
	printf("□□□□■□□□□□□□□□□□■□□□□");
	gotoxy(COLS / 2 - 20, LINES / 2 - 2);
	printf("□□□■□■□□■■■■■□□■□■□□□");
	gotoxy(COLS / 2 - 20, LINES / 2 - 1);
	printf("□□□■□□■■□□□□□■■□□■□□□");
	gotoxy(COLS / 2 - 20, LINES / 2);
	printf("□■■□□□□□□□□□□□□□□□■■□");
	gotoxy(COLS / 2 - 20, LINES / 2 + 1);
	printf("■□□□□■□□■□□□■□□■□□□□■");
	gotoxy(COLS / 2 - 20, LINES / 2 + 2);
	printf("□■■□□□■■□□□□□■■□□□■■□");
	gotoxy(COLS / 2 - 20, LINES / 2 + 3);
	printf("□□■□□■□□■□□□■□□■□□■□□");
	gotoxy(COLS / 2 - 20, LINES / 2 + 4);
	printf("□□■□□□□□□□□□□□□□□□■□□");
	gotoxy(COLS / 2 - 20, LINES / 2 + 5);
	printf("□□□■□□□□■□□□■□□□□■□□□");
	gotoxy(COLS / 2 - 20, LINES / 2 + 6);
	printf("□□□□■■□□□□□□□□□■■□□□□");
	gotoxy(COLS / 2 - 20, LINES / 2 + 7);
	printf("□□□□□□■■■■■■■■■□□□□□□");
	gotoxy(COLS / 2 - 20, LINES / 2 + 8);
	printf("□□□□□□□□□□□□□□□□□□□□□");  // 우는 소 출력 끝
	ColorSet(7);
}
void print_full()
{
	printf("  ♡          @@@@@           ♡          ");
	printf("           @@       @@                    ");
	printf("          @   @@@@    @                 ");
	printf("         @   @ /＼ @   @           ");
	printf("         @         @@@@@@@@@@@@@          ");
	printf("          @       @             @   ");
	printf("           @       @@@@@@@@@@@@@       ");
	printf("           @      @                   ");
	printf("          @       @                  ");
	printf("         @         @                  ");
	printf("        @           @                ");
	printf("       @             @              ");
	printf("      @               @             ");
}
void print_injured()
{
	printf("              @@@@@                ");
	printf("           @@       @@               ");
	printf("          @   @@@@    @          ");
	printf("         @   @ ● @   @                ");
	printf("         @         @@@@@@@@@@@@@       ");
	printf("          @       @             @    ");
	printf("           @       @@@@@@@@@@@@@        ");
	printf("           @      @               ");
	printf("          @       @               ");
	printf("         @         @              ");
	printf("        @           @               ");
	printf("       @             @              ");
	printf("      @               @             ");
}
void print_almost_die()
{
	printf("   @  @       @@@@@          @   @       ");
	printf("@          @@       @@    @         @     ");
	printf("    @     @   @@@@    @               @    ");
	printf("  @      @   @ xx  @   @               @   ");
	printf("         @         @@@@@@@@@@@@@       ");
	printf("          @       @             @     ");
	printf("           @       @@@@@@@@@@@@@       ");
	printf("           @      @                 ");
	printf("          @       @             ");
	printf("         @         @                         ");
	printf("        @           @                   ");
	printf("       @             @               ");
	printf("      @               @                ");
}