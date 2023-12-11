/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philo_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <mbartsch@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:42:03 by mbartsch          #+#    #+#             */
/*   Updated: 2023/11/28 13:45:35 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	init_philos(t_control *controler)
{
	int	z;

	z = 0;
	controler->start_time = new_time();
	while (z < controler->number_philos)
	{
		controler->philos[z].philo_nbr = z + 1;
		controler->philos[z].last_meal = controler->start_time;
		controler->philos[z].ate_nbr = 0;
		controler->philos[z].control = controler;
		z++;
	}
	return (0);
}

int	lonely_life(t_philo *philo)
{
	sem_wait(philo->control->cutlery);
	use_pen(philo, "has taken a Fork");
	sem_post(philo->control->cutlery);
	usleep(philo->control->die_time * 1000);
	use_pen(philo, "has died");
	sem_post(philo->control->all_alive);
	return (0);
}

void	use_pen(t_philo *philo, char *str)
{
	sem_wait(philo->control->pen);
	printf("%lld ", (new_time() - philo->control->start_time));
	printf("%d ", philo->philo_nbr);
	printf("%s\n", str);
	sem_post(philo->control->pen);
}

static void	dinner_time(t_philo *philo)
{
	sem_wait(philo->control->cutlery);
	use_pen(philo, "has taken a fork");
	sem_wait(philo->control->cutlery);
	use_pen(philo, "has taken a fork");
	sem_wait(philo->control->dead);
	philo->last_meal = new_time();
	sem_post(philo->control->dead);
	use_pen(philo, "is eating");
	usleep(philo->control->eat_time * 1000);
	sem_post(philo->control->cutlery);
	sem_post(philo->control->cutlery);
	philo->ate_nbr = philo->ate_nbr + 1;
}

int	philo_life(t_philo *philo)
{
	while (1)
	{
		dinner_time(philo);
		if (philo->control->number_eat != -1 && philo->ate_nbr >= \
			philo->control->number_eat)
			break ;
		use_pen(philo, "is_sleeping");
		usleep(philo->control->sleep_time * 1000);
		use_pen(philo, "is_thinking");
		usleep(philo->control->eat_time);
	}
	pthread_join(philo->devil, NULL);
	return (0);
}
