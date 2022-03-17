#include "../includes/philo.h"

void	sleep_philo(t_philo *philo)
{
	printf("\x1b[36m[%s philo_num %zu]\n\033[m", "sleep in", philo->philo_number);
	pthread_mutex_lock(&(philo->info->shared_mutex));
	print_action(philo, "is sleeping");
	pthread_mutex_unlock(&(philo->info->shared_mutex));
	time_keeper(philo->info, philo->info->time_to_sleep);
}

void	think_philo(t_philo *philo)
{
	printf("\x1b[36m[%s philo_num %zu]\n\033[m", "think in", philo->philo_number);
	pthread_mutex_lock(&(philo->info->shared_mutex));
	print_action(philo, "is thinking");
	pthread_mutex_unlock(&(philo->info->shared_mutex));
	usleep(300);
}

void	eat_philo(t_philo *philo)
{
	printf("\x1b[36m[%s philo_num %zu]\n\033[m", "eat in", philo->philo_number);
	if (philo->has_fork_right == true && philo->has_fork_left == true)
	{
		pthread_mutex_lock(&(philo->info->shared_mutex));
		print_action(philo, "is eating");
		philo->eat_count++;
		pthread_mutex_unlock(&(philo->info->shared_mutex));
		time_keeper(philo->info, philo->info->time_to_eat);
	}
}