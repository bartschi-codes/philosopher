#include "philo.h"

static int	philo_init(t_philo *philo, t_control *cntrl)
{
	int	z;

	z = 0;
	while (z < cntrl->number_philos)
	{
		philo[z].philo_nbr = z + 1;
		philo[z].cntrl = cntrl;
		philo[z].ate = 0;
		philo[z].last_meal = cntrl->start_time;
		z++;
	}
	return (0);
		
}

int	god(t_control *cntrl)
{
	t_philo	*philo;
	int	z;

	z = 0;
	philo = cntrl->philos;
	cntrl->start_time = new_time();
	if (philo_init(philo, cntrl))
		return (1);
	while (z < cntrl->number_philos)
	{
		philo[z].pid = fork();
		if (philo[z].pid == -1)
			return (1);
		else if (philo[z].pid == 0)
			philosopher(&philo[z]);
		z++;
	}
	if (pthread_create(&cntrl->devil, NULL, devil, cntrl))
		return (1);
	return (0);
}

