#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

void	*print_thread(void *z)
{
	long	z_int;

	z_int = (long) z;
	struct timeval tm;

	gettimeofday(&tm, NULL);
	printf("ich bin prozess %ld\n", z_int);
	printf("sec: %li, msec: %li\n", tm.tv_sec, tm.tv_usec);
	pthread_exit(NULL);
}

int	main(void)
{
	pthread_t	threads[10];
	int		z = 0;
	int		cntrl;
	
	while (z < 10)
	{
		cntrl = pthread_create(&threads[z], NULL, print_thread, (void *) z);
		if (cntrl)
		{
			printf("create thread error");
			exit(-1);
		}
		printf("thread %d created, threadid: %ld\n", z, threads[z]);
		pthread_join(threads[z], NULL);
		z++;
	}
}
