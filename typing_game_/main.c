#include "main.h"

int main()
{
	
	int menuInput,levelInput; //����� �Է� (�޴�����)

	//settings
	system("mode con cols=120 lines=45"); //�ܼ�â ũ��
	system("title �Ǵ��̸� ��ƶ�!"); //�ܼ�â ����
	srand(time(NULL)); //srand
	read_file(); //���� �б�
	system("pause"); 
	system("cls");
	CursorView(0);
	catchmeifyoucan();  // ó�� ū �׸� �����°�
	Sleep(1000);        // �׸� ������ 1��
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
				start_game();
				game_run(TIMELIMIT_EASY);
				continue;
			case 2:
				start_game();
				game_run(TIMELIMIT_NORMAL);
				continue;
			case 4:
				start_game();
				game_run(TIMELIMIT_HARD);
				continue;
			case 6:
				continue;
			}
			break;
		case 2:
			//���� ����
			system("cls");
			screen();
			print_letter_in_box1(" < ���� ���� >");
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
			print_letter_in_box1("������ �����մϴ�.");
			return 0;
		}
	}
	system("pause");
	system("cls");

	return 0;
}
