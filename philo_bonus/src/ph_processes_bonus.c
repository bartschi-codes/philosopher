#include "philo_bonus.h"

static void	free_control(t_control *controler)
{
	sem_close(controler->all_alive);
	sem_close(controler->dead);
	sem_close(controler->pen);
	sem_close(controler->cutlery);
	free(controler);
}

int	philo_process(t_philo *philo)
{
	int	return_value;

	if (!(philo->philo_nbr % 2))
		usleep(philo->control->eat_time);
	if (pthread_create(&philo->devil, NULL, devil, philo))
		exit(1);
	if (philo->control->number_philos == 1)
		return_value = lonely_life(philo);
	else
		return_value = philo_life(philo);
	free_control(philo->control);
	exit (return_value);
}

int	main_process(t_control *controler)
{
	int	z;
	int	wstatus;
	int	return_value;

	z = 0;
	wstatus = 0;
	return_value = 0;
	if (pthread_create(&(controler->reaper), NULL, reaper, controler))
		return (1);
	while (z < controler->number_philos)
	{
		waitpid(controler->philo_pids[z], &wstatus, 0);
		if (WIFEXITED(wstatus))
			return_value = WEXITSTATUS(wstatus);
		z++;
	}
	sem_post(controler->all_alive);
	pthread_join(controler->reaper, NULL);
	free_control(controler);
	return (return_value);
}

int	start_processes(t_control *controler)
{
	int	z;

	z = 0;
	while (z < controler->number_philos)
	{
		controler->philo_pids[z] = fork();
		if (controler->philo_pids[z] < 0)
			return (printf("fork error"), 1);
		else if (controler->philo_pids[z] == 0)
			return (philo_process(&controler->philos[z]));
		z++;
	}
	return (0);
}
