#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <semaphore.h>

# ifndef PHILO_AMOUNT
#  define PHILO_AMOUNT 200
# endif

typedef struct s_philo{
	int			philo_nbr;
	long long		last_meal;
	int			ate_nbr;
	pid_t			pid;
	pthread_t		reaper;
	struct	s_control	*cntrl;
}	t_philo;

typedef struct	s_control{
	int		number_philos;
	int		die_time;
	int		eat_time;
	int		sleep_time;
	int		number_eat;
	long long	start_time;
	sem_t		*all_alive;
	sem_t		*dead;
	sem_t		*pen;
	sem_t		*cutlery;
	t_philo		philos[PHILO_AMOUNT];
}	t_control;

int		init_cntrl(char *argv[], t_control **cntrl);
int		god(t_control *cntrl);
int		all_alive(t_control *cntrl);
char		*ft_strjoin(char const *str1, char const *str2);
long long	new_time(void);
void		timer(int time, t_philo *philo);
void		use_pen(t_philo *philo, char *str);
void		*philosopher(t_philo *tmp);
void		*reaper(void *tmp);
void		*devil(void *tmp);
#endif
