#include "../include/philo.h"

static void	check_eat_count(t_monitor *monitor)
{
	int	i;

	i = 0;
	while (i < monitor->data->number_of_philo && monitor->data->argc == 6)
	{
		if (monitor->data->philos[i].is_reached_min_eat == false)
			break ;
		i++;
		if (i == monitor->data->number_of_philo)
		{
			pthread_mutex_lock(&monitor->data->shared_mutex);
			monitor->data->is_finished = true;
			pthread_mutex_unlock(&monitor->data->shared_mutex);
		}
	}
}

static void	check_is_dead(t_monitor *monitor)
{
	int		philo_index;
	int		eat_count;
	size_t	last_eat_time;

	philo_index = -1;
	while (++philo_index < monitor->data->number_of_philo)
	{
		pthread_mutex_lock(&monitor->data->shared_mutex);
		last_eat_time = monitor->data->philos[philo_index].last_eat_time;
		pthread_mutex_unlock(&monitor->data->shared_mutex);
		if (get_time_zero_start(&monitor->data->philos[philo_index]) - \
				last_eat_time > monitor->data->time_to_die)
		{
			print_action(&monitor->data->philos[philo_index], "died");
			pthread_mutex_lock(&monitor->data->shared_mutex);
			monitor->data->is_finished = true;
			pthread_mutex_unlock(&monitor->data->shared_mutex);
		}
		pthread_mutex_lock(&monitor->data->shared_mutex);
		eat_count = monitor->data->philos[philo_index].eat_count;
		pthread_mutex_unlock(&monitor->data->shared_mutex);
		if (eat_count >= (int)monitor->data->number_of_min_eat)
			monitor->data->philos[philo_index].is_reached_min_eat = true;
	}
	check_eat_count(monitor);
}

static void	monitor_action(t_monitor *monitor)
{
	bool	is_finished;

	pthread_mutex_lock(&monitor->data->shared_mutex);
	is_finished = monitor->data->is_finished;
	pthread_mutex_unlock(&monitor->data->shared_mutex);
	while (is_finished != true)
	{
		check_is_dead(monitor);
		pthread_mutex_lock(&monitor->data->shared_mutex);
		is_finished = monitor->data->is_finished;
		pthread_mutex_unlock(&monitor->data->shared_mutex);
	}
}

void	*monitor_routine(void *ptr)
{
	t_monitor	*monitor;

	monitor = (t_monitor *)ptr;
	time_keeper(&monitor->data->philos[0], monitor->data->time_to_die);
	monitor_action(monitor);
	return (NULL);
}
