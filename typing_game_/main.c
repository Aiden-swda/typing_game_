#include "main.h"

int main()
{
	
	int menuInput,levelInput; //사용자 입력 (메뉴선택)

	//settings
	system("mode con cols=120 lines=45");
	srand(time(NULL));
	read_file();
	
	system("pause");
	system("cls");
	catchmeifyoucan();  // 처음 큰 그림 나오는거
	Sleep(3000);        // 그림 나오는 3초
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
			print_letter_in_box(" < 도움말 보기 >");
			print_help();
			break;
		case 4:
			screen();
			print_letter_in_box(" 총 점수 : ");
			printf("%d \n", totalScore);
			break;
		case 6:
			return 0;
		}
	}
	system("pause");
	system("cls");

	return 0;
}
