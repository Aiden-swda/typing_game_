
#include "main.h"

//c.p. : �ܰ踦 �޾ƿð���?
void game_run() 
{
	char input[WORDLEN]; //�Է¹��� �ܾ� �迭
	int randomNum; //���� ���� ���� ����
	int check; //���ڿ� ���� �� ��� ����
	int score = 0; //���� ����
	int heart = 5; //���� ��� ����
	double timespent; //�ð����� �����ϱ� ���� ����

	timespent = get_input_check(&score, &check);
	check_answer(check, &score, &heart);
	life_bar(heart); //life_bar.c

	if (score >= 50) // ������ ���� ����
	{
		system("cls"); // �ܼ�â �ʱ�ȭ
		gotoxy(COLS / 2 - 10, LINES / 2);
		printf("1�ܰ踦 Ŭ���� �ϼ̽��ϴ�!");
		Sleep(2000); //2�� ������
		return 1;
	}
	else if (heart == 0) //����� 0�� �Ǿ������� ����
	{
		system("cls"); // �ܼ�â �ʱ�ȭ
		gotoxy(COLS / 2 - 10, LINES / 2);
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
	}
}

double get_input_check(int *score, int *check)
{
	char input[WORDLEN]; 
	double start, end, timespent; 

	printf("%s\n", wordBase[get_random_word()]); 

	start = time(0); 

	gotoxy(COLS / 2 - 5, 5);
	scanf("%s", input); 

	end = time(0); 
	timespent = end - start; //���ӽð� ����

	printf("����� �ð�: %.2lf ��", timespent);
	Sleep(1000); //�ð� ���� ���ؼ� �ӽ÷� �ɾ���� ������
	/*
	* ���̵� ���� �κ�
	if ((int)result >= 4) 
	{
		score = score - (int)(result * 5); //����� �ð��� ����Ͽ� ���� ����
		heart = heart - 1; //����� ���� ����

	}
	*/
	system("cls");
	*check = strcmp(input, wordBase[get_random_word()]); //���ڿ� ��
	
	return timespent;
}

void check_answer(int check, int *score, int *heart) // ���ڿ� �񱳰��� ���� ���
{
	switch (check)  
	{
	case 0:
		gotoxy(COLS / 2 - 5, 10);
		printf("�¾ҽ��ϴ�!\n");
		*score += 10;
		break;
	case 1:
		gotoxy(COLS / 2 - 5, 10);
		printf("Ʋ�Ƚ��ϴ�!\n");
		*heart--;
		break;
	case -1:
		gotoxy(COLS / 2 - 5, 10);
		printf("Ʋ�Ƚ��ϴ�!\n");
		*heart--;
		break;
	}
}

