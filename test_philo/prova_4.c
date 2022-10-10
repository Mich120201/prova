/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prova_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 10:13:25 by mvolpi            #+#    #+#             */
/*   Updated: 2022/09/23 10:36:06 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

void	*roll_dice()
{
	int	value = (rand() % 6) + 1;
	int	*result = malloc(sizeof(int));
	*result = value;
	printf("thread result: %p\n", result);
	return (void *) result;
}

int	main(int argc, char **argv)
{
	int	*res;
	srand(time(NULL));
	pthread_t	t;

	if (pthread_create(&t, NULL, &roll_dice, NULL) != 0)
		return (1);
	if (pthread_join(t, (void**) &res) != 0)
		return (2);
	printf("main res: %p\n", res);
	printf("result: %d\n", *res);
	free(res);
	return (0);
}
