#include "main.h"

int main()
{
	
	int input; //사용자 입력 (메뉴선택)

	//settings
	system("mode con cols=120 lines=45");
	srand(time(NULL));
	read_file();
	
	system("pause");
	system("cls");
	
	//intro
	first();
	screen();
	print_letter("메뉴를 입력하세요 : ");
	input = input_menu();
	switch (input)
	{
	case 1:
		//게임실행함수
		game_run();
		break;
	case 2:
		//도움말 보기
		screen();
		print_letter("도움말 보기");
		break;
	case 3:
		screen();
		print_letter("총 점수 : ");
		printf("%d \n", totalScore);
		break;
	case 4:
		return 0;
	}

	system("pause");
	system("cls");

	//game run
	
	//for(int i = 0; i = 5; i++)
	
	return 0;
}
