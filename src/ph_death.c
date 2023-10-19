#include "philo.h"

int	all_alive(t_control *cntrl)
{
	int	ret;

	pthread_mutex_lock(&cntrl->dead);
	ret = cntrl->all_alive;
	pthread_mutex_unlock(&cntrl->dead);
	return (ret);
}

int	kill_philo(t_philo philo, long long time)
{
	long long	last_time;

	pthread_mutex_lock(&philo.cntrl->satisfied);
	last_time = philo.last_meal;
	pthread_mutex_unlock(&philo.cntrl->satisfied);
	if (time - last_time > philo.cntrl->die_time)
		return (1);
	return (0);
}

void	*reaper(void *tmp)
{
	int		z;
	int		ate;
	long long	time;
	t_control	*cntrl;

	cntrl = (t_control *)tmp;
	usleep(cntrl->die_time / 2);
	while (cntrl)
	{
		time = new_time();
		z = 0;
		while (z < cntrl->number_philos)
		{
			if (kill_philo(cntrl->philos[z], time))
			{
				use_pen(&cntrl->philos[z], "died");
				pthread_mutex_lock(&cntrl->dead);
				cntrl->all_alive = 0;
				pthread_mutex_unlock(&cntrl->dead);
				return (NULL);
			}
			z++;
		}
		z = -1;
		while (++z < cntrl->number_philos)
			if (cntrl->philos[z].ate == cntrl->number_eat)
				ate++;
		if (ate == cntrl->number_philos)
			return (NULL);
	}
	return (NULL);
}
