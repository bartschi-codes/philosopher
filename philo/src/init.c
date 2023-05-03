/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:58:01 by mbartsch          #+#    #+#             */
/*   Updated: 2023/05/03 17:36:14 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static int	info_init(t_philo_data *info)
{
	info = (t_philo_data *)malloc(sizeof(t_philo_data));
	if (!info)
		return (0);
	info->num_philo = -1;
	info->die_time = -1;
	info->eat_time = -1;
	info->sleep_time = -1;
	info->num_eat = -1;
	return (1);
}

static int	create_philosophers(t_philo_data *info, t_philosopher **philos)
{
	int	z;

	z = 0;
	(*philos) = (t_philosopher *)malloc(sizeof(t_philosopher *) * info->num_philo);
	if (!philos)
		return (0);
	while (z < info->num_philo)
	{
		philos[z] = (t_philosopher *)malloc(sizeof(t_philosopher));
		if (!philos[z])
			return (0);
		z++;
	}
	return (1);
}

static int	init_philosophers(t_philo_data *info, t_philosopher **philos)
{
	struct timeval	start;
	int				z;

	z = 0;
	while (z < info->num_philo)
	{
		philos[z]->philosopher_nbr = z + 1;
		philos[z]->times_eaten = 0;
		philos[z]->info = info;
		z++;
	}
	return (1);
}

void	initer(int argc, char *argv[], t_philo_data *info, \
				t_philosopher **philos)
{
	if (!info_init(info))
		error_h("malloc error: info", info, *philos);
	if (!parse_input(argc, argv, info))
		error_h("wrong input: num_philo die_time eat_time sleep_time [num_eat]"\
			, info, *philos);
	if (!create_philosophers(info, philos))
		error_h("malloc error: philosophers", info, *philos);
	if (!init_philosophers(info, philos))
		error_h("init error: philosophers", info, *philos);
}
