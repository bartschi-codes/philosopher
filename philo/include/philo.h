/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <mbartsch@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:15:57 by mbartsch          #+#    #+#             */
/*   Updated: 2023/12/12 15:15:59 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

# ifndef PHILO_AMOUNT
#  define PHILO_AMOUNT 400
# endif

typedef struct s_philo{
	int					philo_nbr;
	long long			last_meal;
	int					fork;
	int					knife;
	int					ate;
	pthread_t			thread_number;
	struct s_control	*cntrl;
}	t_philo;

typedef struct s_control{
	int				number_philos;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				number_eat;
	int				all_alive;
	long long		start_time;
	pthread_mutex_t	satisfied;
	pthread_mutex_t	dead;
	pthread_mutex_t	pen;
	pthread_mutex_t	cutlery[PHILO_AMOUNT];
	t_philo			philos[PHILO_AMOUNT];
	pthread_t		reaper;
}	t_control;

int			init_cntrl(char *argv[], t_control **cntrl);
int			god(t_control *cntrl);
int			all_alive(t_control *cntrl);
long long	new_time(void);
void		timer(int time, t_philo *philo);
void		use_pen(t_philo *philo, char *str);
void		*philosopher(void *tmp);
void		*reaper(void *tmp);
#endif
