#include "../includes/philo.h"

static void	get_right_fork(t_info *info, size_t philo_number)
{
	size_t	fork_index;

	printf("\x1b[36m[%s philo_num %zu]\n\033[m", "get_right_fork in", philo_number);
	fork_index = philo_number - 1;
	pthread_mutex_lock(&(info->forks_mutex[fork_index]));
	print_action(info->philos[philo_number - 1], "has taken a fork");
	info->philos[philo_number - 1]->has_fork_right = true;
	pthread_mutex_unlock(&(info->forks_mutex[fork_index]));
}

static void	get_left_fork(t_info *info, size_t philo_number)
{
	size_t	fork_index;

	printf("\x1b[36m[%s philo_num %zu]\n\033[m", "get_left_fork in", philo_number);
	if (philo_number == info->number_of_philo)
		fork_index = 0;
	else
		fork_index = philo_number - 1;
	pthread_mutex_lock(&(info->forks_mutex[fork_index]));
	print_action(info->philos[philo_number - 1], "has taken a fork");
	info->philos[philo_number - 1]->has_fork_left = true;
	pthread_mutex_unlock(&(info->forks_mutex[fork_index]));
}

void	get_fork(t_info *info, size_t philo_number)
{
	printf("\x1b[36m[%s philo_num %zu]\n\033[m", "get_fork in", philo_number);
	pthread_mutex_lock(&(info->shared_mutex));
	printf("\x1b[36m[%s philo_num %zu]\n\033[m", "fork_lock", philo_number);
	if (info->philos[philo_number - 1]->has_fork_right == false)
		get_right_fork(info, philo_number);
	if (info->philos[philo_number - 1]->has_fork_left == false)
		get_left_fork(info, philo_number);
	pthread_mutex_unlock(&(info->shared_mutex));
	printf("\x1b[36m[%s philo_num %zu]\n\033[m", "fork_unlock", philo_number);
}