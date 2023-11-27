#include "philo.h"

static void	philo_init(t_philo *philo, t_control *cntrl)
{
	int	z;

	z = 0;
	while (z < cntrl->number_philos)
	{
		philo[z].philo_nbr = z + 1;
		philo[z].cntrl = cntrl;
		philo[z].fork = z;
		philo[z].knife = (z + 1) % philo->cntrl->number_philos;
		philo[z].ate = 0;
		philo[z].last_meal = philo[0].cntrl->start_time;
		z++;
	}
}

int	god(t_control *cntrl)
{
	t_philo	*philo;
	int		z;

	z = 0;
	philo = cntrl->philos;
	cntrl->start_time = new_time();
	philo_init(philo, cntrl);
	while (z < cntrl->number_philos)
	{
		if (pthread_create(&philo[z].thread_number, NULL, \
			philosopher, &philo[z]))
			return (1);
		z++;
	}
	if (pthread_create(&cntrl->reaper, NULL, reaper, cntrl))
		return (1);
	return (0);
}
