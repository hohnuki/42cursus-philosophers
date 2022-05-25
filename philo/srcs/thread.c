#include "../include/philo.h"

void	create_thread(t_data *data)
{
	int	i;

	i = 0;
	pthread_create(&data->monitor.thread_monitor, NULL, &monitor_routine, &data->monitor);
	while (i < data->number_of_philo)
	{
		pthread_create(&(data->philos[i].thread_philo), NULL, &philo_routine, &data->philos[i]);
		i++;
	}
}

void	join_thread(t_data *data)
{
	int	i;

	i = 0;
	pthread_join(data->monitor.thread_monitor, NULL);
	while (i < data->number_of_philo)
	{
		pthread_join(data->philos[i].thread_philo, NULL);
		i++;
	}
}
