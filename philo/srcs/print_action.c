#include "../include/philo.h"

int	print_action(t_philo *philo, char *message)
{
	bool	is_finished;

	pthread_mutex_lock(&philo->data->shared_mutex);
	is_finished = philo->data->is_finished;
	pthread_mutex_unlock(&philo->data->shared_mutex);
	pthread_mutex_lock(&philo->data->shared_mutex);
	if (is_finished == 1)
	{
		pthread_mutex_unlock(&philo->data->shared_mutex);
		return (1);
	}
	printf("%8zu %d %s\n", get_time_zero_start(philo), philo->philo_number, message);
	pthread_mutex_unlock(&philo->data->shared_mutex);
	return (0);
}
