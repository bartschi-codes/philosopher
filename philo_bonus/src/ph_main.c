#include "philo.h"

static void	live_life(t_control *cntrl)
{
	int	z;

	z = 0;
	while (z < cntrl->number_philos)
	{
		waitpid(-1, NULL, 0);
		z++;
	}
}

int	main(int argc, char *argv[])
{
	t_control	*cntrl;

	if (argc != 5 && argc != 6)
		return (\
		printf("wrong input\n./philo nbr_philo die_time eat_time sleep_time [nbr_eat]\n"), 1);
	if (init_cntrl(argv, &cntrl))
		return (printf("wrong input\n./philo nbr_philo die_time eat_time sleep_time [nbr_eat]\n"), 1);
	if (god(cntrl))
		return(printf("thread error\n"), 1);
	live_life(cntrl);
	return (0);
}
