//�����κ��� �ܾ �޴� �Լ��� ����

#include "main.h"

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
