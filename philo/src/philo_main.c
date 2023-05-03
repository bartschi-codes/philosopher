#include "philo.h"

void	print_philos(int num, t_philosopher philo[])
{
	int	z;

	z = 0;
	while (z < num)
	{
		printf("nbr: %d\n", philo[z].philosopher_nbr);
		z++;
	}
}

void	print_info(t_philo_data *info)
{
	printf("num: %d\ndie_time %d\neat_time: %d\nsleep time: %d\nnum_eat: %d\n", info->num_philo, info->die_time, info->eat_time, info->sleep_time, info->num_eat);
}

int	main(int argc, char *argv[])
{
	t_philosopher	*philos;
	t_philo_data	*info;

	if (argc < 5 || argc > 6)
		error_h("wrong input", NULL, NULL);
	info = NULL;
	philos = NULL;
	initer(argc, argv, &info, &philos);
	print_philos(info->num_philo, philos);
	philo_thread(&info, &philos);
	print_info(info);
}
