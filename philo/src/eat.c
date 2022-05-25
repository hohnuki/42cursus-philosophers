#include "../include/philo.h"

int	philo_eat(t_philo *philo)
{
	if (philo->has_fork_right == true && philo->has_fork_left == true)
	{
		philo->last_eat_time = get_time_zero_start(philo);
		if (time_keeper(philo, philo->data->time_to_eat) == 1 \
			|| print_action(philo, "is eating") == 1)
				return (1);
		put_down_fork(philo);
		philo->has_fork_left = 0;
		philo->has_fork_right = 0;
		philo->eat_count++;
	}
	return (0);
}
