//�̴ٹ� �׽�Ʈ ����
#include "main.h"

int game_test()
{
	char input[20]; //�Է¹��� �ܾ� �迭
	char ex_word[103][20] = { "dog", "cat", "bottle", "phone", "robot", "green", "elephant", "include", "sky", "game", "hyomin", 
		"jaemin", "max", "knife", "glass", "class", "art", "smart", "bell", "carry", "climb", "between", "blow", "album", "ago", "among", "animal", "any", "box", 
		"and", "board", "body", "child", "classmate", "city", "boy", "bridge", "clean", 
		"club", "coat", "bright", "coin", "chopstick", "coffee", "cold", "chance", "chalk", "chair", "cheap", "blue", 
		"before", "bowl", "aunt", "as", "away", "bicycle", "church", "card", "hold", 
		"chose", "come", "drink", "give", "get", "hurt", "lay","had", "feed", "lend", "met", "wsing", "throw", "wet", "tell", 
		"set", "wind", "wear", "write", "spend", "stand", "worn", "win", "sweep", "account", "achieve", "across", "accept", "above", "ability", "abuse", 
		"abnormal", "absurd", "acceptance", "according", "absent", "nation", "past", "value", "though", "person", "machine", "stand", "null" }; //�ܾ��
	int a; //���� ���� ���� ����
	int check; //���ڿ� ���� �� ��� ����
	int score = 0; //���� ����
	int heart = 5; //���� ��� ����
	clock_t start, end; 
	double result; //�ð����� �����ϱ� ���� ����


	
	system("mode con cols=120 lines=45"); //�ܼ�â ũ��
	system("title �Ǵ��̸� ��ƶ�!"); //�ܼ�â ����
	system("cls"); // �ܼ�â �ʱ�ȭ
	srand(time(NULL));
	gotoxy(110, 0);
	printf("������\n"); //ü�¹� �׽�Ʈ
	

	while (1)
	{
		gotoxy(5, 5);
		printf("%d", score);
		a = rand() % 103; //�迭���� �ܾ� �����ϱ� ���� ���� �ε��� ��
		gotoxy(COLS/2-5, 3);
		printf("%s\n", ex_word[a]); //�迭���� ���� ����� �ܾ� ���

		start = clock(); //�ð����� ����
		
		gotoxy(COLS / 2 - 5, 5);
		scanf("%s", input); //����� �Է� ���ڿ� �޾ƿ���
		end = clock(); //�ð� ���� ����
		result = (double)(end - start) / CLOCKS_PER_SEC; //�ð� ������
		
		printf("����� �ð�: %f", result);
		Sleep(1000); //�ð� ���� ���ؼ� �ӽ÷� �ɾ���� ������
		if ((int)result >= 4) //���̵� ���� �κ�
		{
			score = score - (int)(result*5); //����� �ð��� ����Ͽ� ���� ����
			heart = heart - 1; //����� ���� ����
			
		}
		
		system("cls"); // �ܼ�â �ʱ�ȭ
		check = strcmp(input, ex_word[a]); //���ڿ� ��

		switch (check)  // ���ڿ� �񱳰��� ���� ���
		{
		case 0:
			gotoxy(COLS / 2 - 5, 10);
			printf("�¾ҽ��ϴ�!\n");
			score = score + 10;
			break;
		case 1:
			gotoxy(COLS / 2 - 5, 10);
			printf("Ʋ�Ƚ��ϴ�!\n");
			heart = heart - 1;
			break;
		case -1:
			gotoxy(COLS / 2 - 5, 10);
			printf("Ʋ�Ƚ��ϴ�!\n");
			heart = heart - 1;
			break;
		}
		switch (heart) // ������� ���� ü�¹�
		{
		case 0:
			gotoxy(110, 0);
			printf("������\n");
			break;
		case 1:
			gotoxy(110, 0);
			printf("������\n");
			break;
		case 2:
			gotoxy(110, 0);
			printf("������\n");
			break;
		case 3:
			gotoxy(110, 0);
			printf("������\n");
			break; 
		case 4:
			gotoxy(110, 0);
			printf("������\n");
			break;
		case 5:
			gotoxy(110, 0);
			printf("������\n");
			break;
		}
		

		if (score>=50) // ������ ���� ����
		{
			system("cls"); // �ܼ�â �ʱ�ȭ
			gotoxy(COLS / 2 - 10, LINES / 2);
			printf("1�ܰ踦 Ŭ���� �ϼ̽��ϴ�!");
			Sleep(2000); //2�� ������
			return 1;
			break;
		}
		else if (heart==0) //����� 0�� �Ǿ������� ����
		{
			system("cls"); // �ܼ�â �ʱ�ȭ
			gotoxy(COLS / 2-10, LINES / 2);
			printf("�Ǵ��̰� Ż���ߴ�!�Ф�\n");
			Sleep(1000);
			system("cls"); // �ܼ�â �ʱ�ȭ
			gotoxy(COLS / 2 - 10, LINES / 2);
			printf("����� ����: %d", score);
			Sleep(1000); //1�� ������
			
			system("cls"); // �ܼ�â �ʱ�ȭ
			gotoxy(COLS / 2 - 10, LINES / 2);
			printf("���ӿ���");
			Sleep(1000); //1�� ������
			return 0;
			break;
		}
	}
}
