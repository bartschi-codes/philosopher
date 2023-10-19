#include "philo.h"

static void	dinner_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->cntrl->cutlery[philo->fork]);
	use_pen(philo, "has taken a fork");
	pthread_mutex_lock(&philo->cntrl->cutlery[philo->knife]);
	use_pen(philo, "has taken a fork");
	pthread_mutex_lock(&philo->cntrl->satisfied);
	philo->last_meal = new_time();
	pthread_mutex_unlock(&philo->cntrl->satisfied);
	use_pen(philo, "is eating");
	timer(philo->cntrl->eat_time, philo);
	pthread_mutex_unlock(&philo->cntrl->cutlery[philo->fork]);
	pthread_mutex_unlock(&philo->cntrl->cutlery[philo->knife]);
	philo->ate = philo->ate + 1;
}

void	lonley_life(t_philo *philo)
{
	pthread_mutex_lock(&philo->cntrl->cutlery[philo->fork]);
	use_pen(philo, "has taken a fork");
	pthread_mutex_unlock(&philo->cntrl->cutlery[philo->fork]);
	timer(philo->cntrl->die_time, philo);
}

void	*philosopher(void *tmp)
{
	t_philo	*philo;

	philo = (t_philo *) tmp;
	if (!(philo->philo_nbr % 2))
		timer(philo->cntrl->eat_time, philo);
	if (philo->cntrl->number_philos == 1)
	{
		lonley_life(philo);
		return(NULL);
	}
	while (all_alive(philo->cntrl))
	{
		dinner_time(philo);
		if (philo->ate == philo->cntrl->number_eat)
			break;
		use_pen(philo, "is sleeping");
		timer(philo->cntrl->sleep_time, philo);
		use_pen(philo, "is thinking");
	}
	return (NULL);
}
