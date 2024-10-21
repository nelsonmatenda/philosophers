#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	int n;
	int id = fork();
	if (id == 0)
		n = 1;
	else
		n = 6;

	if (id != 0)
		wait(NULL);

	int i = n;

	while (i < n + 5)
	{
		printf("%d ", i++);
		fflush(stdout);
	}
	if (id != 0)
		puts("");
	return (0);
}
