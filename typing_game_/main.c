#include "main.h"

int main()
{
	
	int menuInput,levelInput; //사용자 입력 (메뉴선택)

	//settings
	system("mode con cols=120 lines=45");
	system("title 건덕이를 잡아라!"); //콘솔창 제목
	srand(time(NULL));
	read_file();
	system("pause");
	system("cls");
	CursorView(0);
	catchmeifyoucan();  // 처음 큰 그림 나오는거
	Sleep(1000);        // 그림 나오는 1초
	while (1) {
		system("cls");
		//intro
		menuInput = first_menu();
		switch (menuInput)
		{
		case 0:
			//게임실행함수
			levelInput = second_menu();
			switch (levelInput)
			{
			case 0:
				game_run(7);
				continue;
			case 2:
				game_run(5);
				continue;
			case 4:
				game_run(3);
				continue;
			case 6:
				continue;
			}
			//game_run();
			break;
		case 2:
			//도움말 보기
			system("cls");
			screen();
			print_letter_in_box1(" < 도움말 보기 >");
			print_help();
			break;
		case 4:
			screen();
			gotoxy(2, LINES - 14);
			texts("총 점수 : ");
			printf("%d 점", totalScore);
			Sleep(2000);
			break;
		case 6:
			print_letter_in_box1("게임을 종료합니다.");
			return 0;
		}
	}
	system("pause");
	system("cls");

	return 0;
}
