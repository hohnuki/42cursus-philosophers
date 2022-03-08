#include "../includes/philo.h"

static void	set_times(t_info *info)
{
	info->num_of_philosophers = philo_atoi(info->argv[1], info);
	info->time_to_die = philo_atoi(info->argv[2], info);
	info->time_to_eat = philo_atoi(info->argv[3], info);
	info->time_to_sleep = philo_atoi(info->argv[4], info);
}

int	main(int argc, char **argv)
{
	t_info	info;

	info.argc = argc;
	info.argv = argv;
	set_times(&info);
}