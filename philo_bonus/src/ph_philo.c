#include "philo.h"

static void	dinner_time(t_philo *philo)
{
	sem_wait(philo->cntrl->cutlery);
	use_pen(philo, "has taken a fork");
	sem_wait(philo->cntrl->cutlery);
	use_pen(philo, "has taken a fork");
	sem_wait(philo->satisfied);
	philo->last_meal = new_time();
	sem_post(philo->satisfied);
	use_pen(philo, "is eating");
	timer(philo->cntrl->eat_time, philo);
	sem_post(philo->cntrl->cutlery);
	sem_post(philo->cntrl->cutlery);
	philo->ate = philo->ate + 1;
}

void	*lonley_life(t_philo *philo)
{
	sem_wait(philo->cntrl->cutlery);
	use_pen(philo, "has taken a fork");
	sem_post(philo->cntrl->cutlery);
	timer(philo->cntrl->die_time, philo);
	sem_post(philo->cntrl->all_alive);
	return (NULL);
}

void	*philosopher(t_philo *philo)
{
	if (!(philo->philo_nbr % 2))
		timer(philo->cntrl->eat_time, philo);
	if (pthread_create(&philo->reaper, NULL, reaper, philo))
		return (NULL);
	if (philo->cntrl->number_philos == 1)
		return (lonley_life(philo));
	while (all_alive(philo->cntrl))
	{
		dinner_time(philo);
		if (philo->ate == philo->cntrl->number_eat)
			break;
		use_pen(philo, "is sleeping");
		timer(philo->cntrl->sleep_time, philo);
		use_pen(philo, "is thinking");
		timer(philo->cntrl->eat_time / 2, philo);
		usleep(10);
	}
	pthread_join(philo->reaper, NULL);
	sem_post(philo->cntrl->all_alive);
	return (NULL);
}
