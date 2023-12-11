#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

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

typedef struct s_philo
{
	int					philo_nbr;
	int					ate_nbr;
	long long			last_meal;
	pid_t				pid;
	pthread_t			devil;
	struct s_control	*control;
}	t_philo;

typedef struct s_control
{
	int				number_philos;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				number_eat;
	long long		start_time;
	pid_t			philo_pids[PHILO_AMOUNT];
	sem_t			*all_alive;
	sem_t			*dead;
	sem_t			*pen;
	sem_t			*cutlery;
	t_philo			philos[PHILO_AMOUNT];
	pthread_t		reaper;
}	t_control;

int			init_controler(char *argv[], t_control **cntrl);
long long	new_time(void);
int			init_philos(t_control *controler);
int			start_processes(t_control *controler);
int			main_process(t_control *controler);
void		*reaper(void *arg);
void		*devil(void *arg);
int			lonely_life(t_philo *philo);
int			philo_life(t_philo *philo);
void		use_pen(t_philo *philo, char *str);
#endif
