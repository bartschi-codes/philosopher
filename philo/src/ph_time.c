/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <mbartsch@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:16:59 by mbartsch          #+#    #+#             */
/*   Updated: 2023/12/12 15:17:01 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	new_time(void)
{
	struct timeval	tv;
	long long		timestamp;

	gettimeofday(&tv, NULL);
	timestamp = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (timestamp);
}

void	timer(int time, t_philo *philo)
{
	long long	start;

	start = new_time();
	while (all_alive(philo->cntrl))
	{
		if (new_time() - start >= time)
			break ;
		usleep(30);
	}
}
