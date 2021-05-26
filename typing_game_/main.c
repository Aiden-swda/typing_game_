#include "main.h"

int main()
{
	
	int menuInput,levelInput; //사용자 입력 (메뉴선택)

	//settings
	system("mode con cols=120 lines=45");
	srand(time(NULL));
	read_file();
	
	system("pause");

	while (1) {
		system("cls");
		//intro
		English();
		first();
		screen();
		emoticon();
		print_letter("메뉴를 입력하세요 : ");
		menuInput = input_menu();
		switch (menuInput)
		{
		case 1:
			//게임실행함수
			show_level_select();
			screen();
			print_letter("메뉴를 입력하세요 : ");
			levelInput = get_levelInput();
			switch (levelInput)
			{
			case 1:
				game_run(7);
				continue;
			case 2:
				game_run(5);
				continue;
			case 3:
				game_run(3);
				continue;
			case 4:
				continue;
			}
			//game_run();
			break;
		case 2:
			//도움말 보기
			system("cls");
			screen();
			print_letter("도움말 보기");
			print_help();
			break;
		case 3:
			screen();
			print_letter("총 점수 : ");
			printf("%d \n", totalScore);
			break;
		case 4:
			break;
		}
	}
	system("pause");
	system("cls");

	return 0;
}
