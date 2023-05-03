#include "philo.h"

static int	philo_data_init(t_philo_data **info)
{
	(*info) = (t_philo_data *)malloc(sizeof(t_philo_data));
	if (!(*info))
		return (0);
	(*info)->num_philo = -1;
	(*info)->eat_time = -1;
	(*info)->die_time = -1;
	(*info)->sleep_time = -1;
	(*info)->num_eat = -1;
	return (1);
}

static int	philo_philosopher_init(t_philo_data *info, t_philosopher philos[])
{

	struct timeval	start;
	int		z;

	z = 0;
	if (gettimeofday(&start, NULL))
		return (0);
	while (z < info->num_philo)
	{
		philos[z].start_time = &start;
		philos[z].info = info;
		philos[z].times_eaten = 0;
		if (pthread_mutex_init(&philos[z].fork_1, NULL) == -1)
			return (-1);
		if (z == info->num_philo - 1)
			philos[z].fork_2 = &philos[0].fork_1;
		else
			philos[z].fork_2 = &philos[z + 1].fork_1;
		z++;
	}
	return (1);
}

static int	philo_philosophers_create(t_philo_data *info, t_philosopher *philos[])
{
	int	z;
	t_philosopher *philo;

	z = 1;
	(*philos) = (t_philosopher *)malloc(sizeof(t_philosopher) * info->num_philo);
	if (!philos)
		return (0);
	while (z <= info->num_philo)
	{
		philo = (t_philosopher *)malloc(sizeof(t_philosopher));
		if (!philo)
			return (0);
		philo->philosopher_nbr = z;
		(*philos)[z - 1] = *philo;
		z++;
	}
	return (1);
}

void	initer(int argc, char *argv[], t_philo_data **info, t_philosopher *philos[])
{
	if (!philo_data_init(info))
		error_h("malloc error", *info, *philos);
	if (!parse_input(argc, argv, info))
		error_h("wrong input", *info, *philos);
	if (!philo_philosophers_create(*info, philos))
		error_h("malloc errror", *info, *philos);
	if (!philo_philosopher_init(*info, *philos))
		error_h("mutex_init error", *info, *philos);
}
