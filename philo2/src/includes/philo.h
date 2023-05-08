/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:26:28 by mbartsch          #+#    #+#             */
/*   Updated: 2023/05/08 17:39:49 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILO_H
# define PHILO_H

typedef struct s_info{
	int	philo_amount;
	int	eat_time;
	int	die_time;
	int	sleep_time;
	int	eat_amount;
}	t_info;

typedef struct s_print{
	pthread_mutex	log;
	pthread_mutex	die;
}	t_print;

typedef struct s_philosopher{
	int				philo_nbr;
	int				times_eaten;
	pthread_mutex	fork_1;
	pthread_mutex	fork_2;
	struct s_info	*info;
	struct s_print	*print;
}	t_philo;

#endif
