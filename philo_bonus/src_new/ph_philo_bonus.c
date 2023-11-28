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
	control->start_time = new_time();
	while (z < control->number_philos)
	{
		control->philos[z].philo_nbr = z + 1;
		control->philos[z].last_meal = control->start_time;
		control->philos[z].ate_nbr = 0;
		control->philos[z].cntrl = controler;
		z++;
	}
	return (0);
}
