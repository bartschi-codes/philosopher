/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <mbartsch@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:16:37 by mbartsch          #+#    #+#             */
/*   Updated: 2023/12/12 15:16:38 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	end_it_all(t_control *cntrl)
{
	int	z;

	z = 0;
	pthread_mutex_lock(&cntrl->dead);
	cntrl->all_alive = 0;
	pthread_mutex_unlock(&cntrl->dead);
	usleep(cntrl->eat_time);
	while (z < cntrl->number_philos)
	{
		pthread_mutex_destroy(&cntrl->cutlery[z]);
		z++;
	}
	pthread_mutex_destroy(&cntrl->satisfied);
	pthread_mutex_destroy(&cntrl->dead);
	pthread_mutex_destroy(&cntrl->pen);
	free(cntrl);
}

int	thread_control(t_control *cntrl)
{
	int	z;

	z = 0;
	while (z < cntrl->number_philos)
	{
		if (pthread_join(cntrl->philos[z].thread_number, NULL))
			return (1);
		z++;
	}
	pthread_join(cntrl->reaper, NULL);
	end_it_all(cntrl);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_control	*cntrl;

	if (argc != 5 && argc != 6)
		return (\
		printf("wrong input\n./philo nbr_philo die_time eat_time"
				" sleep_time [nbr_eat]\n"), 1);
	if (init_cntrl(argv, &cntrl))
		return (printf("wrong input\n./philo nbr_philo die_time eat_time"
				" sleep_time [nbr_eat]\n"), 1);
	if (god(cntrl))
		return (end_it_all(cntrl), printf("thread error\n"), 1);
	return (thread_control(cntrl));
}
