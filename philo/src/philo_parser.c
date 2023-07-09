/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:51:33 by mbartsch          #+#    #+#             */
/*   Updated: 2023/05/03 16:51:36 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static int	arg_parser(char *arg)
{
	int	z;
	int	num;

	z = 0;
	num = 0;
	while (arg[z])
	{
		if (!(arg[z] >= '0' && arg[z] <= '9'))
			return (-2);
		num = num * 10 + (arg[z] - 48);
		z++;
	}
	return (num);
}

static t_philo_data	*check_errors_philo(t_philo_data *philo)
{
	if (philo->num_philo == -2)
		return (NULL);
	else if (philo->die_time == -2)
		return (NULL);
	else if (philo->eat_time == -2)
		return (NULL);
	else if (philo->sleep_time == -2)
		return (NULL);
	else if (philo->num_eat == -2)
		return (NULL);
	return (philo);
}

t_philo_data	*parse_input(int argc, char *argv[], t_philo_data *philo)
{
	int	z;

	z = 1;
	while (z < argc)
	{
		if (z == 1)
			philo->num_philo = arg_parser(argv[z]);
		else if (z == 2)
			philo->die_time = arg_parser(argv[z]);
		else if (z == 3)
			philo->eat_time = arg_parser(argv[z]);
		else if (z == 4)
			philo->sleep_time = arg_parser(argv[z]);
		else
			philo->num_eat = arg_parser(argv[z]);
		z++;
	}
	return (check_errors_philo(philo));
}
