#include "../includes/philo.h"

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
}