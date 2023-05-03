/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:49:26 by mbartsch          #+#    #+#             */
/*   Updated: 2023/05/03 16:56:58 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>

typedef struct s_philo_data{
	int	num_philo;
	int	die_time;
	int	eat_time;
	int	sleep_time;
	int	num_eat;
}	t_philo_data;

typedef struct s_philosopher{
	int					philosopher_nbr;
	int					times_eaten;
	pthread_mutex_t		fork_1;
	pthread_mutex_t		*fork_2;
	struct s_philo_data	*info;
	struct timeval		*start_time;
}	t_philosopher;

void	initer(int argc, char *argv[], t_philo_data *info, \
				t_philosopher *philos[]);
int		parse_input(int agrc, char *argv[], t_philo_data *info);
void	error_h(char *err_msg, t_philo_data *info, t_philosopher philos[]);
int		philo_thread(t_philo_data *info, t_philosopher *philos[]);
void	philo_philosopher(t_philosopher *philo);

#endif
