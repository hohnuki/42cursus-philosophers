#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
	int date = 0;
	pid_t pid = fork();

	if (pid == 0)
	{
		sleep(1);
		date = 10;
		printf("\x1b[36m[child = %d]\n\033[m", date);
		exit (0);
	}
	else
	{
		printf("\x1b[36m[parent = %d]\n\033[m", date);
		waitpid(pid, NULL, 0);
		printf("\x1b[36m[parent end = %d]\n\033[m", date);
	}
	return 0;
}