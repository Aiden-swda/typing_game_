#include "main.h"

int game_run(int level)
{
	char input[15]; //입력받을 단어 배열
	int a; //랜덤 숫자 받을 변수
	int check; //문자열 비교한 값 담는 변수
	int score = 0; //점수 변수
	int heart = 5; //남은 목숨 변수
	double result; //시간값을 저장하기 위한 변수
	int nextInput;
	int combo = 0;
	int letter = 0; //답이 틀리거나 맞을 때 출력될 텍스트를 위한 변수
	int b = 0;
	int play_count = 1; // 게임 라운드 횟수 저장 변수
	char ch;
	int s_time, j = 0;
	int wordLength;

	system("cls"); // 콘솔창 초기화
	main_screen();
	gotoxy(96, 4);
	ColorSet(12);
	printf("■■■■■"); //체력바 테스트
	ColorSet(7);
	print_full();  //건덕이 출력
	srand(time(0));
	gotoxy(10, 4);
	printf("단계 점수 : %d", score);
	gotoxy(10, 5);
	printf("     콤보 : %d", combo);
	gotoxy(10, 6);
	printf("   라운드 : %d", play_count);
	gotoxy(50, 5);
	printf("TIME LIMIT : %ds", level);
	s_time = time(0);
	a = get_random_word(&wordLength,level);	
	event_word(a, heart);	
	while (1)
	{
		if (time(0) == s_time + level) //시간 확인
		{
			ColorSet(7);
			system("cls");
			main_screen();
			heart = heart - 1;
			story(15);
			Sleep(1000);
			life_bar(heart);
			if (combo > 0)
				combo--;
			play_count++;
			gotoxy(10, 4);
			printf("단계 점수 : %d", score);
			gotoxy(10, 5);
			printf("     콤보 : %d", combo);
			gotoxy(10, 6);
			printf("   라운드 : %d", play_count);
			gotoxy(50, 5);
			printf("TIME LIMIT : %ds", level);
			a = get_random_word(&wordLength,level);
			event_word(a, heart);
			s_time = time(0);
			j = 0;
		}
		if (_kbhit())
		{
			ColorSet(7);
			ch = _getch();
			gotoxy(COLS / 2 - 5 + j, 28);
			//Backspace 처리
			if (ch == 8)
			{
				if (j > 0)
				{
					j--;
					printf("\b \b");
				}
			}
			if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
			{

				printf("%c", ch);
				input[j] = ch;
				j++;
				if (j == wordLength)
				{
					b = 1;
				}
			}
		}
		if (b == 1)
		{
			input[wordLength] = 0;
			for (int i = 0; wordBase[a][i] != 0; i++)  //배열값 마지막에 붙어있는 \n 제거
			{
				if (wordBase[a][i] == '\n')
				{
					wordBase[a][i] = 0;
					break;
				}
			}
			check = strcmp(input, wordBase[a]); //문자열 비교
			b = 0;			
			switch (check)  // 문자열 비교값에 따른 출력
			{
			case 0:
				play_count++;
				letter = rand() % 4;
				switch (letter)
				{
				case 0:
					story(19);
					Sleep(500);
					break;
				case 1:
					story(20);
					Sleep(500);
					break;
				case 2:
					story(21);
					Sleep(500);
					break;
				case 3:
					story(22);
					Sleep(500);
					break;
				}
				combo++;
				if (event == 1)
				{
					if (heart < 5)
					{
						story(16);
						Sleep(1000);
						heart = heart + 1;
					}
				}
				score = score + 10;
				ColorSet(7);
				break;
			case 1:
				//gotoxy(COLS / 2 - 5, 10);
				play_count++;
				letter = rand() % 4;
				switch (letter)
				{
				case 0:
					story(11);
					Sleep(500);
					break;
				case 1:
					story(12);
					Sleep(500);
					break;
				case 2:
					story(13);
					Sleep(500);
					break;
				case 3:
					story(14);
					Sleep(500);
					break;
				}
				if (combo > 0)
					combo--;
				heart = heart - 1;
				ColorSet(7);
				story(15);
				Sleep(1000);
				break;
			case -1:
				//gotoxy(COLS / 2 - 5, 10);
				play_count++;
				letter = rand() % 4;
				switch (letter)
				{
				case 0:
					story(11);
					Sleep(500);
					break;
				case 1:
					story(12);
					Sleep(500);
					break;
				case 2:
					story(13);
					Sleep(500);
					break;
				case 3:
					story(14);
					Sleep(500);
					break;
				}
				if (combo > 0)
					combo--;
				heart = heart - 1;
				ColorSet(7);
				story(15);
				Sleep(1000);
				break;
			}
			Sleep(1000);
			system("cls");
			main_screen();
			life_bar(heart);
			gotoxy(10, 4);
			printf("단계 점수 : %d", score);
			gotoxy(10, 5);
			printf("     콤보 : %d", combo);
			gotoxy(10, 6);
			printf("   라운드 : %d", play_count);
			gotoxy(50, 5);
			printf("TIME LIMIT : %ds", level);
			a = get_random_word(&wordLength,level);
			event_word(a, heart);
			s_time = time(0);
			j = 0;
		}
		if (score >= 50&&play_count==9) // 점수에 따른 동작
		{
			system("cls"); // 콘솔창 초기화
			main_screen();
			gotoxy(37, 37);
			printf("                                          ");
			totalScore = totalScore + score; // 총 점수 관리
			//레벨에 따른 출력 조절
			switch (level)
			{
			case TIMELIMIT_EASY:
				totalScore = totalScore + (combo * 10);
				ColorSet(7);
				story(31);
				printf("%d 점", combo * 10);
				Sleep(1500);
				story(8);
				Sleep(1500);
				story(24);
				Sleep(1500);
				nextInput = ask_next_level();
				switch (nextInput) {
				case 0:
					game_run(TIMELIMIT_NORMAL);
					break;
				case 2:
					break;
				}
				break;
			case TIMELIMIT_NORMAL:
				totalScore = totalScore + (combo * 20);
				ColorSet(7);
				story(32);
				printf("%d 점", combo * 20);
				Sleep(1500);
				story(9);
				Sleep(1500);
				story(25);
				Sleep(2000);
				nextInput = ask_next_level();
				switch (nextInput) {
				case 0:
					game_run(TIMELIMIT_HARD);
					break;
				case 2:
					break;
				}
				break;
			case TIMELIMIT_HARD:
				totalScore = totalScore + (combo * 30);
				ColorSet(7);
				story(10);
				Sleep(1500);
				story(33);
				printf("%d 점", combo * 30);
				Sleep(1500);

				gotoxy(32, 37);
				printf("                                              ");
				gotoxy(40, 37);
				printf("[계속하려면 스페이스 바를 누르시오]");

				for (int i = 26; i < 31; i++) {
					story(i);
					char ch = _getch();
					if (ch == 32) {
						main_screen();
						gotoxy(32, 37);
						printf("                                              ");
						gotoxy(40, 37);
						printf("[계속하려면 스페이스 바를 누르시오]");
					}
				}
				gotoxy(32, 37);
				printf("                                              ");

				Sleep(2000);
				ending_credit();  // 엔딩 크레딧
				system("cls");
				gotoxy(COLS / 2, LINES / 2);
				printf("메인메뉴로 돌아갑니다.");
				Sleep(2000);
				break;
			}
			break;
		}
		else if (heart == 0|| play_count == 9) //목숨이 0이 되었을 때, 라운드 종료시의 점수가 낮았을 때의 동작
		{
			totalScore = totalScore + score; //총 점수 관리
			ColorSet(7);
			story(23);
			Sleep(1000);
			system("cls"); // 콘솔창 초기화
			main_screen();
			print_letter_in_box2("당신의 점수: ");
			printf("%d점", score);
			Sleep(3000); //1초 딜레이
			system("cls"); // 콘솔창 초기화
			print_gameover();
			Sleep(2000); //1초 딜레이
			return 0;
			break;
		}
	}
}
