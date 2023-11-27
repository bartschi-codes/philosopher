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

static void	*end_them(t_control *cntrl)
{
	pthread_mutex_lock(&cntrl->dead);
	cntrl->all_alive = 0;
	pthread_mutex_unlock(&cntrl->dead);
	return (NULL);
}

static int	all_ate(t_control *cntrl)
{
	int	z;
	int	ate;

	z = 0;
	ate = z;
	while (cntrl->number_eat != -1 && z < cntrl->number_philos)
	{
		if (cntrl->philos[z].ate >= cntrl->number_eat)
			ate++;
		z++;
	}
	if (ate == cntrl->number_philos)
		return (1);
	return (0);
}

void	*reaper(void *tmp)
{
	int			z;
	long long	time;
	t_control	*cntrl;

	cntrl = (t_control *)tmp;
	usleep(cntrl->die_time / 2);
	while (cntrl->all_alive)
	{
		time = new_time();
		z = 0;
		while (z < cntrl->number_philos)
		{
			if (kill_philo(cntrl->philos[z], time))
			{
				use_pen(&cntrl->philos[z], "died");
				return (end_them(cntrl));
			}
			z++;
		}
		if (all_ate(cntrl))
			return (end_them(cntrl));
	}
	return (NULL);
}
