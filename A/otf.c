#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int main(int ac, char** ag)
{
	int stdout_bk;

	if(ac != 2)
	{
		printf("Usage: ./otf [program name]");
		return 0;
	}
	stdout_bk = dup(fileno(stdout));
	char file_path[20] = "./";
	strcat(file_path, ag[1]);
	int pipefd[2];
	pipe(pipefd);
	dup2(pipefd[1], fileno(stdout));

	system(file_path);
	fflush(stdout);
	close(pipefd[1]);

	dup2(stdout_bk, fileno(stdout));

	char buf[1001];
	read(pipefd[0], buf, 1000);
	
	printf("This is the buffer\n %s", buf);

	int result_file = open("result.txt", O_CREAT | O_RDWR | O_NONBLOCK);
	write(result_file, buf, strlen(buf));
	close(result_file);
	return 0;
}
