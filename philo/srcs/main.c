#include "../includes/philo.h"

static void	set_fork_status(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_of_philosophers)
	{
		info->fork_status[i] = true;
		i++;
	}
}

static void	set_etc(t_info *info)
{
	info->num_of_philosophers = philo_atoi(info->argv[1], info);
	info->time_to_die = philo_atoi(info->argv[2], info);
	info->time_to_eat = philo_atoi(info->argv[3], info);
	info->time_to_sleep = philo_atoi(info->argv[4], info);
	info->fork_status = malloc(sizeof(bool) * info->argc);
	if (info->fork_status == NULL)
		free_element(info);
	set_fork_status(info);
}

static void	init_structure(t_info *info)
{
	info->argc = 0;
	info->argv = NULL;
	info->num_of_philosophers = 0;
	info->time_to_die = 0;
	info->time_to_eat = 0;
	info->time_to_sleep = 0;
	info->array = NULL;
}

int	main(int argc, char **argv)
{
	t_info	info;

	init_structure(&info);
	info.argc = argc - 1;
	info.argv = argv;
	set_etc(&info);
	execute_mult_thread(&info);
}