#include "main.h"

int main()
{
	
	int menuInput,levelInput; //����� �Է� (�޴�����)

	//settings
	system("mode con cols=120 lines=45");
	system("title �Ǵ��̸� ��ƶ�!"); //�ܼ�â ����
	srand(time(NULL));
	read_file();
	game_run(5);
	system("pause");
	system("cls");
	English();
	while (1) {
		system("cls");
		//intro
		menuInput = first_menu();
		switch (menuInput)
		{
		case 0:
			//���ӽ����Լ�
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
			//���� ����
			system("cls");
			screen();
			print_letter_in_box(" < ���� ���� >");
			print_help();
			break;
		case 4:
			screen();
			gotoxy(2, LINES - 14);
			texts("�� ���� : ");
			printf("%d ��", totalScore);
			Sleep(2000);
			break;
		case 6:
			print_letter_in_box("������ �����մϴ�.");
			return 0;
		}
	}
	system("pause");
	system("cls");

	return 0;
}
