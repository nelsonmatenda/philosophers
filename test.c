#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void	*routine()
{
	printf("From threads\n");
	sleep(2);
	printf("Finish\n");
}

int main(int ac, char **av)
{
	pthread_t	t1, t2;
	if(pthread_create(&t1, NULL, &routine, NULL) != 0)
		return (EXIT_FAILURE);
	if(pthread_create(&t2, NULL, &routine, NULL) != 0)
		return (EXIT_FAILURE);
	if(pthread_join(t1, NULL) != 0)
		return (EXIT_FAILURE);
	if(pthread_join(t2, NULL) != 0)
		return (EXIT_FAILURE);
	return (0);
}
