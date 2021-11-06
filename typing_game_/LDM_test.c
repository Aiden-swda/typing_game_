

#include "main.h"

int game_run()
{
	char input[20]; //입력받을 단어 배열
	int a; //랜덤 숫자 받을 변수
	int check; //문자열 비교한 값 담는 변수
	int score = 0; //점수 변수
	int heart = 5; //남은 목숨 변수
	clock_t start, end; 
	double result; //시간값을 저장하기 위한 변수


	
	//system("mode con cols=120 lines=45"); //콘솔창 크기
	system("title 건덕이를 잡아라!"); //콘솔창 제목
	system("cls"); // 콘솔창 초기화
	//srand(time(NULL));
	gotoxy(110, 0);
	printf("■■■■■\n"); //체력바 테스트
	

	while (1)
	{
		gotoxy(5, 5);
		printf("%d", score);
		a = get_random_word(&wordLength); //배열에서 단어 추출하기 위한 랜덤 인덱스 값
		gotoxy(COLS/2-5, 3);
		printf("%s\n", wordBase[a]); //배열에서 랜덤 추출된 단어 출력

	
		start = clock(); //시간측정 시작
		
		gotoxy(COLS / 2 - 5, 5);
		scanf("%s", input); //사용자 입력 문자열 받아오기
		//gets_s(input, 20);
		end = clock(); //시간 측정 정지
		result = (double)(end - start) / CLOCKS_PER_SEC; //시간 측정값
		
		printf("경과한 시간: %f\n", result);
		
		Sleep(1000); //시간 보기 위해서 임시로 걸어놓은 딜레이
		if ((int)result >= 4) //난이도 조절 부분
		{
			score = score - (int)(result*5); //경과한 시간에 비례하여 점수 차감
			heart = heart - 1; //목숨도 같이 차감
			
		}
		
		system("cls"); // 콘솔창 초기화

		for (int i = 0; wordBase[a][i] !=0 ; i++)  //배열값 마지막에 붙어있는 \n 제거
		{
			if (wordBase[a][i] == '\n')
			{
				wordBase[a][i] = 0;
				break;
			}
		}

		check = strcmp(input, wordBase[a]); //문자열 비교
		printf("%d", check);

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
		switch (heart) // 목숨값에 따른 체력바
		{
		case 0:
			gotoxy(110, 0);
			printf("□□□□□\n");
			break;
		case 1:
			gotoxy(110, 0);
			printf("□□□□■\n");
			break;
		case 2:
			gotoxy(110, 0);
			printf("□□□■■\n");
			break;
		case 3:
			gotoxy(110, 0);
			printf("□□■■■\n");
			break; 
		case 4:
			gotoxy(110, 0);
			printf("□■■■■\n");
			break;
		case 5:
			gotoxy(110, 0);
			printf("■■■■■\n");
			break;
		}
		

		if (score>=50) // 점수에 따른 동작
		{
			system("cls"); // 콘솔창 초기화
			gotoxy(COLS / 2 - 10, LINES / 2);
			printf("1단계를 클리어 하셨습니다!");
			Sleep(2000); //2초 딜레이
			return 1;
			break;
		}
		else if (heart==0) //목숨이 0이 되었을때의 동작
		{
			system("cls"); // 콘솔창 초기화
			gotoxy(COLS / 2-10, LINES / 2);
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
