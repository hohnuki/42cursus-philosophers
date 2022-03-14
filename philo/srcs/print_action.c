#include "../includes/philo.h"

void	print_action(t_philo *philo, char *message)
{
//	pthread_mutex_lock(&(philo->info->shared_mutex));
	printf("%zu %zu %s\n", get_time(philo->info), philo->philo_number, message);
//	pthread_mutex_unlock(&(philo->info->shared_mutex));
}