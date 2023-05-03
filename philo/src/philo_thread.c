#include "philo.h"

int	philo_thread(t_philo_data **info, t_philosopher *philos[])
{
	int		i;
	pthread_t	*threads;

	i = 0;
	threads = (pthread_t *)malloc(sizeof(pthread_t) * (*info)->num_philo);
	if (!threads)
		return (0);
	while (i < (*info)->num_philo)
	{
		if (pthread_create(&threads[i], NULL, (void *)philo_philosopher, (void *)philos[i]) == -1)
			return (-1);
		i++;
	}
	i = 0;
	while (i < (*info)->num_philo)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	return (1);
}
