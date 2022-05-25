#include "../include/philo.h"

int	philo_sleep(t_philo *philo)
{
	if (print_action(philo, "is sleeping") == 1 \
		|| time_keeper(philo, philo->data->time_to_sleep) == 1)
		return (1);
	return (0);
}

int	philo_think(t_philo *philo)
{
	if (print_action(philo, "is thinking") == 1)
		return (1);
	return (0);
}

void	*philo_routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	philo->start_time = get_time_zero_start(philo);
	if ((philo->philo_number % 2) == 0)
		usleep(200);
	while (philo->data->is_finished != 1)
	{
		if (pickup_fork(philo) == 1 || philo_eat(philo) == 1 \
			|| philo_sleep(philo) == 1 || philo_think(philo))
			break ;
	}
	put_down_fork(philo);
	return (NULL);
}
