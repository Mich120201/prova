/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prova_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 10:10:19 by mvolpi            #+#    #+#             */
/*   Updated: 2022/09/23 10:10:21 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

int	mails = 0;
pthread_mutex_t	mutex;

void	*threads()
{
	for (int i = 0; i < 10000000; i++)
	{
		pthread_mutex_lock(&mutex);
		mails++;
		pthread_mutex_unlock(&mutex);
	}
}

int	main(int argc, char **argv)
{
	pthread_t	t[4];
	int	i;

	pthread_mutex_init(&mutex, NULL);
	for (i = 0; i < 4; i++)
	{
		if (pthread_create(t + i, NULL, &threads, NULL) != 0)
		{
			perror("create therad: fail!");
			return (1);
		}
		printf("thread %d: created!\n", i);
		sleep(1);
		if (pthread_join(t [i], NULL) != 0)
			return (2);
		printf("thread %d: has finished execution!\n", i);
		sleep(1);
	}
	pthread_mutex_destroy(&mutex);
	printf("numeber of mails: %d\n", mails);
	return (0);
}
