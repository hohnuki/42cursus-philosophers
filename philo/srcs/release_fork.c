#include "../includes/philo.h"

void	release_fork(t_philo *philo)
{
	size_t	fork_index;

	fork_index = philo->philo_number;
	printf("\x1b[36m[%s philo_num %zu]\n\033[m", "release_fork in", philo->philo_number);
	if (philo->has_fork_left == true && philo->has_fork_right == true)
	{
		pthread_mutex_unlock(philo->info->forks_mutex[fork_index]);
		philo->has_fork_left = false;
		philo->has_fork_right = false;
		sleep_philo(philo);
	}
}