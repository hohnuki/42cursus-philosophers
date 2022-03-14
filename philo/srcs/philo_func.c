#include "../includes/philo.h"

void	time_keeper(t_info *info, size_t time)
{
	size_t	start_time;
	size_t	passed_time;

	start_time = get_time(info);
	while (1)
	{
		passed_time = get_time(info);
		if (passed_time - start_time >= time)
			return ;
	}
}

void	*philo_func(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	pthread_mutex_lock(&(philo->info->shared_mutex));
	philo->last_eat_time = get_time(philo->info);
	pthread_mutex_unlock(&(philo->info->shared_mutex));
	if (philo->philo_number % 2 == 1)
		usleep(200);
	while (1)
	{
		get_fork(philo);
		eat_philo(philo);
		think_philo(philo);
		release_fork(philo);
	}
	return (NULL);
}