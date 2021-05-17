/*

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define WORDNUM 6 //단어개수
#define WORDLEN 20 //단어글자수

int arrayNum;

//2차원 배열을 생성 
char wordBase[WORDNUM][WORDLEN];

void read_file()
{
	int i, j = 0;

	//파일열기 
	FILE* fp = fopen("hello.txt", "r");

	//for 문으로 한줄당 하나씩 배열에 저장 
	for (i = 0; i < WORDLEN; i++)
	{
		fgets(wordBase[j], WORDLEN, fp);
		j++;
	}

	fclose(fp);

}

int get_random_word()
{
	arrayNum = rand() % WORDNUM; //일단 어떤 단어 꺼낼지 정하기
	return arrayNum;
}

int main()
{
	int i, j, k;

	srand(time(NULL)); //시간 세팅

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

	//꺼낸단어 보여주기
	for (k = 0; k < WORDLEN; k++)
	{
		printf("%c", wordBase[arrayNum][k]);
	}
	//꺼낸단어 보여주기 -> 대문자로 (소문자 - 32 = 대문자)
	for (k = 0; k < WORDLEN; k++)
	{
		printf("%c", wordBase[arrayNum][k] - 32);
		//버그 발생 , 단어길이보다 짧을경우 -32했을때 깨진문자가 출력(WORDLEN보다 짧은만큼)
	}

	return 0;
}

*/