//이다민 테스트 파일3
#include "main.h"

int game_run()
{

	char input[15]; //입력받을 단어 배열
	int a; //랜덤 숫자 받을 변수
	int check; //문자열 비교한 값 담는 변수
	int score = 0; //점수 변수
	int heart = 5; //남은 목숨 변수
	double result; //시간값을 저장하기 위한 변수

	int b = 0;

	char ch;
	int s_time, j = 0;

	int wordLength;

	//system("mode con cols=120 lines=45"); //콘솔창 크기
	system("title 건덕이를 잡아라!"); //콘솔창 제목
	system("cls"); // 콘솔창 초기화
	//srand(time(NULL));
	gotoxy(110, 0);
	printf("■■■■■\n"); //체력바 테스트

	srand(time(0));
	s_time = time(0);
	a = get_random_word(&wordLength);
	printf("%d", wordLength);
	gotoxy(COLS / 2 - 5, 3);
	printf("%s\n", wordBase[a]);


	while (1)
	{
		//a = get_random_word(); //배열에서 단어 추출하기 위한 랜덤 인덱스 값
		//gotoxy(COLS / 2 - 5, 3);
		//printf("%s\n", wordBase[a]); //배열에서 랜덤 추출된 단어 출력

		if (time(0) == s_time + 5) //시간 확인
		{
			system("cls");
			heart = heart - 1;
			life_bar(heart);

			gotoxy(5, 5);
			printf("%d", score);
			a = get_random_word(&wordLength);
			gotoxy(COLS / 2 - 5, 3);
			printf("%s\n", wordBase[a]);
			s_time = time(0);
			j = 0;
		}
		if (_kbhit())
		{

			ch = _getch();
			gotoxy(COLS / 2 - 5 + j, 5);

			//Backspace 처리
			if (ch == 8)
			{
				if (j > 0)
				{
					j--;
					gotoxy(COLS / 2 - 5 + j, 5);
					printf(" ");
					gotoxy(COLS / 2 - 5 + j, 5);
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
			system("cls");
			switch (check)  // 문자열 비교값에 따른 출력
			{
			case 0:
				gotoxy(COLS / 2 - 5, 10);
				printf("맞았습니다!\n");
				score = score + 10;
				break;
			case 1:
				gotoxy(COLS / 2 - 5, 10);
				printf("틀렸습니다!\n");
				heart = heart - 1;
				break;
			case -1:
				gotoxy(COLS / 2 - 5, 10);
				printf("틀렸습니다!\n");
				heart = heart - 1;
				break;
			}
			life_bar(heart);


			gotoxy(5, 5);
			printf("%d", score);
			a = get_random_word(&wordLength);
			gotoxy(COLS / 2 - 5, 3);
			printf("%s\n", wordBase[a]);
			s_time = time(0);
			j = 0;
		}

		if (score >= 50) // 점수에 따른 동작
		{
			system("cls"); // 콘솔창 초기화
			gotoxy(COLS / 2 - 10, LINES / 2);
			printf("1단계를 클리어 하셨습니다!");
			Sleep(2000); //2초 딜레이
			return 1;
			break;
		}
		else if (heart == 0) //목숨이 0이 되었을때의 동작
		{
			system("cls"); // 콘솔창 초기화
			gotoxy(COLS / 2 - 10, LINES / 2);
			printf("건덕이가 탈출했다!ㅠㅠ\n");
			Sleep(1000);
			system("cls"); // 콘솔창 초기화
			gotoxy(COLS / 2 - 10, LINES / 2);
			printf("당신의 점수: %d", score);
			Sleep(1000); //1초 딜레이

			system("cls"); // 콘솔창 초기화
			gotoxy(COLS / 2 - 10, LINES / 2);
			printf("게임오버");
			Sleep(1000); //1초 딜레이
			return 0;
			break;
		}
	}
}
