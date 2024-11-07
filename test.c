#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>


//passei aqui iracelma

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	int fd[2];

	if (pipe(fd) == -1)
	{
		printf("Error with pipe\n");
		return (1);
	}

	int id = fork();
	if (id == 0)
	{
		int x;
		printf("digite um numero: ");
		scanf("%d", &x);
		if (write(fd[1], &x, sizeof(int)) == -1)
		{
			printf("Error with write\n");
			return(2);
		}
		close(fd[1]);
	}
	else
	{
		//wait(NULL);
		close(fd[1]);
		int y;
		if(read(fd[0], &y, sizeof(int)) == -1)
		{
			printf("Error with read\n");
			return(2);
		}
		close(fd[0]);
		printf("valor pegado no child: %d\n", y);
	}
	return (0);
}
