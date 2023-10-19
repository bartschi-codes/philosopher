#include "philo.h"

void	use_pen(t_philo *philo, char *str)
{
	int	allowed;

	pthread_mutex_lock(&philo->cntrl->dead);
	allowed = philo->cntrl->all_alive;
	pthread_mutex_unlock(&philo->cntrl->dead);
	if (allowed)
	{
		pthread_mutex_lock(&philo->cntrl->pen);
		printf("%lld ", (new_time() - philo->cntrl->start_time));
		printf("%d ", philo->philo_nbr);
		printf("%s\n", str);
		pthread_mutex_unlock(&philo->cntrl->pen);
	}
}
