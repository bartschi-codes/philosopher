#include "philo.h"

static int	check_death(t_philosopher *philo)
{
	
}

void	philo_philosopher(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->fork_1);
	printf("%ld philsopher %d has taken fork_1", philo->start_time->tv_usec, philo->philosopher_nbr);
	pthread_mutex_lock(philo->fork_2);
	printf("%ld philsopher %d has taken fork_2", philo->start_time->tv_usec, philo->philosopher_nbr);
	usleep(philo->info->eat_time);
	printf("%ld philsopher %d has eaten", philo->start_time->tv_usec, philo->philosopher_nbr);
	philo->times_eaten++;
	pthread_mutex_unlock(&philo->fork_1);
	pthread_mutex_unlock(philo->fork_2);
	printf("%ld philsopher %d has put back forks", philo->start_time->tv_usec, philo->philosopher_nbr);
	if ((philo->times_eaten) == philo->info->num_eat)
		exit(1);	
	check_death(philo);
	usleep(philo->info->sleep_time);
	printf("%ld philsopher %d has sleept", philo->start_time->tv_usec, philo->philosopher_nbr);
	check_death(philo);
}
