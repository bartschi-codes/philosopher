/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_time_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <mbartsch@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:15:27 by mbartsch          #+#    #+#             */
/*   Updated: 2023/12/12 15:15:33 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long long	new_time(void)
{
	struct timeval	tv;
	long long		timestamp;

	gettimeofday(&tv, NULL);
	timestamp = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (timestamp);
}
