//엑셀로부터 단어를 받는 함수를 구현

#include "main.h"

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
