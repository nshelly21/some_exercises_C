#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int ac, char** ag)
{
	int initial_position;
	int final_position;
	char *frase;
	char buffer[1000];//define a buffer with static memory

	if(ac != 4)//check necesary arguments cuantity for this program
	{
		printf("Usage: ./program_one [file path] [intial position]  [final position]");
		return 0;
	}

    FILE* f = fopen(ag[1], "r");//open a file with in the path given
	if(f == NULL)
	{
		printf("Wrong file path...");	
		return 0;
	}
	initial_position = atoi(ag[2]);//string to int
	final_position = atoi(ag[3]);//string to int
    fseek(f, initial_position, SEEK_SET);//change the position from where we are going to read or write
    memset(buffer, 0, 1000);//put zeros on the buffer
    fread(buffer, 1, final_position, f);//read from f by 1 to 1000 symbols and put this in buffer
    printf("%s\n", buffer);//show the desired text
}
