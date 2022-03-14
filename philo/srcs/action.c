#include "../includes/philo.h"

void	sleep_philo(t_philo *philo)
{
	pthread_mutex_lock(&(philo->info->shared_mutex));
	print_action(philo, "is sleeping");
	pthread_mutex_unlock(&(philo->info->shared_mutex));
	time_keeper(philo->info, philo->info->time_to_sleep);
}

void	think_philo(t_philo *philo)
{
	pthread_mutex_lock(&(philo->info->shared_mutex));
	print_action(philo, "is thinking");
	pthread_mutex_unlock(&(philo->info->shared_mutex));
	usleep(300);
}

void	eat_philo(t_philo *philo)
{
	pthread_mutex_lock(&(philo->info->shared_mutex));
	print_action(philo, "is eating");
	philo->eat_count++;
	pthread_mutex_unlock(&(philo->info->shared_mutex));
	time_keeper(philo->info, philo->info->time_to_eat);
}