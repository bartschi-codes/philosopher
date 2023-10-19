#include "philo.h"

long long new_time(void)
{
	struct timeval	tv;
	long long	timestamp;

	gettimeofday(&tv, NULL);
	timestamp = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (timestamp);
}

void	timer(int time, t_philo *philo)
{
	long long	start;

	start = new_time();
	while(philo->cntrl->all_alive)
	{
		if (new_time() - start >= time)
			break ;
		usleep(30);
	}
}
