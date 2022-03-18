#include "../includes/philo.h"

void	join_thread(t_info *info)
{
	size_t	i;

	i = 0;
	while (i < info->number_of_philo)
	{
		pthread_join(info->philos[i]->thread_philo, NULL);
		pthread_join(info->monitors[i]->thread_monitor, NULL);
		i++;
	}
}
