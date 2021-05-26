
#include "main.h"
/*
//c.p. : 단계를 받아올건지?
/*
void game_run()
{
	char input[WORDLEN]; //입력받을 단어 배열
	int randomNum; //랜덤 숫자 받을 변수
	int check; //문자열 비교한 값 담는 변수
	int score = 0; //점수 변수
	int heart = 5; //남은 목숨 변수
	double timespent; //시간값을 저장하기 위한 변수
	randomNum = get_random_word();

	gotoxy(5, 5);
	printf("%d", score);
	gotoxy(110, 0);
	printf("■■■■■\n");
	timespent = get_input_check(&score, &check, randomNum);
	//check_answer(check, &score, &heart);
	switch (check)
	{
	case 0:
		gotoxy(COLS / 2 - 5, 10);
		score = score + 10;
		printf("맞았습니다!\n");
		break;
	case 1:
		gotoxy(COLS / 2 - 5, 10);
		heart = heart -1;
		printf("틀렸습니다!\n");
		break;
	case -1:
		gotoxy(COLS / 2 - 5, 10);
		heart = heart - 1;
		printf("틀렸습니다!\n");
		break;
	}
	life_bar(heart); //life_bar.c

	if (score >= 50) // 점수에 따른 동작
	{
		system("cls"); // 콘솔창 초기화
		gotoxy(COLS / 2 - 10, LINES / 2);
		printf("1단계를 클리어 하셨습니다!");
		Sleep(2000); //2초 딜레이
		return 1;
		//break;
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
		//break;
	}
}
/*
double get_input_check(int *score, int *check, int randomNum)
{
	char input[WORDLEN]; 
	double start, end, timespent; 

	gotoxy(COLS / 2 - 5, 3);
	printf("%s\n", wordBase[randomNum]); 

	start = time(0); 

	gotoxy(COLS / 2 - 5, 5);
	scanf("%s", input); 

	end = time(0); 
	timespent = end - start; //게임시간 측정

	printf("경과한 시간: %.2lf 초", timespent);
	Sleep(1000); //시간 보기 위해서 임시로 걸어놓은 딜레이
	
				 
	/*
	//* 난이도 조절 부분
	if ((int)timespent >= 4) 
	{
		score = score - (int)(timespent * 5); //경과한 시간에 비례하여 점수 차감
		heart = heart - 1; //목숨도 같이 차감
	}
	*/
	/*
	system("cls");

	for (int i = 0; wordBase[randomNum][i] != 0; i++)
	{
		if (wordBase[randomNum][i] == '\n')
		{
			wordBase[randomNum][i] = 0;
			break;
		}
	}

	*check = strcmp(input, wordBase[randomNum]); //문자열 비교
	
	return timespent;
}
/*
void check_answer(int check, int *score, int *heart) // 문자열 비교값에 따른 출력
{
	switch (check)  
	{
	case 0:
		gotoxy(COLS / 2 - 5, 10);
		printf("맞았습니다!\n");
		*score += 10;
		break;
	case 1:
		gotoxy(COLS / 2 - 5, 10);
		printf("틀렸습니다!\n");
		--*heart;
		break;
	case -1:
		gotoxy(COLS / 2 - 5, 10);
		printf("틀렸습니다!\n");
		--*heart;
		break;
	}
}
*/
