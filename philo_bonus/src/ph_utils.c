#include "philo.h"

static size_t	len_of_str(char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		s++;
		len++;
	}
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*concat;
	size_t	len;
	size_t	z;

	z = 0;
	len = 0;
	len = len + len_of_str((char *)s1);
	len = len + len_of_str((char *)s2);
	concat = (char *)malloc((len + 1) * sizeof(char));
	if (concat == NULL)
		return (NULL);
	while (*s1)
	{
		concat[z] = *s1;
		s1++;
		z++;
	}
	while (*s2)
	{
		concat[z] = *s2;
		s2++;
		z++;
	}
	concat[z] = '\0';
	return (concat);
}

void	use_pen(t_philo *philo, char *str)
{
	sem_wait(philo->cntrl->pen);
	printf("%lld ", (new_time() - philo->cntrl->start_time));
	printf("%d ", philo->philo_nbr);
	printf("%s\n", str);
	sem_post(philo->cntrl->pen);
}
