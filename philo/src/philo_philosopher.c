/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_philosopher.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:47:44 by mbartsch          #+#    #+#             */
/*   Updated: 2023/05/03 15:47:49 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

/*static int	check_death(t_philosopher *philo)
{
	return (1);
}*/

void	philo_philosopher(t_philosopher *philo)
{
	printf("ich bin philospoher %d\n", philo->philosopher_nbr);
	pthread_exit(NULL);
}
