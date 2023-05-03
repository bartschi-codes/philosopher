/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:44:11 by mbartsch          #+#    #+#             */
/*   Updated: 2023/05/03 16:57:34 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	philo_thread(t_philo_data *info, t_philosopher *philos[])
{
	int			i;
	pthread_t	*threads;

	i = 0;
	threads = (pthread_t *)malloc(sizeof(pthread_t) * info->num_philo);
	if (!threads)
		return (0);
	while (i < info->num_philo)
	{
		if (pthread_create(&threads[i], NULL, (void *)philo_philosopher, \
				(void *)philos[i]) == -1)
			return (-1);
		pthread_join(threads[i], NULL);
		i++;
	}
	return (1);
}
