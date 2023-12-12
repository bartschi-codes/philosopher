/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <mbartsch@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:17:02 by mbartsch          #+#    #+#             */
/*   Updated: 2023/12/12 15:17:04 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	use_pen(t_philo *philo, char *str)
{
	int	allowed;

	pthread_mutex_lock(&philo->cntrl->dead);
	allowed = philo->cntrl->all_alive;
	pthread_mutex_unlock(&philo->cntrl->dead);
	if (allowed)
	{
		pthread_mutex_lock(&philo->cntrl->pen);
		printf("%lld ", (new_time() - philo->cntrl->start_time));
		printf("%d ", philo->philo_nbr);
		printf("%s\n", str);
		pthread_mutex_unlock(&philo->cntrl->pen);
	}
}
