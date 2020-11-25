#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int ac, char** ag)
{
	int position;
	char *phrase;
	char buffer[1000];//define a buffer with static memory

	if(ac != 4)//check necesary arguments cuantity for this program
	{
		printf("Usage: ./program_one [position] [file path]  [phrase]");
		return 0;
	}

    FILE* f = fopen(ag[2], "r");//open a file with in the path given
	if(f == NULL)
	{
		printf("Wrong file path...");	
		return 0;
	}
	position = atoi(ag[1]);//string to int
	phrase = ag[3];
    fseek(f, position, SEEK_SET);//change the position from where we are going to read or write
    fwrite(phrase, 1, strlen(phrase), f);
	printf("%s\n", buffer);//show the desired text
}
