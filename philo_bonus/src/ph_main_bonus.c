/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_main_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <mbartsch@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:15:11 by mbartsch          #+#    #+#             */
/*   Updated: 2023/12/12 15:15:12 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char *argv[])
{
	t_control	*controler;

	if (argc < 5 || argc > 6)
		return (printf("Use: [Number_Philos] [Die_Time] [Eat_Time] " \
				"[Sleep_Time] {Amount_Eat}\n"), 1);
	if (init_controler(argv, &controler))
		return (2);
	if (start_processes(controler))
		return (3);
	if (main_process(controler))
		return (4);
	return (0);
}
