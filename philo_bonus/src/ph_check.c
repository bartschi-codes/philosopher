#include "philo.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (c);
	return (0);
}

static int	check_input(char *argv[])
{
	int	z;
	int	z2;

	z = 1;
	z2 = 0;
	while(argv[z])
	{
		while (argv[z][z2])
		{
			if (ft_isdigit(argv[z][z2]) == 0)
				return (0);
			z2++;
		}
		z2 = 0;	
		z++;
	}
	return (1);
}

static int	ph_atoi(char *arg, int *dest)
{
	long	z;


	if (!arg)
	{
		*dest = -1;
		return (0);
	}
	z = 0;
	while (*arg)
	{
		z = z * 10 + (*arg - '0');
		if (z > 2147483647 || z < -2147483648)
			return (1);
		arg++;
	}
	*dest = (int)z;
	return (0);
}

static int	semas_init(t_control *cntrl)
{
	sem_unlink("/all_alive");
	cntrl->all_alive = sem_open("/all_alive", O_CREAT, 0664, 1);
	if (cntrl->all_alive == SEM_FAILED)
		return (1);
	sem_unlink("/all_alive");
	sem_unlink("/dead");
	cntrl->dead = sem_open("/dead", O_CREAT, 0664, 1);
	if (cntrl->dead == SEM_FAILED)
		return (1);
	sem_unlink("/dead");
	sem_unlink("/pen");
	cntrl->pen = sem_open("/pen", O_CREAT, 0664, 1);
	if (cntrl->pen == SEM_FAILED)
		return (1);
	sem_unlink("/pen");
	sem_unlink("/cutlery");
	cntrl->cutlery = sem_open("/cutlery", O_CREAT, 0664, cntrl->number_philos);
	if (cntrl->cutlery == SEM_FAILED)
		return (1);
	sem_unlink("/cutlery");
	sem_wait(cntrl->all_alive);
	return (0);

}

int	init_cntrl(char *argv[], t_control **cntrl)
{
	if (!check_input(argv))
		return (1);
	*cntrl = (t_control *)malloc(sizeof(t_control));
	if (!*cntrl)
		return (1);
	if (ph_atoi(argv[1], &(*cntrl)->number_philos))
		return (free(*cntrl), 1);
	if (ph_atoi(argv[2], &(*cntrl)->die_time))
		return (free(*cntrl), 1);
	if (ph_atoi(argv[3], &(*cntrl)->eat_time))
		return (free(*cntrl), 1);
	if (ph_atoi(argv[4], &(*cntrl)->sleep_time))
		return (free(*cntrl), 1);
	if (ph_atoi(argv[5], &(*cntrl)->number_eat))
		return (free(*cntrl), 1);
	if (semas_init(*cntrl))
		return(1);
	(*cntrl)->all_live = 1;
	return (0);
}
