#include "philo.h"

int	all_alive(t_control *cntrl)
{
	int	ret;

	sem_wait(cntrl->dead);
	ret = cntrl->all_live;
	sem_post(cntrl->dead);
	return (ret);
}

int	kill_philo(t_philo philo, long long time)
{
	long long	last_time;

	sem_wait(philo.satisfied);
	last_time = philo.last_meal;
	sem_post(philo.satisfied);
	if (time - last_time > philo.cntrl->die_time)
		return (1);
	return (0);
}

void	*devil(void *tmp)
{
	t_control	*cntrl;
	int		z;

	z = 0;
	cntrl =(t_control *) tmp;
	sem_wait(cntrl->all_alive);
	while (z < cntrl->number_philos)
	{
		kill(cntrl->philos[z].pid, SIGTERM);
		z++;
	}
	return (NULL);
}

void	*reaper(void *tmp)
{
	int		z;
	long long	time;
	t_philo		*philo;

	philo = (t_philo *)tmp;
	while (42)
	{
		time = new_time();
		if (kill_philo(*philo, time))
		{
			use_pen(philo, "died");
			sem_post(philo->cntrl->all_alive);
			break ;
		}
		z++;
	}
	return (NULL);
}
