/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_death_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <mbartsch@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:14:56 by mbartsch          #+#    #+#             */
/*   Updated: 2023/12/12 15:15:02 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*reaper(void *arg)
{
	t_control	*control;
	int			z;

	control = (t_control *) arg;
	z = 0;
	sem_wait(control->all_alive);
	while (z < control->number_philos)
	{
		kill(control->philo_pids[z], SIGTERM);
		z++;
	}
	return (NULL);
}

void	*devil(void *arg)
{
	t_philo		*philo;
	long long	time;

	philo = (t_philo *) arg;
	while (1)
	{
		sem_wait(philo->control->dead);
		time = philo->last_meal;
		sem_post(philo->control->dead);
		if (philo->ate_nbr < philo->control->number_eat)
			return (NULL);
		if (new_time() - time > philo->control->die_time)
		{
			sem_wait(philo->control->pen);
			printf("%lld ", (new_time() - philo->control->start_time));
			printf("%d ", philo->philo_nbr);
			printf("has died\n");
			sem_post(philo->control->all_alive);
			return (NULL);
		}
	}
}
