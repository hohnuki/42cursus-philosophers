#include "../include/philo.h"

void	destroy_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philo)
	{
		pthread_mutex_destroy(&data->forks_mutex[i]);
		i++;
	}
	pthread_mutex_destroy(&data->shared_mutex);
}

int	main(int argc, char **argv)
{
	t_data	data;

	memset(&data, 0, sizeof(t_data));
	if ((argc != 5 && argc != 6) || \
		ft_isnum(argc - 1, argv) == false || digit_check(argc, argv) == false)
	{
		printf("Invalid input!\n");
		return (0);
	}
	if (init_data(&data, argc, argv) == false)
		return (0);
	create_thread(&data);
	join_thread(&data);
	destroy_mutex(&data);
}
