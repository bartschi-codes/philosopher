#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>

typedef struct	s_control{
	int		number_philos;
	int		die_time;
	int		eat_time;
	int		sleep_time;
	int		number_eat;
	pthread_mutex	satisfied;
	pthread_mutex	alive;
	pthread_mutex	pen;
	t_philo		*philo;
}	t_control;

typedef struct s_philo{
	int			philo_nbr;
	struct	t_control	*cntrl;
}	t_philo;

int	init_cntrl(char *argv[], t_control **cntrl);

#endif
