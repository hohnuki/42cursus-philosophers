#include "../include/philo.h"

void	create_thread(t_data *data)
{
	int	i;

	i = 0;
	data->start_time = get_time_zero_start(&data->philos[0]);
	while (i < data->number_of_philo)
	{
		pthread_create(&(data->philos[i].thread_philo), \
		NULL, &philo_routine, &data->philos[i]);
		i++;
	}
	pthread_create(&data->monitor.thread_monitor, \
	NULL, &monitor_routine, &data->monitor);
}

void	join_thread(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philo)
	{
		pthread_join(data->philos[i].thread_philo, NULL);
		i++;
	}
	pthread_join(data->monitor.thread_monitor, NULL);
}
