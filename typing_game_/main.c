#include "main.h"

int main()
{
	
	int input; //����� �Է� (�޴�����)

	//settings
	system("mode con cols=120 lines=45");
	srand(time(NULL));
	read_file();
	
	system("pause");
	system("cls");
	
	//intro
	first();
	screen();
	print_letter("�޴��� �Է��ϼ��� : ");
	input = input_menu();
	switch (input)
	{
	case 1:
		//���ӽ����Լ�
		game_run();
		break;
	case 2:
		//���� ����
		screen();
		print_letter("���� ����");
		break;
	case 3:
		screen();
		print_letter("�� ���� : ");
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
