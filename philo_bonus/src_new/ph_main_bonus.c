#include "philo_bonus.h"

int	main(int argc, char *argv[])
{
	t_control	*controler;

	if (argc < 5 || argc >  6)
		return( 1 );
	if (init_args(argc, argv, controler))
		return ( 2 );

}
