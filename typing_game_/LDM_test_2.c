#include "main.h"
#include <conio.h>
#define SIZE 6
#define TIME_LIMIT 5
void show_string(char*);
int test()
{
	char word[SIZE], ch, input[SIZE];
	int s_time, j = 0;

	srand(time(0));
	show_string(word);
	s_time = time(0);
	while (1)
	{
		if (time(0) == s_time + TIME_LIMIT)
		{
			system("cls");
			show_string(word);
			s_time = time(0);
			j = 0;
			//printf("\n");
			//printf("%s", input);
		}
		if (_kbhit())
		{
			ch = _getch();
			if (ch == 27)
			{
				break;
			}
			if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
			{
				printf("%c", ch);
				input[j] = ch;
				j++;
			}
			
		}
		
		



		if (j >= SIZE - 1)
		{
			printf("%s\n", input);
			input[SIZE - 1] = 0;
			if (!strcmp(word, input))
			{
				printf("\n축하합니다.\n");
				Sleep(1000);
			}
			system("cls");
			show_string(word);
			s_time = time(0);
			j = 0;
		}
		
	}


}

void show_string(char* w)
{
	int i;
	for ( i = 0; i <= 4; i++)
	{
		w[i] = 'a' + (rand() % 26);
	}
	w[i] = 0;
	printf("%s\n", w);
}