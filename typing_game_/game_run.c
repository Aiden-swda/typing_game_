#include "main.h"

int game_run(int level)
{
	char input[15]; //�Է¹��� �ܾ� �迭
	int a; //���� ���� ���� ����
	int check; //���ڿ� ���� �� ��� ����
	int score = 0; //���� ����
	int heart = 5; //���� ��� ����
	double result; //�ð����� �����ϱ� ���� ����
	int nextInput;
	int combo = 0;
	int letter = 0; //���� Ʋ���ų� ���� �� ��µ� �ؽ�Ʈ�� ���� ����
	int b = 0;
	int play_count = 1; // ���� ���� Ƚ�� ���� ����

	char ch;
	int s_time, j = 0;

	int wordLength;

	//system("mode con cols=120 lines=45"); //�ܼ�â ũ��
	system("cls"); // �ܼ�â �ʱ�ȭ
	main_screen();
	//srand(time(NULL));
	gotoxy(96, 4);
	ColorSet(12);
	printf("������"); //ü�¹� �׽�Ʈ
	ColorSet(7);

	print_full();  //�Ǵ��� ���

	srand(time(0));
	gotoxy(10, 4);
	printf("�ܰ� ���� : %d", score);
	gotoxy(10, 5);
	printf("     �޺� : %d", combo);
	gotoxy(10, 6);
	printf("   ���� : %d", play_count);

	s_time = time(0);
	a = get_random_word(&wordLength,level);
	
	event_word(a, heart);

	
	while (1)
	{
		//a = get_random_word(); //�迭���� �ܾ� �����ϱ� ���� ���� �ε��� ��
		//gotoxy(COLS / 2 - 5, 3);
		//printf("%s\n", wordBase[a]); //�迭���� ���� ����� �ܾ� ���
		if (time(0) == s_time + level) //�ð� Ȯ��
		{
			ColorSet(7);
			system("cls");
			main_screen();
			heart = heart - 1;
			life_bar(heart);
			if (combo > 0)
				combo--;
			play_count++;
			gotoxy(10, 4);
			printf("�ܰ� ���� : %d", score);
			gotoxy(10, 5);
			printf("     �޺� : %d", combo);
			gotoxy(10, 6);
			printf("   ���� : %d", play_count);
			a = get_random_word(&wordLength,level);
			event_word(a, heart);
			s_time = time(0);
			j = 0;
		}
		if (_kbhit())
		{
			ColorSet(7);
			ch = _getch();
			gotoxy(COLS / 2 - 5 + j, 28);

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
			
			switch (check)  // ���ڿ� �񱳰��� ���� ���
			{
			case 0:
				//gotoxy(COLS / 2 - 5, 10);
				play_count++;
				letter = rand() % 4;
				switch (letter)
				{
				case 0:
					story(19);
					break;
				case 1:
					story(20);
					break;
				case 2:
					story(21);
					break;
				case 3:
					story(22);
					break;
				}
				combo++;
				if (event == 1)
				{
					if (heart < 5)
					{
						story(16);
						heart = heart + 1;
					}
				}
				score = score + 10;
				ColorSet(7);
				break;
			case 1:
				//gotoxy(COLS / 2 - 5, 10);
				play_count++;
				letter = rand() % 4;
				switch (letter)
				{
				case 0:
					story(11);
					break;
				case 1:
					story(12);
					break;
				case 2:
					story(13);
					break;
				case 3:
					story(14);
					break;
				}
				if (combo > 0)
					combo--;
				heart = heart - 1;
				ColorSet(7);
				break;
			case -1:
				//gotoxy(COLS / 2 - 5, 10);
				play_count++;
				letter = rand() % 4;
				switch (letter)
				{
				case 0:
					story(11);
					break;
				case 1:
					story(12);
					break;
				case 2:
					story(13);
					break;
				case 3:
					story(14);
					break;
				}
				if (combo > 0)
					combo--;
				heart = heart - 1;
				ColorSet(7);
				break;
			}
			Sleep(1000);
			system("cls");
			main_screen();
			life_bar(heart);

			gotoxy(10, 4);
			printf("�ܰ� ���� : %d", score);
			gotoxy(10, 5);
			printf("     �޺� : %d", combo);
			gotoxy(10, 6);
			printf("   ���� : %d", play_count);
			a = get_random_word(&wordLength,level);
			event_word(a, heart);
			s_time = time(0);
			j = 0;
		}
		if (score >= 50&&play_count==8) // ������ ���� ����
		{
			system("cls"); // �ܼ�â �ʱ�ȭ
			main_screen();
			gotoxy(37, 37);
			printf("                                          ");
			totalScore = totalScore + score; // �� ���� ����

			//gotoxy(COLS / 2 - 10, LINES / 2);
			//������ ���� ��� ����
			switch (level)
			{
			case 7:
				totalScore = totalScore + (combo * 10);
				ColorSet(7);
				story(31);
				printf("%d ��", combo * 10);
				Sleep(1500);
				story(8);
				Sleep(1500);
				story(24);
				Sleep(1500);
				nextInput = ask_next_level();
				switch (nextInput) {
				case 0:
					game_run(5);
					break;
				case 2:
					break;
				}
				break;
			case 5:
				totalScore = totalScore + (combo * 20);
				ColorSet(7);
				story(32);
				printf("%d ��", combo * 20);
				Sleep(1500);
				story(9);
				Sleep(1500);
				story(25);
				Sleep(2000);
				nextInput = ask_next_level();
				switch (nextInput) {
				case 0:
					game_run(3);
					break;
				case 2:
					break;
				}
				break;
			case 3:
				totalScore = totalScore + (combo * 30);
				ColorSet(7);
				story(10);
				Sleep(1500);
				story(33);
				printf("%d ��", combo * 30);
				Sleep(1500);

				gotoxy(32, 37);
				printf("                                              ");
				gotoxy(40, 37);
				printf("[����Ϸ��� �����̽� �ٸ� �����ÿ�]");

				for (int i = 26; i < 31; i++) {
					story(i);
					char ch = _getch();
					if (ch == 32) {
						main_screen();
						gotoxy(32, 37);
						printf("                                              ");
						gotoxy(40, 37);
						printf("[����Ϸ��� �����̽� �ٸ� �����ÿ�]");
					}
				}

				gotoxy(32, 37);
				printf("                                              ");

				Sleep(2000);
				ending_credit();  // ���� ũ����
				system("cls");
				gotoxy(COLS / 2, LINES / 2);
				printf("\n���θ޴��� ���ư��ϴ�.");
				Sleep(2000);
				break;
			}
			//Sleep(2000); //2�� ������
			break;
		}
		else if (heart == 0|| play_count == 5) //����� 0�� �Ǿ��� ��, ���� ������� ������ ������ ���� ����
		{
			totalScore = totalScore + score; //�� ���� ����
			ColorSet(7);
			story(23);

			system("cls"); // �ܼ�â �ʱ�ȭ
			main_screen();
			Sleep(1000);
			system("cls"); // �ܼ�â �ʱ�ȭ
			main_screen();
			print_letter_in_box2("����� ����: ");
			printf("%d", score);
			Sleep(3000); //1�� ������

			system("cls"); // �ܼ�â �ʱ�ȭ
			print_gameover();
			Sleep(2000); //1�� ������
			return 0;
			break;
		}
	}
}
