#include "main.h"

int game_run(int level)
{
	char input[15]; //�Է¹��� �ܾ� �迭
	int a; //���� ���� ���� ����
	int check; //���ڿ� ���� �� ��� ����
	int score = 0; //���� ����
	int heart = 5; //���� ��� ����
	double result; //�ð����� �����ϱ� ���� ����

	int b = 0;

	char ch;
	int s_time, j = 0;

	int wordLength;

	//system("mode con cols=120 lines=45"); //�ܼ�â ũ��
	system("title �Ǵ��̸� ��ƶ�!"); //�ܼ�â ����
	system("cls"); // �ܼ�â �ʱ�ȭ
	//srand(time(NULL));
	gotoxy(110, 0);
	printf("������\n"); //ü�¹� �׽�Ʈ

	srand(time(0));
	s_time = time(0);
	a = get_random_word(&wordLength);
	printf("%d", wordLength);
	gotoxy(COLS / 2 - 5, 3);
	printf("%s\n", wordBase[a]);


	while (1)
	{
		//a = get_random_word(); //�迭���� �ܾ� �����ϱ� ���� ���� �ε��� ��
		//gotoxy(COLS / 2 - 5, 3);
		//printf("%s\n", wordBase[a]); //�迭���� ���� ����� �ܾ� ���

		if (time(0) == s_time + level) //�ð� Ȯ��
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
		}
		if (_kbhit())
		{

			ch = _getch();
			gotoxy(COLS / 2 - 5 + j, 5);

			//Backspace ó��
			if (ch == 8)
			{
				if (j > 0)
				{
					j--;
					printf("\b \b");
				}
			}

			//printf("%c", ch);
			if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
			{

				printf("%c", ch);
				input[j] = ch;
				j++;
				if (j == wordLength)
				{
					b = 1;
				}
			}
		}

		if (b == 1)
		{
			//printf("%s\n", input);
			input[wordLength] = 0;
			for (int i = 0; wordBase[a][i] != 0; i++)  //�迭�� �������� �پ��ִ� \n ����
			{
				if (wordBase[a][i] == '\n')
				{
					wordBase[a][i] = 0;
					break;
				}
			}
			check = strcmp(input, wordBase[a]); //���ڿ� ��
			//printf("%d", check);
			b = 0;
			system("cls");
			switch (check)  // ���ڿ� �񱳰��� ���� ���
			{
			case 0:
				gotoxy(COLS / 2 - 5, 10);
				switch (rand() % 4)  // �¾��� �� ��µǴ� �ؽ�Ʈ
				{
				case 0:
					printf("�¾ҽ��ϴ�!");
					break;
				case 1:
					printf("�� �ϰ� �־��!");
					break;
				case 2:
					printf("���� �Ƿ��̳׿�!");
					break;
				case 3:
					printf("������!");
					break;
				}
				printf("�¾ҽ��ϴ�!\n");
				score = score + 10;
				break;
			case 1:
				gotoxy(COLS / 2 - 5, 10);
				switch (rand() % 4)  // Ʋ���� �� ��µǴ� �ؽ�Ʈ
				{
				case 0:
					printf("�ƽ��׿�...");
					break;
				case 1:
					printf("���ݸ� �� ���غ��ô�.");
					break;
				case 2:
					printf("ħ���ϰ�!");
					break;
				case 3:
					printf("��Ʊ� ���� ����");
					break;
				}
				heart = heart - 1;
				break;
			case -1:
				gotoxy(COLS / 2 - 5, 10);
				switch (rand() % 4)  // Ʋ���� �� ��µǴ� �ؽ�Ʈ
				{
				case 0:
					printf("�ƽ��׿�...");
					break;
				case 1:
					printf("���ݸ� �� ���غ��ô�.");
					break;
				case 2:
					printf("ħ���ϰ�!");
					break;
				case 3:
					printf("��Ʊ� ���� ����");
					break;
				}
				heart = heart - 1;
				break;
			}
			life_bar(heart);


			gotoxy(5, 5);
			printf("���� ����: %d", score);  // ���� ���� ���
			a = get_random_word(&wordLength);
			gotoxy(COLS / 2 - 5, 3);
			printf("%s\n", wordBase[a]);
			s_time = time(0);
			j = 0;
		}

		if (score >= 50) // ������ ���� ����
		{
			system("cls"); // �ܼ�â �ʱ�ȭ
			gotoxy(COLS / 2 - 10, LINES / 2);
			printf("1�ܰ踦 Ŭ���� �ϼ̽��ϴ�!");
			Sleep(3000); // 3�� ������
			return 1;
			break;
		}
		else if (heart == 0) //����� 0�� �Ǿ������� ����
		{
			system("cls"); // �ܼ�â �ʱ�ȭ
			gotoxy(COLS / 2 - 10, LINES / 2);
			printf("�Ǵ��̰� Ż���ߴ�!�Ф�\n");
			Sleep(1500);
			system("cls"); // �ܼ�â �ʱ�ȭ
			gotoxy(COLS / 2 - 10, LINES / 2);
			printf("����� ����: %d", score);
			Sleep(1500); // 1.5�� ������

			system("cls"); // �ܼ�â �ʱ�ȭ
			print_gameover();
			Sleep(3500); // 3.5�� ������
			return 0;
			break;
		}
	}
}
