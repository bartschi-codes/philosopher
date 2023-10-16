#include "philo.h"

void	print_philo(t_control *cntrl)
{
	printf("nbr: %d\n", cntrl->number_philos);
	printf("die: %d\n", cntrl->die_time);
	printf("eat: %d\n", cntrl->eat_time);
	printf("sleep: %d\n", cntrl->sleep_time);
	printf("nbr eat: %d\n", cntrl->number_eat);
}

int	main(int argc, char *argv[])
{
	t_control	*cntrl;

	if (argc != 5 && argc != 6)
		return (printf("wrong input\n"), 1);
	if (init_cntrl(argv, &cntrl))
		return (printf("wrong input\n"), 1);
	print_philo(cntrl);
	god(cntrl);
}
