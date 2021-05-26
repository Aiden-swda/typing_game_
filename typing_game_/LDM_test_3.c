//이다민 테스트 파일3
#include "main.h"
#define SIZE 6

int game_run()
{

	int a; //랜덤 숫자 받을 변수
	int check; //문자열 비교한 값 담는 변수
	int score = 0; //점수 변수
	int heart = 5; //남은 목숨 변수
	clock_t start, end;
	double result; //시간값을 저장하기 위한 변수
	int wordLength;

	char ch;
	int s_time, j = 0;

	//system("mode con cols=120 lines=45"); //콘솔창 크기
	system("title 건덕이를 잡아라!"); //콘솔창 제목
	system("cls"); // 콘솔창 초기화
	//srand(time(NULL));
	gotoxy(110, 0);
	printf("■■■■■\n"); //체력바 테스트

	srand(time(0));
	s_time = time(0);
	a = get_random_word(&wordLength);
	gotoxy(COLS / 2 - 5, 3);
	printf("%s\n", wordBase[a]);

	while (1)
	{
		char* inputArray = (int*)malloc(sizeof(char) * wordLength);
		//char input[wordLength]; //입력받을 단어 배열
		
		//a = get_random_word(); //배열에서 단어 추출하기 위한 랜덤 인덱스 값
		//gotoxy(COLS / 2 - 5, 3);
		//printf("%s\n", wordBase[a]); //배열에서 랜덤 추출된 단어 출력

		if (time(0) == s_time + 5)
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
			free(inputArray);
		}
		if (_kbhit())
		{
			//gotoxy(COLS / 2 - 5, 5);
			ch = _getch();
			if (ch == 27)
			{
				break;
			}
			//printf("%c", ch);
			if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
			{
				printf("%c", ch);
				inputArray[j] = ch;
				j++;
			}
		}
		if (j >= wordLength)
		{
			//printf("%s\n", input);
			inputArray[wordLength] = 0;
			for (int i = 0; wordBase[a][i] != 0; i++)  //배열값 마지막에 붙어있는 \n 제거
			{
				if (wordBase[a][i] == '\n')
				{
					wordBase[a][i] = 0;
					break;
				}
			}
			check = strcmp(inputArray, wordBase[a]); //문자열 비교
			//printf("%d", check);
			
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
			free(inputArray);
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
