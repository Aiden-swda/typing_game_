/*

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define WORDNUM 6 //�ܾ��
#define WORDLEN 20 //�ܾ���ڼ�

int arrayNum;

//2���� �迭�� ���� 
char wordBase[WORDNUM][WORDLEN];

void read_file()
{
	int i, j = 0;

	//���Ͽ��� 
	FILE* fp = fopen("hello.txt", "r");

	//for ������ ���ٴ� �ϳ��� �迭�� ���� 
	for (i = 0; i < WORDLEN; i++)
	{
		fgets(wordBase[j], WORDLEN, fp);
		j++;
	}

	fclose(fp);

}

int get_random_word()
{
	arrayNum = rand() % WORDNUM; //�ϴ� � �ܾ� ������ ���ϱ�
	return arrayNum;
}

int main()
{
	int i, j, k;

	srand(time(NULL)); //�ð� ����

	read_file();

	for (i = 0; i < WORDNUM; i++)
	{
		for (j = 0; j < WORDLEN; j++)
		{
			printf("%c", wordBase[i][j]);
		}
	}
	printf("\n\n\n\n");

	get_random_word();

	//�����ܾ� �����ֱ�
	for (k = 0; k < WORDLEN; k++)
	{
		printf("%c", wordBase[arrayNum][k]);
	}
	//�����ܾ� �����ֱ� -> �빮�ڷ� (�ҹ��� - 32 = �빮��)
	for (k = 0; k < WORDLEN; k++)
	{
		printf("%c", wordBase[arrayNum][k] - 32);
		//���� �߻� , �ܾ���̺��� ª����� -32������ �������ڰ� ���(WORDLEN���� ª����ŭ)
	}

	return 0;
}

*/