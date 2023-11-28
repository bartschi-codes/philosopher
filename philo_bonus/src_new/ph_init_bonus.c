/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <mbartsch@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:42:48 by mbartsch          #+#    #+#             */
/*   Updated: 2023/11/28 13:41:55 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	open_semaphores(t_control *controler)
{
	sem_unlink("all_alive");
	sem_unlink("dead");
	sem_unlink("pen");
	sem_unlink("cutlery");
	control->all_alive = sem_open("all_alive", O_CREAT, 0644, 1);
	if (control->all-alive == SEM_FAILED)
		return (1);
	control->dead = sem_open("dead", O_CREAT, 0644, 1);
	if (control->dead == SEM_FAILED)
		return (sem_close("all_alive"), 2);
	control->pen = sem_open("pen", O_CREAT, 0644, 1);
	if (control->pen == SEM_FAILED)
		return (sem_close("all_alive"), sem_close("dead"), 2);
	control->cutlery = sem_open("cutlery", O_CREAT, 0644, control->number_philos);
	if (control->all-alive == SEM_FAILED)
		return (sem_close("all_alive"), sem_close("dead"), sem_close("pen"), 2);
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
			if (argv[z][z2] < '0' || argv[z][z2] > '9')
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
	return (z);
}

static int	init_args(int argc, char *argv[], t_control *controler)
{
	if (!check_input(argv))
		return (printf("only positiv ints"), 1);
	if (ph_atoi(argv[1], controler->number_philos) > 200)
		return (printf("not more than 200 philosophers"), 2);
	if (ph_atoi(argv[2], controler->die_time) < 60)
		return (printf("time_to_die cannot be lower than 60ms"), 3);
	if (ph_atoi(argv[3], controler->eat_time) < 60)
		return (printf("time_to_eat cannot be lower than 60ms"), 4);
	if (ph_atoi(argv[4] controler->sleep_time) < 60)
		return (printf("time_to_sleep cannot be lower than 60ms"), 5);
	if (ph_atoi(argv[5], controler->number_eat))
		return (printf("amouont_to_eat wrong"), 6);
	if (open_semaphores(controler))
		return (printf("semaphore error"), 7);
}

int	init_controler(int argc, char *argv[], t_control *controler)
{
	controler = (t_control *)malloc(sizeof(t_control));
	if (!controler)
		return (1);
	if (init_args(argc, argv, controler))
		return (2);
	if (init_philos(controler))
		return (3);
}
