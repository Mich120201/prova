#include "file.h"

void	*threads()
{
	printf("test for threads\n");
	sleep(5);
	printf("endind test\n");
}

int	main(int srgc, char **argv)
{
	pthread_t	t1, t2;

	if (pthread_create(&t1, NULL, &threads, NULL) != 0)
		return (1);
	if (pthread_create(&t2, NULL, &threads, NULL) != 0)
		return (2);
	if (pthread_join(t1, NULL) != 0)
		return (3);
	if (pthread_join(t2, NULL) != 0)
		return (4);
	return (0);
}
