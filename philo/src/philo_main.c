/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:55:41 by mbartsch          #+#    #+#             */
/*   Updated: 2023/05/03 16:56:42 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	print_philos(t_philosopher *philo[])
{
	int	z;
	t_philosopher	*p;

	p = *philo;
	z = 0;
	while (p)
	{
		printf("nbr: %d\n", p->philosopher_nbr);
		z++;
		p = *(philo + z);
	}
}

void	print_info(t_philo_data *info)
{
	printf("num: %d\ndie_time %d\neat_time: %d\nsleep time: %d\nnum_eat: %d\n", \
					info->num_philo, info->die_time, info->eat_time, \
					info->sleep_time, info->num_eat);
}

int	main(int argc, char *argv[])
{
	t_philosopher	*philos;
	t_philo_data	*info;

	if (argc < 5 || argc > 6)
		error_h("wrong input", NULL, NULL);
	philos = NULL;
	info = NULL;
	initer(argc, argv, &info, &philos);
	print_philos(&philos);
	philo_thread(info, &philos);
	print_info(info);
}
