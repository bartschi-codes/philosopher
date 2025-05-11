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
	controler->all_alive = sem_open("all_alive", O_CREAT, 0644, 1);
	if (controler->all_alive == SEM_FAILED)
		return (1);
	controler->dead = sem_open("dead", O_CREAT, 0644, 1);
	if (controler->dead == SEM_FAILED)
		return (sem_close(controler->all_alive), 2);
	controler->pen = sem_open("pen", O_CREAT, 0644, 1);
	if (controler->pen == SEM_FAILED)
		return (sem_close(controler->all_alive), sem_close(controler->dead), 2);
	controler->cutlery = sem_open("cutlery", O_CREAT, 0644, \
		controler->number_philos);
	if (controler->cutlery == SEM_FAILED)
		return (sem_close(controler->all_alive), sem_close(controler->dead), \
			sem_close(controler->pen), 2);
	return (0);
}

static int	check_input(char *argv[])
{
	int	z;
	int	z2;

	z = 1;
	z2 = 0;
	while (argv[z])
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
			return (-1);
		arg++;
	}
	*dest = (int)z;
	return (z);
}

static int	init_args(char *argv[], t_control *controler)
{
	if (!check_input(argv))
		return (printf("only positiv ints\n"), 1);
	if (ph_atoi(argv[1], &controler->number_philos) > 200)
		return (printf("not more than 200 philosophers\n"), 2);
	if (ph_atoi(argv[2], &controler->die_time) < 60)
		return (printf("time_to_die cannot be lower than 60ms\n"), 3);
	if (ph_atoi(argv[3], &controler->eat_time) < 60)
		return (printf("time_to_eat cannot be lower than 60ms\n"), 4);
	if (ph_atoi(argv[4], &controler->sleep_time) < 60)
		return (printf("time_to_sleep cannot be lower than 60ms\n"), 5);
	if (ph_atoi(argv[5], &controler->number_eat) < 0)
		return (printf("amouont_to_eat wrong\n"), 6);
	if (open_semaphores(controler))
		return (printf("semaphore error\n"), 7);
	return (0);
}

int	init_controler(char *argv[], t_control **controler)
{
	*controler = (t_control *)malloc(sizeof(t_control));
	if (!controler)
		return (printf("malloc error\n"), 1);
	if (init_args(argv, *controler))
		return (2);
	sem_wait((*controler)->all_alive);
	if (init_philos(*controler))
		return (3);
	return (0);
}
