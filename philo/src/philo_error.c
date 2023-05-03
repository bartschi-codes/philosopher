#include "philo.h"

static void	free_philos(int num, t_philosopher philos [])
{
	int	z;
	
	z = 0;
	while (z < num)
		free(&philos[z]);
	free(philos);
}

void	error_h(char *err_msg, t_philo_data *info, t_philosopher philos[])
{
	if (philos)
		free_philos(info->num_philo, philos);
	if (info)
		free(info);
	printf("%s\n", err_msg);
}
