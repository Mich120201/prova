#include "file.h"

int	primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 19};

void	*routine(void *arg)
{
	int	index = *(int*)arg;
	printf("%d ", primes[index]);
	free(arg);
}

int	main(int argc, char **argv)
{
	pthread_t	t[10];
	int	i;
	for (i = 0; i < 10; i++)
	{
		int	*a = malloc(sizeof(int));
		*a = i;
		if (pthread_create(&t[i], NULL, &routine, a) != 0)
			printf("creation thread %d: fail!", i);
	}
	for (i = 0; i < 10; i++)
	{
		if (pthread_join(t[i], NULL) != 0)
			printf("join thread %d: fail!", i);
	} 
	return (0);
}
