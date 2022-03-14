#include "../includes/philo.h"

void	*philo_func(void *ptr)
{
	t_info	*info;

	info = (t_info *)ptr;
	printf("\x1b[36m[%zu]\n\033[m", get_time(info));
	return (NULL);
}