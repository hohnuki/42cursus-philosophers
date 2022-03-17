#include "../includes/philo.h"

void	create_thread(t_info *info)
{
	size_t	i;

	i = 0;
	while (i < info->number_of_philo)
	{
		printf("\x1b[36m[aaaaaaaa]\n\033[m");
		pthread_create(&(info->philos[i]->thread_philo), NULL, philo_func, info->philos[i]);
		pthread_create(&(info->monitors[i]->thread_monitor), NULL, monitor_func, info->monitors[i]);
		i++;
	}
}