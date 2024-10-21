#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	int id1 = fork();
	int id2 = fork();

	if (id1 == 0)
	{
		if (id2 == 0)
			printf("in Y\n");
		else
			printf("in X\n");
	}
	else
	{
		if (id2 == 0)
			printf("in Z\n");
		else
			printf("in main(parent)\n");
	}
	while (wait(NULL) != -1)
	{
		printf("Wait for\n");
	}

	return (0);
}
