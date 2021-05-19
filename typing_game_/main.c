#include "main.h"

int main()
{
	system("mode con cols=120 lines=45");
	srand(time(NULL));
	
	story();

	//first();
	read_file();
	
	return 0;
}
