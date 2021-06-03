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
	int play_count = 0; // 게임 라운드 횟수 저장 변수

	char ch;
	int s_time, j = 0;

	int wordLength;

	//system("mode con cols=120 lines=45"); //콘솔창 크기
	system("cls"); // 콘솔창 초기화
	main_screen();
	//srand(time(NULL));
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
	s_time = time(0);
	a = get_random_word(&wordLength);
	
	event_word(a, heart);

	
	while (1)
	{
		//a = get_random_word(); //배열에서 단어 추출하기 위한 랜덤 인덱스 값
		//gotoxy(COLS / 2 - 5, 3);
		//printf("%s\n", wordBase[a]); //배열에서 랜덤 추출된 단어 출력
		if (time(0) == s_time + level) //시간 확인
		{
			ColorSet(7);
			system("cls");
			main_screen();
			heart = heart - 1;
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
			a = get_random_word(&wordLength);
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

			//printf("%c", ch);
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
			//printf("%s\n", input);
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
			//printf("%d", check);
			b = 0;
			
			switch (check)  // 문자열 비교값에 따른 출력
			{
			case 0:
				//gotoxy(COLS / 2 - 5, 10);
				play_count++;
				print_letter_in_box2("좋아요!");
				combo++;
				if (event == 1)
				{
					if (heart < 5)
					{
						printf("\n\t체력1획득!\n");
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
					print_letter_in_box2("아쉬워요..");
					break;
				case 1:
					print_letter_in_box2("좀 더 힘내보세요..!");
					break;
				case 2:
					print_letter_in_box2("뭐하시는 거죠?");
					break;
				case 3:
					print_letter_in_box2("제대로 좀 해보세요.");
					break;
				}
				if (combo > 0)
					combo--;
				heart = heart - 1;
				ColorSet(7);
				break;
			case -1:
				//gotoxy(COLS / 2 - 5, 10);
				play_count++;
				letter = rand() % 4;
				switch (letter)
				{
				case 0:
					print_letter_in_box2("아쉬워요..");
					break;
				case 1:
					print_letter_in_box2("좀 더 힘내보세요..!");
					break;
				case 2:
					print_letter_in_box2("뭐하시는 거죠?");
					break;
				case 3:
					print_letter_in_box2("제대로 좀 해보세요.");
					break;
				}
				if (combo > 0)
					combo--;
				heart = heart - 1;
				ColorSet(7);
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
			a = get_random_word(&wordLength);
			event_word(a, heart);
			s_time = time(0);
			j = 0;
		}
		if (score >= 100&&play_count==10) // 점수에 따른 동작
		{
			system("cls"); // 콘솔창 초기화
			main_screen();
			totalScore = totalScore + score; // 총 점수 관리

			//gotoxy(COLS / 2 - 10, LINES / 2);
			//레벨에 따른 출력 조절
			switch (level)
			{
			case 7:
				totalScore = totalScore + (combo * 10);
				ColorSet(7);
				print_letter_in_box2("'쉬움' 단계를 클리어 하셨습니다! 콤보 점수 : ");
				printf("%d 점", combo * 10);
				Sleep(2000);
				nextInput = ask_next_level();
				switch (nextInput) {
				case 0:
					game_run(5);
					break;
				case 2:
					break;
				}
				break;
			case 5:
				totalScore = totalScore + (combo * 20);
				ColorSet(7);
				print_letter_in_box2("'보통' 단계를 클리어 하셨습니다! 콤보 점수 : ");
				printf("%d 점", combo * 20);
				Sleep(2000);
				nextInput = ask_next_level();
				switch (nextInput) {
				case 0:
					game_run(3);
					break;
				case 2:
					break;
				}
				break;
			case 3:
				totalScore = totalScore + (combo * 30);
				ColorSet(7);
				print_letter_in_box2("'어려움' 단계를 클리어 하셨습니다! 콤보 점수 : ");
				printf("%d 점", combo * 30);
				Sleep(2000);
				ending_credit();  // 엔딩 크레딧
				system("cls");
				gotoxy(COLS / 2, LINES / 2);
				printf("\n메인메뉴로 돌아갑니다.");
				Sleep(2000);
				break;
			}
			//Sleep(2000); //2초 딜레이
			break;
		}
		else if (heart == 0|| play_count == 10) //목숨이 0이 되었을 때, 라운드 종료시의 점수가 낮았을 때의 동작
		{
			totalScore = totalScore + score; //총 점수 관리
			ColorSet(7);

			system("cls"); // 콘솔창 초기화
			//main_screen();
			print_letter_in_box2("건덕이가 탈출했다!ㅠㅠ");
			Sleep(1000);
			system("cls"); // 콘솔창 초기화
			//main_screen();
			print_letter_in_box2("당신의 점수: ");
			//Sleep(15);
			printf("%d", score);
			Sleep(3000); //1초 딜레이

			system("cls"); // 콘솔창 초기화
			//main_screen();
			print_gameover();
			Sleep(2000); //1초 딜레이
			return 0;
			break;
		}
	}
}
