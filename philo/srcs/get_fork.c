#include "../includes/philo.h"

static void	get_right_fork(t_philo *philo)
{
	size_t	fork_index;

	fork_index = philo->philo_number;
	pthread_mutex_lock(philo->info->forks_mutex[fork_index]);
	philo->has_fork_right = true;
//	pthread_mutex_unlock(philo->info->forks_mutex[fork_index]);
}

static void	get_left_fork(t_philo *philo)
{
	size_t	fork_index;

	if (philo->philo_number == philo->info->number_of_philo)
		fork_index = 0;
	else
		fork_index = philo->philo_number - 1;
	pthread_mutex_lock(philo->info->forks_mutex[fork_index]);
	philo->has_fork_left = true;
//	pthread_mutex_unlock(philo->info->forks_mutex[fork_index]);
}

void	get_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo->info->shared_mutex));
	print_action(philo, "has taken a fork");
	pthread_mutex_unlock(&(philo->info->shared_mutex));
	if (philo->has_fork_right == false)
		get_right_fork(philo);
	if (philo->has_fork_left == false)
		get_left_fork(philo);
}