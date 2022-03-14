#include "../includes/philo.h"

static void	init_philos(t_info *info)
{
	size_t	i;

	info->philos = xmalloc(info, sizeof(t_philo) * info->number_of_philo);
	i = 0;
	while (i < info->number_of_philo)
	{
		info->philos[i].has_fork_right = false;
		info->philos[i].has_fork_left = false;
		info->philos[i].eat_count = 0;
		info->philos[i].philo_number = i + 1;

		pthread_create(info->philos[i].thread_philo, NULL, philo_func, info);
		i++;
	}
}

static void	init_monitors(t_info *info)
{
	size_t	i;

	info->monitors = xmalloc(info, sizeof(t_monitor) * info->number_of_philo);
	i = 0;
	while (i < info->number_of_philo)
	{
		info->monitors[i].monitor_number = i + 1;

		pthread_create(info->monitors[i].monitor_number, NULL, monitor_func, info);
		i++;
	}
}

void	init_structure(t_info *info, int argc, char **argv)
{
	info->argc = argc;
	info->argv = argv;

	info->number_of_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info->number_of_min_eat = ft_atoi(argv[5]);
	pthread_mutex_init(info->shared_mutex, NULL);

	init_philos(info);
	init_monitors(info);
}